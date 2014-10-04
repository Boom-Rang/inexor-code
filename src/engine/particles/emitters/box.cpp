#include "cube.h"
#include "engine/particles/particles.h"

/**
 * Singleton implementation of a box emitter.
 */
struct box_emitter : public particle_emitter_implementation
{

public:

	static box_emitter& instance()
	{
		static box_emitter _instance;
		return _instance;
	}
	virtual ~box_emitter() { }

	/**
	 * Emits particles from a single sphere (x,y,z).
	 */
	inline std::list<particle_instance*> emit(particle_emitter_instance *pe_inst, int elapsedtime)
	{
		particle_emitter_type* pe_type = pe_inst->type;
		pe_inst->millistoprocess += elapsedtime;
		int particlestoemit = pe_inst->millistoprocess / pe_type->rate;
		pe_inst->millistoprocess = pe_inst->millistoprocess % pe_type->rate;

		std::list<particle_instance*> emitted;
		for (int i = 0; i < pe_inst->batch_size; i++)
		{
			// get new particle, may increase the pool
			particle_instance *p_inst = ps.emit_particle();
			// set the origin emitter
			p_inst->pe_inst = pe_inst;
			// get the particle type, mass and density from the emitter type
			p_inst->type = pe_inst->p_type;
			// random position
			rx = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			ry = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			rz = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			p_inst->o.x = pe_inst->o.x + pe_inst->attributes["size_x"] * (rx - 0.5f);
			p_inst->o.y = pe_inst->o.y + pe_inst->attributes["size_y"] * (ry - 0.5f);
			p_inst->o.z = pe_inst->o.z + pe_inst->attributes["size_z"] * (rz - 0.5f);

			p_inst->vel = vec(pe_inst->vel);
			p_inst->roll = 0;

			p_inst->mass = pe_inst->mass;
			p_inst->density = pe_inst->density;
			// set the remaining iterations from the emitter type's lifetime
			p_inst->remaining = pe_inst->lifetime;
			// add particle instance to the alive pool
			ps.alive_pool.push_back(p_inst);
			ps.count_alive_pool++;
			emitted.push_back(p_inst);
		}
		return emitted;
	}

private:

	particle_instance* last;

	box_emitter() : particle_emitter_implementation("box_emitter")
	{
		ps.add_emitter_implementation(this);
		last = NULL;
	}
	box_emitter( const box_emitter& );
	box_emitter & operator = (const box_emitter &);

};

box_emitter& ps_emitter_box = box_emitter::instance();
