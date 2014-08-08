#include "cube.h"
#include "engine/particles/particles.h"

/**
 * Singleton implementation of a field emitter.
 */
struct field_emitter : public particle_emitter_implementation
{

public:

	static field_emitter& instance()
	{
		static field_emitter _instance;
		return _instance;
	}
	virtual ~field_emitter() { }

	/**
	 * Emits particles from a one, two or three dimensional grid which is specified
	 * by the grid size attributes: grid_size_x, grid_size_y, grid_size_z. The distance of the
	 * points in the grid is specified by the grid_dist attribute.
	 */
	void emit(particle_emitter_instance *pe_inst, int elapsedtime)
	{
		/** === TEST === **/
		float rx = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		float ry = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		float rz = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		pe_inst->o.x += (rx - 0.5f);
		pe_inst->o.y += (ry - 0.5f);
		pe_inst->o.z += (rz - 0.5f);
		/** === TEST === **/

		particle_emitter_type* pe_type = pe_inst->pe_type;
		pe_inst->millistoprocess += elapsedtime;
		int particlestoemit = pe_inst->millistoprocess / pe_type->rate;
		pe_inst->millistoprocess = pe_inst->millistoprocess % pe_type->rate;

		if (particlestoemit > 0)
		{
			float grid_dist = pe_inst->attributes["grid_dist"];
			int grid_size_x = int(pe_inst->attributes["grid_size_x"]);
			int grid_size_y = int(pe_inst->attributes["grid_size_y"]);
			int grid_size_z = int(pe_inst->attributes["grid_size_z"]);
			for (int x = 0; x < grid_size_x; x++)
			{
				float dx = x * grid_dist;
				for (int y = 0; y < grid_size_y; y++)
				{
					float dy = y * grid_dist;
					for (int z = 0; z < grid_size_z; z++)
					{
						float dz = z * grid_dist;
						loopi(particlestoemit)
						{
							// get new particle, may increase the pool
							particle_instance *p_inst = emit_particle();
							// set the origin emitter
							p_inst->pe_inst = pe_inst;
							// get the particle type, mass and density from the emitter type
							p_inst->p_type = pe_inst->p_type;
							p_inst->o.x = pe_inst->o.x + dx;
							p_inst->o.y = pe_inst->o.y + dy;
							p_inst->o.z = pe_inst->o.z + dz;
							p_inst->vel = pe_inst->vel;
							p_inst->mass = pe_inst->mass;
							p_inst->density = pe_inst->density;
							// set the elapsed and remaining iterations from the emitter type's lifetime
							p_inst->elapsed = 0;
							p_inst->remaining = pe_inst->lifetime;
							// add particle instance to the alive pool
							alive_pool.push_back(p_inst);
							// add particle instance to it's renderer
							p_inst->p_type->pr_inst->particles.push_back(p_inst);
						}
					}
				}
			}
		}
	}

private:

	field_emitter() : particle_emitter_implementation("field_emitter")
	{
		particle_emitter_implementations.push_back(this);
	}
	field_emitter( const field_emitter& );
	field_emitter & operator = (const field_emitter &);

};

field_emitter& ps_emitter_field = field_emitter::instance();
