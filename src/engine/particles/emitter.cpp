#include "cube.h"
#include "particles.h"

VARP(emitters, 0, 1, 1);

void particle_system::emit_particles(int elapsedtime)
{
	if (emitters)
	{
		int started = SDL_GetTicks();
		for(std::vector<particle_emitter_instance*>::iterator it = particle_emitter_instances.begin(); it != particle_emitter_instances.end(); ++it)
		{
			if ((*it)->enabled && (*it)->lifetime > 0)
			{
				// emit particles
				std::list<particle_instance*> particles = (*it)->pe_type->pe_impl->emit(*it, elapsedtime);
				// initialize emitted particles
				for(std::vector<particle_initializer_instance*>::iterator pi_it = (*it)->initializers.begin(); pi_it != (*it)->initializers.end(); ++pi_it)
				{
					(*pi_it)->pi_type->pi_impl->init(particles, elapsedtime);
				}
			}
		}
		timer_emitter = SDL_GetTicks() - started;
	}
	if (editmode)
	{
		for(std::vector<particle_emitter_instance*>::iterator it = particle_emitter_instances.begin(); it != particle_emitter_instances.end(); ++it)
		{
			// conoutf("%3.1f %3.1f", (*it)->o.x, (*it)->ent->o.x);
			(*it)->o = vec((*it)->ent->o);
		}
	}
}

/**
 * By emitting a particle we want to reuse dead particles in order to save
 * memory.
 */
particle_instance* particle_system::emit_particle()
{
	if (dead_pool.size() > 0)
	{
		// reanimate a dead particle
		particle_instance* p_inst = dead_pool.back();
		dead_pool.pop_back();
		count_dead_pool--;
		p_inst->elapsed = 0;
		return p_inst;
	} else {
		// dynamically create a new particle instance
		particle_instance *p_inst = new particle_instance;
		p_inst->elapsed = 0;
		return p_inst;
	}
}

particle_emitter_type* particle_system::add_particle_emitter_type(const std::string name, const std::string p_type, float mass, float density, int lifetime, int rate, const std::string impl)
{
	if (!particle_emitter_types_map.count(name))
	{
		particle_emitter_type* pe_type = new particle_emitter_type;
		pe_type->name = name;
		pe_type->mass = mass;
		pe_type->density = density;
		pe_type->lifetime = lifetime;
		pe_type->rate = rate;
		pe_type->p_type = particle_types_map[p_type];
		pe_type->pe_impl = particle_emitter_implementations_map[impl];
		particle_emitter_types.push_back(pe_type);
		particle_emitter_types_map[name] = pe_type;
		count_particle_emitter_types++;
		return pe_type;
	} else {
		conoutf("Particle modifier type %s already exists!", name.c_str());
		return particle_emitter_types_map[name];
	}
}

void particle_emitter_instance::add_modifier(particle_modifier_instance* pm_inst)
{
	modifiers.push_back(pm_inst);
}

void particle_emitter_instance::add_initializer(particle_initializer_instance* pi_inst)
{
	initializers.push_back(pi_inst);
}

particle_emitter_instance* particle_emitter_type::create_instance(const vec &o, const vec &vel)
{
	particle_emitter_instance* pe_inst = new particle_emitter_instance;
	pe_inst->pe_type = this;
	pe_inst->p_type = p_type;
	pe_inst->o = o;
	pe_inst->vel = vel;
	pe_inst->enabled = true;
	pe_inst->mass = mass;
	pe_inst->density = density;
	pe_inst->lifetime = lifetime;
	pe_inst->rate = rate;
	pe_inst->millistoprocess = 0;
	// initialize default modifiers by copy all modifiers
	pe_inst->modifiers = modifiers;
	// initialize default initializers by copy all initializers
	pe_inst->initializers = initializers;
	// initialize default attributes by copy the attributes map
	pe_inst->attributes.insert(attributes.begin(), attributes.end());

	// TODO!!!!
	// create entity and attach to the instance object
	// float yaw;
	// float pitch;
	// vectoyawpitch(*vel, &yaw, &pitch);
	int idx;
	pe_inst->ent = newentity(true, vec(o), EP_EMITTER, 0, 0, 0, 0, 0, idx);  // yeah i love the hard coded entity system, which would break every map if i would insert a new entity type on engine level. This is only a quick fix and have to replace by an integration into the new entity system
	addentity(idx);
	pe_inst->ent->spawned = true;

	ps.particle_emitter_instances.push_back(pe_inst);
	ps.count_particle_emitter_instances++;
	return pe_inst;
}

particle_emitter_instance* particle_system::create_particle_emitter_instance(std::string pe_type, const vec &o, const vec &vel)
{
	if (particle_emitter_types_map.count(pe_type))
	{
		return particle_emitter_types_map[pe_type]->create_instance(o, vel);
	} else {
		conoutf("Particle emitter type %s not found!", pe_type.c_str());
		return 0;
	}
}

void particle_system::remove_particle_emitter_type(std::string name)
{
	if (particle_emitter_types_map.count(name))
	{
		particle_emitter_types_map.erase(name);
		// TODO: iterate particle_emitter_types and check by name
		count_particle_emitter_types--;
	} else {
		conoutf("Particle emitter type %s not found!", name.c_str());
	}
}

void particle_system::remove_all_particle_emitter_types()
{
	particle_emitter_types_map.clear();
	particle_emitter_types.clear();
	count_particle_emitter_types = 0;
}

void create_particle_emitter_instance(std::string pe_type, const vec &o, const vec &vel) {
	ps.create_particle_emitter_instance(pe_type, o, vel);
}

// ICOMMAND(add_particle_emitter_type, "ssiiiis", (char *name, char *particle_type, int *mass, int *density, int *lifetime, int *rate, char *impl), add_particle_emitter_type(name, particle_type, *mass, *density, *lifetime, *rate, impl));
// ICOMMAND(create_particle_emitter_instance, "siiiiii", (char *type, int *ox, int *oy, int *oz, int *vx, int *vy, int *vz), create_particle_emitter_instance(type, vec(*ox, *oy, *oz), vec(*vx, *vy, *vz)));

/*
ICOMMAND(particle_emitter_types_num, "", (), intret(particle_emitter_types.size()));
ICOMMAND(assign_modifier_to_emitter, "ss", (char *modifier_name, char *emitter_name), intret(assign_modifier_to_emitter(modifier_name, emitter_name)));
ICOMMAND(ls_particle_emitter_types, "", (),
{
	for(std::vector<particle_emitter_type>::iterator it = particle_emitter_types.begin(); it != particle_emitter_types.end(); ++it) {
		conoutf("%s | %i | %i", it->name.c_str(), it->particle_type, particle_emitter_types[i].lifetime);
	}
});
*/
