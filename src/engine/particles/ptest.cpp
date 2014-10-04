#include "cube.h"
#include "particles/particles.h"

struct ptest
{

	ptest()
    {
    }

	void setup(int setup)
	{
		switch (setup) {
/*
			case 1: setup1(); break;
			case 2: setup2(); break;
			case 3: setup3(); break;
			case 4: setup4(); break;
			case 5: setup5(); break;
			case 6: setup6(); break;
			case 7: setup7(); break;
			case 8: setup8(); break;
			case 9: setup9(); break;
			case 10: setup10(); break;
*/
			case 11: setup11(); break;
			case 12: setup12(); break;
			case 13: setup13(); break;
			case 14: setup14(); break;
			case 15: setup15(); break;
			case 16: setup16(); break;
			case 17: position_trace_modifier_test(); break;
			case 18: vector_field_test(); break;
		}
	}

/*
	void setup1()
    {
		float mass = 1.0f;
		float density = 1.0f;
		int lifetime = 30000;
		int rate = 1;

		particle_renderer_type* pr_type_ball = ps.add_particle_renderer_type("ball_renderer", "packages/particles/ball1.png", "shader", vec4(255.0f, 255.0f, 0.0f, 0.3f), "billboard_renderer");
		particle_renderer_instance* pr_inst_fire = pr_type_ball->create_instance("fire");
		particle_type* p_type_fire = ps.add_particle_type("fire", "fire");
		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();
		particle_modifier_type* pm_type_randomv = ps.add_particle_modifier_type("randomv", "randomv");
		particle_modifier_instance* pm_inst_randomv = pm_type_randomv->create_instance();
		particle_emitter_type* pe_point_fire_type = ps.add_particle_emitter_type("fire_point_emitter", "fire", mass, density, lifetime, rate, "point_emitter");
		particle_emitter_instance* pe_inst_point_1 = pe_point_fire_type->create_instance(vec(512.0f, 512.0f, 514.0f), vec(-40.0f, 0.0f, 0.0f));
		pe_inst_point_1->add_modifier(pm_inst_velocity_transformation);
		pe_inst_point_1->add_modifier(pm_inst_randomv);
    }

	void setup2()
    {
		float mass = 1.0f;
		float density = 1.0f;
		// int lifetime1 = 3500;
		// int rate1 = 1;
		int lifetime2 = 10000;
		int rate2 = 10;

		int lifetime3 = 500;
		int rate3 = 20;

		float density4 = 5.0f;
		int lifetime4 = 500;
		int rate4 = 10;

		particle_renderer_type* pr_type_cube = ps.add_particle_renderer_type("cube_renderer", "packages/particles/flare.jpg", "shader", vec4(255.0f, 255.0f, 255.0f, 0.9f), "cube_renderer");

		particle_renderer_type* pr_type_ball = ps.add_particle_renderer_type("ball_renderer", "packages/particles/ball1.png", "shader", vec4(255.0f, 255.0f, 255.0f, 0.3f), "billboard_renderer");
		pr_type_ball->attributes["size"] = 20.0f;

		particle_renderer_type* pr_type_smoke = ps.add_particle_renderer_type("smoke_renderer", "<grey>packages/particles/smoke.png", "shader", vec4(255.0f, 220.0f, 220.0f, 0.1f), "billboard_renderer");
		pr_type_smoke->attributes["size"] = 75.0f;

		particle_renderer_instance* pr_inst_fire = pr_type_ball->create_instance("fire");
		pr_inst_fire->color.r = 200.0f;
		pr_inst_fire->color.b = 0.0f;

		particle_renderer_instance* pr_inst_poison = pr_type_ball->create_instance("poison");
		pr_inst_poison->color.r = 0.0f;
		pr_inst_poison->color.b = 200.0f;

		particle_renderer_instance* pr_inst_smoke = pr_type_smoke->create_instance("smoke");

		particle_renderer_instance* pr_inst_cube = pr_type_cube->create_instance("cube");
		pr_inst_cube->color.g = 100.0f;

		particle_type* p_type_fire = ps.add_particle_type("fire", "fire");
		particle_type* p_type_poison = ps.add_particle_type("poison", "poison");
		particle_type* p_type_smoke = ps.add_particle_type("smoke", "smoke");
		particle_type* p_type_cube = ps.add_particle_type("cube", "cube");

		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();

		particle_modifier_type* pm_type_randomv = ps.add_particle_modifier_type("randomv", "randomv");
		particle_modifier_instance* pm_inst_randomv = pm_type_randomv->create_instance();

		particle_modifier_type* pm_type_randomw = ps.add_particle_modifier_type("randomw", "randomw");
		particle_modifier_instance* pm_inst_randomw = pm_type_randomw->create_instance();

		particle_modifier_type* pm_type_gravity_point = ps.add_particle_modifier_type("gravity_point", "gravity_point");
		pm_type_gravity_point->attributes["mass"] = 1000.0f;
		pm_type_gravity_point->attributes["gravity"] = 0.8f;
		particle_modifier_instance* pm_inst_gravity_point_1 = pm_type_gravity_point->create_instance(vec(768.0f, 768.0f, 532.0f));
		particle_modifier_instance* pm_inst_gravity_point_2 = pm_type_gravity_point->create_instance(vec(256.0f, 256.0f, 532.0f));
		particle_modifier_instance* pm_inst_gravity_point_3 = pm_type_gravity_point->create_instance(vec(768.0f, 256.0f, 532.0f));
		particle_modifier_instance* pm_inst_gravity_point_4 = pm_type_gravity_point->create_instance(vec(256.0f, 768.0f, 532.0f));

		particle_modifier_type* pm_type_black_hole = ps.add_particle_modifier_type("black_hole", "black_hole");
		pm_type_black_hole->attributes["mass"] = 5000.0f;
		pm_type_black_hole->attributes["gravity"] = 1.8f;

		particle_modifier_instance* pm_inst_black_hole = pm_type_black_hole->create_instance(vec(768.0f, 768.0f, 532.0f));

		particle_emitter_type* pe_point_fire_type = ps.add_particle_emitter_type("fire_point_emitter", "fire", mass, density, lifetime2, rate2, "point_emitter");
		particle_emitter_instance* pe_inst_point_1 = pe_point_fire_type->create_instance(vec(512.0f, 512.0f, 514.0f), vec(-40.0f, 0.0f, 0.0f));
		particle_emitter_instance* pe_inst_point_2 = pe_point_fire_type->create_instance(vec(512.0f, 512.0f, 514.0f), vec(0.0f, -40.0f, 0.0f));

		particle_emitter_type* pe_point_poison_type = ps.add_particle_emitter_type("poison_point_emitter", "poison", mass, density, lifetime2, rate2, "point_emitter");
		particle_emitter_instance* pe_inst_point_3 = pe_point_poison_type->create_instance(vec(512.0f, 512.0f, 514.0f), vec(40.0f, 0.0f, 0.0f));
		particle_emitter_instance* pe_inst_point_4 = pe_point_poison_type->create_instance(vec(512.0f, 512.0f, 514.0f), vec(0.0f, 40.0f, 0.0f));

		particle_emitter_type* pe_type_smoke_field = ps.add_particle_emitter_type("smoke_field_emitter", "smoke", mass, density, lifetime3, rate3, "field_emitter");
		pe_type_smoke_field->attributes["grid_size_x"] = 3.0f;
		pe_type_smoke_field->attributes["grid_size_y"] = 3.0f;
		pe_type_smoke_field->attributes["grid_size_z"] = 3.0f;
		pe_type_smoke_field->attributes["grid_dist"] = 20.0f;
		particle_emitter_instance* pe_inst_smoke_field = pe_type_smoke_field->create_instance(vec(768.0f, 768.0f, 514.0f), vec(0.0f, 0.0f, 10.0f));

		particle_emitter_type* pe_type_cube_field = ps.add_particle_emitter_type("cube_field_emitter", "cube", mass, density4, lifetime4, rate4, "field_emitter");
		pe_type_cube_field->attributes["grid_size_x"] = 6.0f;
		pe_type_cube_field->attributes["grid_size_y"] = 6.0f;
		pe_type_cube_field->attributes["grid_size_z"] = 1.0f;
		pe_type_cube_field->attributes["grid_dist"] = 20.0f;
		particle_emitter_instance* pe_inst_cube_field = pe_type_cube_field->create_instance(vec(256.0f, 256.0f, 514.0f), vec(0.0f, 0.0f, 70.0f));

		pe_inst_point_1->add_modifier(pm_inst_velocity_transformation);
		pe_inst_point_2->add_modifier(pm_inst_velocity_transformation);
		pe_inst_point_3->add_modifier(pm_inst_velocity_transformation);
		pe_inst_point_4->add_modifier(pm_inst_velocity_transformation);
		pe_inst_smoke_field->add_modifier(pm_inst_velocity_transformation);
		pe_inst_cube_field->add_modifier(pm_inst_velocity_transformation);

		pe_inst_point_1->add_modifier(pm_inst_randomv);
		pe_inst_point_2->add_modifier(pm_inst_randomv);
		pe_inst_point_3->add_modifier(pm_inst_randomv);
		pe_inst_point_4->add_modifier(pm_inst_randomv);
		pe_inst_smoke_field->add_modifier(pm_inst_randomw);
		pe_inst_cube_field->add_modifier(pm_inst_randomv);

		pe_inst_point_1->add_modifier(pm_inst_gravity_point_1);
		pe_inst_point_2->add_modifier(pm_inst_gravity_point_2);
		pe_inst_point_3->add_modifier(pm_inst_gravity_point_3);
		pe_inst_point_4->add_modifier(pm_inst_gravity_point_4);

		pe_inst_smoke_field->add_modifier(pm_inst_black_hole);

		// pe_inst_cube_field->add_modifier(pm_inst_black_hole);
    }

	void setup3()
    {
		float mass = 1.0f;
		float density = 1.0f;
		int lifetime = 1000;
		int rate = 1;

		particle_renderer_type* pr_type_ball = ps.add_particle_renderer_type("ball_renderer", "packages/particles/ball1.png", "shader", vec4(255.0f, 255.0f, 0.0f, 0.3f), "billboard_renderer");
		pr_type_ball->attributes["size"] = 100.0f;
		particle_renderer_instance* pr_inst_fire = pr_type_ball->create_instance("fire");
		particle_type* p_type_fire = ps.add_particle_type("fire", "fire");
		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();
		particle_modifier_type* pm_type_randomv = ps.add_particle_modifier_type("randomv", "randomv");
		particle_modifier_instance* pm_inst_randomv = pm_type_randomv->create_instance();
		particle_modifier_type* pm_type_velocity_damper = ps.add_particle_modifier_type("velocity_damper", "velocity_damper");
		particle_modifier_instance* pm_inst_velocity_damper = pm_type_velocity_damper->create_instance(vec(0.01f, 0.02f, 0.1f));
		// pm_inst_velocity_damper->attributes["damper"] = 0.999f;
		particle_emitter_type* pe_sphere_fire_type = ps.add_particle_emitter_type("sphere_point_emitter", "fire", mass, density, lifetime, rate, "sphere_emitter");
		particle_emitter_instance* pe_inst_sphere_1 = pe_sphere_fire_type->create_instance(vec(512.0f, 512.0f, 514.0f), vec(1.0f, 5.0f, 200.0f));
		pe_inst_sphere_1->add_modifier(pm_inst_velocity_transformation);
		pe_inst_sphere_1->add_modifier(pm_inst_velocity_damper);
		pe_inst_sphere_1->add_modifier(pm_inst_randomv);
    }

	void setup4()
    {
		float mass = 1.0f;
		float density = 5.0f;
		int lifetime = 20000;
		int rate = 900;

		particle_renderer_type* pr_type_spring = ps.add_particle_renderer_type("spring_renderer_4", "packages/particles/flare.jpg", "shader", vec4(255.0f, 255.0f, 255.0f, 0.3f), "spring_renderer");
		particle_renderer_instance* pr_inst_spring = pr_type_spring->create_instance("spring4");
		particle_type* p_type_cube = ps.add_particle_type("spring4", "spring4");

		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();

		particle_modifier_type* pm_type_mass_spring_transformation = ps.add_particle_modifier_type("mass_spring_transformation", "mass_spring_transformation");
		particle_modifier_instance* pm_inst_mass_spring_transformation = pm_type_mass_spring_transformation->create_instance();

		particle_modifier_type* pm_type_gravity_point = ps.add_particle_modifier_type("gravity_point", "gravity_point");
		pm_type_gravity_point->attributes["mass"] = 1000.0f;
		pm_type_gravity_point->attributes["gravity"] = 5.0f;
		particle_modifier_instance* pm_inst_gravity_point_1 = pm_type_gravity_point->create_instance(vec(768.0f, 768.0f, 832.0f));

		particle_modifier_type* pm_type_gravity_point_2 = ps.add_particle_modifier_type("gravity_point_2", "gravity_point");
		pm_type_gravity_point_2->attributes["mass"] = 2000.0f;
		pm_type_gravity_point_2->attributes["gravity"] = 10.0f;
		particle_modifier_instance* pm_inst_gravity_point_2 = pm_type_gravity_point_2->create_instance(vec(512.0f, 512.0f, 1000.0f));

		particle_modifier_type* pm_type_bb_culling = ps.add_particle_modifier_type("bb_culling", "bb_culling");
		particle_modifier_instance* pm_inst_bb_culling = pm_type_bb_culling->create_instance(vec(1024.0f, 1024.0f, 1024.0f));

		particle_emitter_type* pe_type_fire_field = ps.add_particle_emitter_type("fire_field_emitter", "spring4", mass, density, lifetime, rate, "field_emitter");
		pe_type_fire_field->attributes["grid_size_x"] = 5.0f;
		pe_type_fire_field->attributes["grid_size_y"] = 5.0f;
		pe_type_fire_field->attributes["grid_size_z"] = 1.0f;
		pe_type_fire_field->attributes["grid_dist"] = 50.0f;
		particle_emitter_instance* pe_inst_fire_field = pe_type_fire_field->create_instance(vec(768.0f, 768.0f, 514.0f), vec(0.0f, 0.0f, 50.0f));
		pe_inst_fire_field->add_modifier(pm_inst_velocity_transformation);
		pe_inst_fire_field->add_modifier(pm_inst_mass_spring_transformation);
		pe_inst_fire_field->add_modifier(pm_inst_gravity_point_2);
		pe_inst_fire_field->add_modifier(pm_inst_bb_culling);
    }

	void setup5()
    {
		float mass = 1.0f;
		float density = 5.0f;
		int lifetime = 20000;
		int rate = 900;

		particle_renderer_type* pr_type_primary = ps.add_particle_renderer_type("primary_renderer", "packages/particles/ball1.png", "shader", vec4(255.0f, 128.0f, 0.0f, 0.7f), "billboard_renderer");
		pr_type_primary->attributes["size"] = 30.0f;
		particle_renderer_instance* pr_inst_primary = pr_type_primary->create_instance("primary");
		particle_type* p_type_primary = ps.add_particle_type("primary", "primary");

		particle_renderer_type* pr_type_satellite = ps.add_particle_renderer_type("satellite_renderer", "packages/particles/ball1.png", "shader", vec4(255.0f, 0.0f, 0.0f, 0.3f), "billboard_renderer");
		pr_type_satellite->attributes["size"] = 10.0f;
		particle_renderer_instance* pr_inst_satellite = pr_type_satellite->create_instance("satellite");
		particle_type* p_type_satellite = ps.add_particle_type("satellite", "satellite");

		particle_renderer_type* pr_type_spring = ps.add_particle_renderer_type("spring_renderer_5", "packages/particles/flare.jpg", "shader", vec4(255.0f, 255.0f, 255.0f, 0.3f), "spring_renderer");
		particle_renderer_instance* pr_inst_spring = pr_type_spring->create_instance("spring5");
		particle_type* p_type_cube = ps.add_particle_type("spring5", "spring5");

		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();

		particle_modifier_type* pm_type_mass_spring_transformation = ps.add_particle_modifier_type("mass_spring_transformation", "mass_spring_transformation");
		particle_modifier_instance* pm_inst_mass_spring_transformation = pm_type_mass_spring_transformation->create_instance();

		particle_modifier_type* pm_type_gravity_point_5 = ps.add_particle_modifier_type("gravity_point_5", "gravity_point");
		pm_type_gravity_point_5->attributes["mass"] = 5000.0f;
		pm_type_gravity_point_5->attributes["gravity"] = 10.0f;
		particle_modifier_instance* pm_inst_gravity_point = pm_type_gravity_point_5->create_instance(vec(512.0f, 512.0f, 1000.0f));

		particle_modifier_type* pm_type_global_gravity_5 = ps.add_particle_modifier_type("global_gravity_5", "global_gravity");
		pm_type_global_gravity_5->attributes["mass"] = 250.0f;
		pm_type_global_gravity_5->attributes["gravity"] = 1.0f;
		particle_modifier_instance* pm_inst_global_gravity_5 = pm_type_global_gravity_5->create_instance(vec(0.0f, 0.0f, 400.0f));

		particle_modifier_type* pm_type_geometry_collide_5 = ps.add_particle_modifier_type("geometry_collide_5", "geometry_collide");
		particle_modifier_instance* pm_inst_geometry_collide_5 = pm_type_geometry_collide_5->create_instance();
		pm_inst_geometry_collide_5->attributes["elasticity"] = 0.8f;

		particle_emitter_type* pe_type_ball_satellite = ps.add_particle_emitter_type("ball_satellite_emitter", "satellite", mass, density, lifetime, rate, "satellite_emitter");
		pe_type_ball_satellite->attributes["grid_size_x"] = 5.0f;
		pe_type_ball_satellite->attributes["grid_size_y"] = 5.0f;
		pe_type_ball_satellite->attributes["grid_size_z"] = 1.0f;
		pe_type_ball_satellite->attributes["grid_dist"] = 50.0f;
		particle_emitter_instance* pe_inst_ball_satellite = pe_type_ball_satellite->create_instance(vec(768.0f, 768.0f, 514.0f), vec(0.0f, 0.0f, 150.0f));
		pe_inst_ball_satellite->add_modifier(pm_inst_velocity_transformation);
		pe_inst_ball_satellite->add_modifier(pm_inst_mass_spring_transformation);
		pe_inst_ball_satellite->add_modifier(pm_inst_gravity_point);
		pe_inst_ball_satellite->add_modifier(pm_inst_global_gravity_5);
		pe_inst_ball_satellite->add_modifier(pm_inst_geometry_collide_5);

		// noop emitter, just to enable
		particle_emitter_type* pe_type_noop_spring = ps.add_particle_emitter_type("noop_emitter", "spring_renderer_5", mass, density, 0, 0, "noop_emitter");
		particle_emitter_instance* pe_inst_noop_spring = pe_type_noop_spring->create_instance(vec(256.0f, 256.0f, 514.0f), vec(0.0f, 0.0f, 0.0f));
    }

	void setup6()
    {
		float mass = 1.0f;
		float density = 250.0f;
		int lifetime = 10000;
		int rate = 75;

		particle_renderer_type* pr_type_spring = ps.add_particle_renderer_type("spring_renderer_6", "packages/particles/flare.jpg", "shader", vec4(255.0f, 255.0f, 255.0f, 0.3f), "spring_renderer");
		particle_renderer_instance* pr_inst_spring = pr_type_spring->create_instance("spring6");
		particle_type* p_type_spring = ps.add_particle_type("spring6", "spring6");

		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();

		particle_modifier_type* pm_type_mass_spring_transformation = ps.add_particle_modifier_type("mass_spring_transformation", "mass_spring_transformation");
		particle_modifier_instance* pm_inst_mass_spring_transformation = pm_type_mass_spring_transformation->create_instance();

		particle_modifier_type* pm_type_geometry_collide_6 = ps.add_particle_modifier_type("geometry_collide_6", "geometry_collide");
		particle_modifier_instance* pm_inst_geometry_collide_6 = pm_type_geometry_collide_6->create_instance();
		pm_inst_geometry_collide_6->attributes["elasticity"] = 0.8f;

		particle_emitter_type* pe_type_cloth_emitter = ps.add_particle_emitter_type("spring_cloth_emitter", "spring6", mass, density, lifetime, rate, "cloth_emitter");
		particle_emitter_instance* pe_inst_cloth_emitter = pe_type_cloth_emitter->create_instance(vec(0.0f, 100.0f, 1750.0f), vec(0.0f, 0.0f, -100.0f));
		pe_inst_cloth_emitter->add_modifier(pm_inst_velocity_transformation);
		pe_inst_cloth_emitter->add_modifier(pm_inst_mass_spring_transformation);
		pe_inst_cloth_emitter->add_modifier(pm_inst_geometry_collide_6);
    }

	void setup7()
    {
		float mass = 5.0f;
		float density = 250.0f;
		int lifetime = 5000;
		int rate = 10;

		particle_renderer_type* pr_type_fire_ball = ps.add_particle_renderer_type("fire_ball_7", "media/particle/shockwave01.png", "shader", vec4(255.0f, 255.0f, 0.0f, 0.1f), "billboard_renderer");
		pr_type_fire_ball->attributes["size"] = 45.0f;
		particle_renderer_instance* pr_inst_fire_ball = pr_type_fire_ball->create_instance("fire_ball_7");
		particle_type* p_type_fire_ball = ps.add_particle_type("fire_ball_7", "fire_ball_7");

		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();

		particle_modifier_type* pm_type_simple_gravity = ps.add_particle_modifier_type("global_gravity_10", "simple_gravity");
		particle_modifier_instance* pm_inst_simple_gravity = pm_type_simple_gravity->create_instance(vec(0.0f, 0.0f, 0.0f));

		particle_modifier_type* pm_type_geometry_collide_7 = ps.add_particle_modifier_type("geometry_collide_7", "geometry_collide");
		particle_modifier_instance* pm_inst_geometry_collide_7 = pm_type_geometry_collide_7->create_instance();
		pm_inst_geometry_collide_7->attributes["elasticity"] = 0.8f;

		particle_modifier_type* pm_type_randomv_7 = ps.add_particle_modifier_type("randomv_7", "randomv");
		particle_modifier_instance* pm_inst_randomv_7 = pm_type_randomv_7->create_instance();

		particle_emitter_type* pe_type_fire_ball_7 = ps.add_particle_emitter_type("fire_ball_emitter_7", "fire_ball_7", mass, density, lifetime, rate, "point_emitter");
		particle_emitter_instance* pe_inst_fire_ball_7 = pe_type_fire_ball_7->create_instance(vec(512.0f, 512.0f, 400.0f), vec(1.0f, 1.0f, 3.0f));
		pe_inst_fire_ball_7->add_modifier(pm_inst_velocity_transformation);
		pe_inst_fire_ball_7->add_modifier(pm_inst_simple_gravity);
		pe_inst_fire_ball_7->add_modifier(pm_inst_geometry_collide_7);
		pe_inst_fire_ball_7->add_modifier(pm_inst_randomv_7);
    }

	void setup8()
    {
		float mass = 1.0f;
		float density = 1.0f;
		int lifetime2 = 10000;
		int rate2 = 10;
		particle_renderer_type* pr_type_cube = ps.add_particle_renderer_type("cube_renderer", "packages/particles/flare.jpg", "shader", vec4(255.0f, 255.0f, 255.0f, 0.9f), "cube_renderer");
		particle_renderer_instance* pr_inst_cube = pr_type_cube->create_instance("cube");
		pr_inst_cube->color.g = 100.0f;
		particle_type* p_type_cube = ps.add_particle_type("cube", "cube");
		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();
		particle_modifier_type* pm_type_randomv = ps.add_particle_modifier_type("randomv", "randomv");
		particle_modifier_instance* pm_inst_randomv = pm_type_randomv->create_instance();
		particle_modifier_type* pm_type_geometry_collide_7 = ps.add_particle_modifier_type("geometry_collide_7", "geometry_collide");
		particle_modifier_instance* pm_inst_geometry_collide_7 = pm_type_geometry_collide_7->create_instance();
		pm_inst_geometry_collide_7->attributes["elasticity"] = 0.8f;
		particle_emitter_type* pe_point_poison_type = ps.add_particle_emitter_type("cube_field_emitter", "cube", mass, density, lifetime2, rate2, "point_emitter");
		particle_emitter_instance* pe_inst_point_3 = pe_point_poison_type->create_instance(vec(512.0f, 512.0f, 514.0f), vec(40.0f, 0.0f, 0.0f));
		pe_inst_point_3->add_modifier(pm_inst_velocity_transformation);
		pe_inst_point_3->add_modifier(pm_inst_randomv);
		pe_inst_point_3->add_modifier(pm_inst_geometry_collide_7);
    }

	void setup9()
    {
		float mass = 1.0f;
		float density = 1.0f;
		int lifetime = 30000;
		int rate = 10;

		particle_renderer_type* pr_type_snow = ps.add_particle_renderer_type("snow_renderer_9", "packages/particles/smoke.png", "shader", vec4(255.0f, 255.0f, 255.0f, 0.3f), "billboard_renderer");
		pr_type_snow->attributes["size"] = 30.0f;
		particle_renderer_instance* pr_inst_snow = pr_type_snow->create_instance("snow_9");
		particle_type* p_type_snow = ps.add_particle_type("snow_9", "snow_9");
		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();
		particle_modifier_type* pm_type_randomv = ps.add_particle_modifier_type("randomv_9", "randomv");
		particle_modifier_instance* pm_inst_randomv = pm_type_randomv->create_instance();
		particle_modifier_type* pm_type_velocity_damper = ps.add_particle_modifier_type("velocity_damper_9", "velocity_damper");
		particle_modifier_instance* pm_inst_velocity_damper = pm_type_velocity_damper->create_instance(vec(0.01f, 0.02f, 0.1f));
		particle_modifier_type* pm_type_wind = ps.add_particle_modifier_type("wind_9", "wind");
		particle_modifier_instance* pm_inst_wind = pm_type_wind->create_instance();
		pm_inst_wind->vel = vec(0.8f, 0.4f, 0.0f);
		particle_modifier_type* pm_type_geometry_collide = ps.add_particle_modifier_type("geometry_collide_9", "geometry_collide");
		particle_modifier_instance* pm_inst_geometry_collide = pm_type_geometry_collide->create_instance();
		pm_inst_geometry_collide->attributes["elasticity"] = 0.8f;
		particle_modifier_type* pm_type_gravity_point = ps.add_particle_modifier_type("gravity_point_9", "gravity_point");
		pm_type_gravity_point->attributes["mass"] = 5000.0f;
		pm_type_gravity_point->attributes["gravity"] = -30.0f;
		particle_modifier_instance* pm_inst_gravity_point = pm_type_gravity_point->create_instance(vec(1024.0f, 1024.0f, 550.0f));

		particle_emitter_type* pe_box_snow_type = ps.add_particle_emitter_type("box_emitter_9", "snow_9", mass, density, lifetime, rate, "box_emitter");
		pe_box_snow_type->density = 600.0f;
		particle_emitter_instance* pe_inst_box_snow = pe_box_snow_type->create_instance(vec(1024.0f, 1024.0f, 800.0f), vec(0.0f, 0.0f, -25.0f));
		pe_inst_box_snow->add_modifier(pm_inst_velocity_transformation);
		pe_inst_box_snow->add_modifier(pm_inst_velocity_damper);
		pe_inst_box_snow->add_modifier(pm_inst_wind);
		pe_inst_box_snow->add_modifier(pm_inst_geometry_collide);
		pe_inst_box_snow->add_modifier(pm_inst_gravity_point);
    }

	void setup10()
    {
		float mass = 1.0f;
		float density = 1.0f;
		int lifetime = 10000;
		int rate = 100;

		float mass_fog = 0.5f;
		float density_fog = 1.0f;
		int lifetime_fog = 10000;
		int rate_fog = 5;
		float size_fog = 15.0f;

		particle_renderer_type* pr_type_grendade = ps.add_particle_renderer_type("grenade_renderer", "projectiles/grenade", "shader", vec4(0.0f, 0.0f, 0.0f, 0.0f), "model_renderer");
		particle_renderer_instance* pr_inst_snow = pr_type_grendade->create_instance("grendade_10");
		particle_type* p_type_grendade = ps.add_particle_type("grendade_10", "grendade_10");

		particle_renderer_type* pr_type_smoke = ps.add_particle_renderer_type("smoke_renderer", "<grey>packages/particles/smoke.png", "shader", vec4(220.0f, 220.0f, 128.0f, 0.2f), "billboard_renderer");
		pr_type_smoke->attributes["size"] = size_fog;
		particle_renderer_instance* pr_inst_smoke = pr_type_smoke->create_instance("smoke_10");
		particle_type* p_type_smoke = ps.add_particle_type("smoke_10", "smoke_10");


		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();
		// particle_modifier_type* pm_type_velocity_damper = ps.add_particle_modifier_type("velocity_damper_10", "velocity_damper");
		// particle_modifier_instance* pm_inst_velocity_damper = pm_type_velocity_damper->create_instance(vec(0.01f, 0.02f, 0.1f));
		particle_modifier_type* pm_type_wind = ps.add_particle_modifier_type("wind_10", "wind");
		particle_modifier_instance* pm_inst_wind = pm_type_wind->create_instance();
		pm_inst_wind->vel = vec(30.0f, 40.0f, 0.0f);
		particle_modifier_type* pm_type_simple_gravity = ps.add_particle_modifier_type("global_gravity_10", "simple_gravity");
		particle_modifier_instance* pm_inst_simple_gravity = pm_type_simple_gravity->create_instance(vec(0.0f, 0.0f, 0.0f));

		particle_modifier_type* pm_type_geometry_collide = ps.add_particle_modifier_type("geometry_collide_10", "geometry_collide");
		particle_modifier_instance* pm_inst_geometry_collide = pm_type_geometry_collide->create_instance();
		pm_inst_geometry_collide->attributes["elasticity"] = 0.75f;

		particle_modifier_type* pm_type_geometry_culling = ps.add_particle_modifier_type("geometry_culling_10", "geometry_culling");
		particle_modifier_instance* pm_inst_geometry_culling = pm_type_geometry_culling->create_instance();

		particle_emitter_type* pe_box_grenade_type = ps.add_particle_emitter_type("box_grenade_emitter_10", "grendade_10", mass, density, lifetime, rate, "box_emitter");
		pe_box_grenade_type->density = 600.0f;
		particle_emitter_instance* pe_inst_grenade_snow = pe_box_grenade_type->create_instance(vec(1024.0f, 1024.0f, 520.0f), vec(0.0f, 0.0f, 0.0f));
		pe_inst_grenade_snow->add_modifier(pm_inst_velocity_transformation);
		pe_inst_grenade_snow->add_modifier(pm_inst_wind);
		pe_inst_grenade_snow->add_modifier(pm_inst_simple_gravity);
		pe_inst_grenade_snow->add_modifier(pm_inst_geometry_collide);

		particle_emitter_type* pe_box_smoke_type = ps.add_particle_emitter_type("box_fog_emitter_10", "smoke_10", mass_fog, density_fog, lifetime_fog, rate_fog, "box_emitter");
		pe_box_smoke_type->density = 600.0f;
		particle_emitter_instance* pe_inst_box_fog = pe_box_smoke_type->create_instance(vec(1024.0f, 1024.0f, 520.0f), vec(0.0f, 0.0f, -20.0f));
		pe_inst_box_fog->add_modifier(pm_inst_velocity_transformation);
		pe_inst_box_fog->add_modifier(pm_inst_wind);
		pe_inst_box_fog->add_modifier(pm_inst_simple_gravity);
		pe_inst_box_fog->add_modifier(pm_inst_geometry_culling);
		// pe_inst_box_fog->add_modifier(pm_inst_geometry_collide);

    }

*/
	void setup11()
    {
		float mass = 5.0f;
		float density = 1.0f;
		int lifetime = 20000;
		int rate = 50;

		particle_renderer_type* pr_type_grenade = ps.add_particle_renderer_type("grenade_renderer", "projectiles/grenade", "shader", vec4(0.0f, 0.0f, 0.0f, 0.0f), "model_renderer");
		particle_renderer_instance* pr_inst_grenade = pr_type_grenade->create_instance("grendade_11");
		pr_inst_grenade->offset = vec(0.0f, 0.0f, 2.0f);
		particle_type* p_type_grendade = ps.add_particle_type("grendade_11", "grendade_11");

		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();

		particle_modifier_type* pm_type_wind = ps.add_particle_modifier_type("wind_11", "wind");
		particle_modifier_instance* pm_inst_wind = pm_type_wind->create_instance();
		pm_inst_wind->vel = vec(30.0f, 40.0f, 0.0f);

		particle_modifier_type* pm_type_simple_gravity = ps.add_particle_modifier_type("global_gravity_11", "simple_gravity");
		particle_modifier_instance* pm_inst_simple_gravity = pm_type_simple_gravity->create_instance(vec(0.0f, 0.0f, 0.0f));

		particle_modifier_type* pm_type_geometry_collide = ps.add_particle_modifier_type("geometry_collide_11", "geometry_collide");
		particle_modifier_instance* pm_inst_geometry_collide = pm_type_geometry_collide->create_instance();
		pm_inst_geometry_collide->attributes["elasticity"] = 0.75f;

		particle_modifier_type* pm_type_rolling = ps.add_particle_modifier_type("rolling_11", "rolling");
		particle_modifier_instance* pm_inst_rolling = pm_type_rolling->create_instance();

		particle_emitter_type* pe_type_box_grenade = ps.add_particle_emitter_type("box_grenade_emitter_11", "grendade_11", mass, density, lifetime, rate, "box_emitter");
		pe_type_box_grenade->density = 600.0f;

		particle_emitter_instance* pe_inst_box_grenade = pe_type_box_grenade->create_instance(vec(100.0f, 100.0f, 520.0f), vec(0.0f, 0.0f, 0.0f));
		pe_inst_box_grenade->add_modifier(pm_inst_velocity_transformation);
		pe_inst_box_grenade->add_modifier(pm_inst_wind);
		pe_inst_box_grenade->add_modifier(pm_inst_simple_gravity);
		pe_inst_box_grenade->add_modifier(pm_inst_geometry_collide);
		pe_inst_box_grenade->add_modifier(pm_inst_rolling);
    }

	void setup12()
    {
		float mass = 5.0f;
		float density = 1.0f;
		int lifetime = 20000;
		int rate = 10;

		particle_renderer_type* pr_type_grenade = ps.add_particle_renderer_type("grenade_renderer", "projectiles/rocket", "shader", vec4(0.0f, 0.0f, 0.0f, 0.0f), "model_renderer");
		particle_renderer_instance* pr_inst_grenade = pr_type_grenade->create_instance("grendade_12");
		pr_inst_grenade->offset = vec(0.0f, 0.0f, 2.0f);
		particle_type* p_type_grendade = ps.add_particle_type("grendade_12", pr_inst_grenade);

		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();

		particle_modifier_type* pm_type_geometry_collide = ps.add_particle_modifier_type("geometry_collide_12", "geometry_collide");
		particle_modifier_instance* pm_inst_geometry_collide = pm_type_geometry_collide->create_instance();
		pm_inst_geometry_collide->attributes["elasticity"] = 0.75f;

		particle_modifier_type* pm_type_rolling = ps.add_particle_modifier_type("rolling_12", "rolling");
		particle_modifier_instance* pm_inst_rolling = pm_type_rolling->create_instance();

		particle_modifier_type* pm_type_gravity_point_a = ps.add_particle_modifier_type("gravity_point_12a", "pulsar");
		pm_type_gravity_point_a->attributes["mass"] = 1000.0f;
		pm_type_gravity_point_a->attributes["gravity"] = 5.0f;
		particle_modifier_instance* pm_inst_gravity_point_a = pm_type_gravity_point_a->create_instance(vec(256.0f, 512.0f, 390.0f));

		particle_modifier_type* pm_type_gravity_point_b = ps.add_particle_modifier_type("gravity_point_12b", "pulsar");
		pm_type_gravity_point_b->attributes["mass"] = 1000.0f;
		pm_type_gravity_point_b->attributes["gravity"] = 5.0f;
		particle_modifier_instance* pm_inst_gravity_point_b = pm_type_gravity_point_b->create_instance(vec(768.0f, 512.0f, 390.0f));

		particle_modifier_type* pm_type_gravity_point_c = ps.add_particle_modifier_type("gravity_point_12c", "pulsar");
		pm_type_gravity_point_c->attributes["mass"] = 1000.0f;
		pm_type_gravity_point_c->attributes["gravity"] = 5.0f;
		particle_modifier_instance* pm_inst_gravity_point_c = pm_type_gravity_point_c->create_instance(vec(512.0f, 256.0f, 390.0f));

		particle_modifier_type* pm_type_gravity_point_d = ps.add_particle_modifier_type("gravity_point_12d", "pulsar");
		pm_type_gravity_point_d->attributes["mass"] = 1000.0f;
		pm_type_gravity_point_d->attributes["gravity"] = 5.0f;
		particle_modifier_instance* pm_inst_gravity_point_d = pm_type_gravity_point_d->create_instance(vec(512.0f, 768.0f, 390.0f));

		particle_modifier_type* pm_type_gravity_point_e = ps.add_particle_modifier_type("gravity_point_12e", "pulsar");
		pm_type_gravity_point_e->attributes["mass"] = 1000.0f;
		pm_type_gravity_point_e->attributes["gravity"] = -5.0f;
		particle_modifier_instance* pm_inst_gravity_point_e = pm_type_gravity_point_e->create_instance(vec(512.0f, 512.0f, 134.0f));

		particle_modifier_type* pm_type_gravity_point_f = ps.add_particle_modifier_type("gravity_point_12f", "pulsar");
		pm_type_gravity_point_f->attributes["mass"] = 1000.0f;
		pm_type_gravity_point_f->attributes["gravity"] = -5.0f;
		particle_modifier_instance* pm_inst_gravity_point_f = pm_type_gravity_point_f->create_instance(vec(512.0f, 512.0f, 646.0f));


		particle_modifier_type* pm_type_randomv = ps.add_particle_modifier_type("randomv_12", "randomv");
		particle_modifier_instance* pm_inst_randomv = pm_type_randomv->create_instance();


		particle_emitter_type* pe_type_sphere_grenade = ps.add_particle_emitter_type("sphere_grenade_emitter_12", "grendade_12", mass, density, lifetime, rate, "sphere_emitter");

		particle_emitter_instance* pe_inst_sphere_grenade = pe_type_sphere_grenade->create_instance(vec(512.0f, 512.0f, 390.0f), vec(10.0f, 10.0f, 0.0f));
		pe_inst_sphere_grenade->add_modifier(pm_inst_velocity_transformation);
		pe_inst_sphere_grenade->add_modifier(pm_inst_gravity_point_a);
		pe_inst_sphere_grenade->add_modifier(pm_inst_gravity_point_b);
		pe_inst_sphere_grenade->add_modifier(pm_inst_gravity_point_c);
		pe_inst_sphere_grenade->add_modifier(pm_inst_gravity_point_d);
		pe_inst_sphere_grenade->add_modifier(pm_inst_geometry_collide);
		pe_inst_sphere_grenade->add_modifier(pm_inst_rolling);
		pe_inst_sphere_grenade->add_modifier(pm_inst_randomv);
    }

	void setup13()
    {
		float mass = 1.0f;
		float density = 1.0f;
		int lifetime = 10000;
		int rate = 50;

		particle_renderer_type* pr_type_shockwave = ps.add_particle_renderer_type("plasma_renderer_13", "media/particle/shockwave01.png", "shader", vec4(128.0f, 128.0f, 255.0f, 0.3f), "billboard_renderer");
		pr_type_shockwave->attributes["size"] = 40.0f;
		particle_renderer_instance* pr_inst_shockwave_1 = pr_type_shockwave->create_instance("shockwave_1");
		pr_inst_shockwave_1->color = vec4(0.0f, 192.0f, 255.0f, 0.1f);
		pr_inst_shockwave_1->attributes["size"] = 80.0f;
		particle_renderer_instance* pr_inst_shockwave_2 = pr_type_shockwave->create_instance("shockwave_2");
		pr_inst_shockwave_2->color = vec4(255.0f, 192.0f, 0.0f, 0.1f);
		pr_inst_shockwave_2->attributes["size"] = 40.0f;
		particle_renderer_instance* pr_inst_shockwave_3 = pr_type_shockwave->create_instance("shockwave_3");
		pr_inst_shockwave_3->color = vec4(192.0f, 255.0f, 0.0f, 0.1f);
		pr_inst_shockwave_3->attributes["size"] = 20.0f;
		particle_renderer_instance* pr_inst_shockwave_4 = pr_type_shockwave->create_instance("shockwave_4");
		pr_inst_shockwave_4->color = vec4(192.0f, 0.0f, 255.0f, 0.1f);
		pr_inst_shockwave_4->attributes["size"] = 60.0f;
		particle_renderer_instance* pr_inst_shockwave_5 = pr_type_shockwave->create_instance("shockwave_5");
		pr_inst_shockwave_5->color = vec4(0.0f, 0.0f, 255.0f, 0.1f);
		pr_inst_shockwave_5->attributes["size"] = 100.0f;

		particle_type* p_type_shockwave_1 = ps.add_particle_type("shockwave_13_1", pr_inst_shockwave_1);
		particle_type* p_type_shockwave_2 = ps.add_particle_type("shockwave_13_2", pr_inst_shockwave_2);
		particle_type* p_type_shockwave_3 = ps.add_particle_type("shockwave_13_3", pr_inst_shockwave_3);
		particle_type* p_type_shockwave_4 = ps.add_particle_type("shockwave_13_4", pr_inst_shockwave_4);
		particle_type* p_type_shockwave_5 = ps.add_particle_type("shockwave_13_5", pr_inst_shockwave_5);

		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation_13", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();

		particle_initializer_type* pi_type_random_velocity = ps.add_particle_initializer_type("random_velocity_13", "random_velocity");
		pi_type_random_velocity->attributes["osx"] = 40.0f;
		pi_type_random_velocity->attributes["osy"] = 0.0f;
		pi_type_random_velocity->attributes["osz"] = 40.0f;
		pi_type_random_velocity->attributes["isx"] = 20.0f;
		pi_type_random_velocity->attributes["isy"] = 0.0f;
		pi_type_random_velocity->attributes["isz"] = 0.0f;
		particle_initializer_instance* pi_inst_random_velocity = pi_type_random_velocity->create_instance();

		particle_initializer_type* pi_type_random_particle_type = ps.add_particle_initializer_type("random_particle_type_15", "random_particle_type");
		particle_initializer_instance* pi_inst_random_particle_type = pi_type_random_particle_type->create_instance();
		pi_inst_random_particle_type->particle_types.push_back(p_type_shockwave_1);
		pi_inst_random_particle_type->particle_types.push_back(p_type_shockwave_2);
		pi_inst_random_particle_type->particle_types.push_back(p_type_shockwave_3);
		pi_inst_random_particle_type->particle_types.push_back(p_type_shockwave_4);
		pi_inst_random_particle_type->particle_types.push_back(p_type_shockwave_5);

		particle_emitter_type* pe_type_point_plasma = ps.add_particle_emitter_type("plasma_point_emitter_13", "plasma_13", mass, density, lifetime, rate, "point_emitter");
		particle_emitter_instance* pe_inst_point_plasma = pe_type_point_plasma->create_instance(vec(512.0f, 512.0f, 350.0f), vec(0.0f, 0.0f, 0.0f));
		pe_inst_point_plasma->add_modifier(pm_inst_velocity_transformation);
		pe_inst_point_plasma->add_initializer(pi_inst_random_velocity);
		pe_inst_point_plasma->add_initializer(pi_inst_random_particle_type);
    }

	void setup14()
    {
		float mass = 1.0f;
		float density = 1.0f;
		int lifetime = 1000;
		int rate = 5;

		particle_renderer_type* pr_type_sparkle = ps.add_particle_renderer_type("sparkle_renderer_14", "media/particle/spark01.png", "shader", vec4(128.0f, 128.0f, 255.0f, 0.3f), "billboard_renderer");
		pr_type_sparkle->attributes["size"] = 60.0f;
		particle_renderer_instance* pr_inst_sparkle = pr_type_sparkle->create_instance("sparkle_14");

		particle_type* p_type_sparkle = ps.add_particle_type("sparkle_14", pr_inst_sparkle);

		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation_14", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();
		particle_modifier_type* pm_type_geometry_culling = ps.add_particle_modifier_type("geometry_culling_14", "geometry_culling");
		particle_modifier_instance* pm_inst_geometry_culling = pm_type_geometry_culling->create_instance();

		particle_initializer_type* pi_type_random_position = ps.add_particle_initializer_type("random_position_14", "random_position");
		pi_type_random_position->attributes["osx"] = 0.0f;
		pi_type_random_position->attributes["osy"] = 0.0f;
		pi_type_random_position->attributes["osz"] = 50.0f;
		pi_type_random_position->attributes["isx"] = 0.0f;
		pi_type_random_position->attributes["isy"] = 0.0f;
		pi_type_random_position->attributes["isz"] = 0.0f;
		particle_initializer_instance* pi_inst_random_position = pi_type_random_position->create_instance();
		particle_initializer_type* pi_type_random_velocity = ps.add_particle_initializer_type("random_velocity_14", "random_velocity");
		pi_type_random_velocity->attributes["osx"] = 40.0f;
		pi_type_random_velocity->attributes["osy"] = 40.0f;
		pi_type_random_velocity->attributes["osz"] = 0.0f;
		pi_type_random_velocity->attributes["isx"] = 20.0f;
		pi_type_random_velocity->attributes["isy"] = 20.0f;
		pi_type_random_velocity->attributes["isz"] = 0.0f;
		particle_initializer_instance* pi_inst_random_velocity = pi_type_random_velocity->create_instance();

		particle_emitter_type* pe_type_point_sparkle = ps.add_particle_emitter_type("sparkle_point_emitter_14", "sparkle_14", mass, density, lifetime, rate, "point_emitter");
		particle_emitter_instance* pe_inst_point_plasma = pe_type_point_sparkle->create_instance(vec(512.0f, 512.0f, 514.0f), vec(0.0f, 0.0f, 0.0f));
		pe_inst_point_plasma->add_modifier(pm_inst_velocity_transformation);
		pe_inst_point_plasma->add_modifier(pm_inst_geometry_culling);
		pe_inst_point_plasma->add_initializer(pi_inst_random_position);
		pe_inst_point_plasma->add_initializer(pi_inst_random_velocity);
    }

	void setup15()
    {
		float mass = 1.0f;
		float density = 1.0f;
		int lifetime = 1000;
		int rate = 10;

		particle_renderer_type* pr_type_flash = ps.add_particle_renderer_type("flash_renderer_15", "media/particle/flash01.png", "shader", vec4(255.0f, 0.0f, 0.0f, 0.2f), "billboard_renderer");
		pr_type_flash->attributes["size"] = 45.0f;
		particle_renderer_instance* pr_inst_flash_1 = pr_type_flash->create_instance("flash_15_1");
		particle_renderer_instance* pr_inst_flash_2 = pr_type_flash->create_instance("flash_15_2");
		pr_inst_flash_2->color = vec4(255.0f, 192.0f, 0.0f, 0.1f);

		particle_type* p_type_flash_1 = ps.add_particle_type("flash_15_1", pr_inst_flash_1);
		particle_type* p_type_flash_2 = ps.add_particle_type("flash_15_2", pr_inst_flash_2);

		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation_15", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();
		particle_modifier_type* pm_type_geometry_culling = ps.add_particle_modifier_type("geometry_culling_15", "geometry_culling");
		particle_modifier_instance* pm_inst_geometry_culling = pm_type_geometry_culling->create_instance();

		particle_initializer_type* pi_type_random_position = ps.add_particle_initializer_type("random_position_15", "random_position");
		pi_type_random_position->attributes["osx"] = 10.0f;
		pi_type_random_position->attributes["osy"] = 10.0f;
		pi_type_random_position->attributes["osz"] = 0.0f;
		pi_type_random_position->attributes["isx"] = 5.0f;
		pi_type_random_position->attributes["isy"] = 5.0f;
		pi_type_random_position->attributes["isz"] = 0.0f;
		particle_initializer_instance* pi_inst_random_position = pi_type_random_position->create_instance();
		particle_initializer_type* pi_type_random_velocity = ps.add_particle_initializer_type("random_velocity_15", "random_velocity");
		pi_type_random_velocity->attributes["osx"] = 0.0f;
		pi_type_random_velocity->attributes["osy"] = 0.0f;
		pi_type_random_velocity->attributes["osz"] = 40.0f;
		pi_type_random_velocity->attributes["isx"] = 0.0f;
		pi_type_random_velocity->attributes["isy"] = 0.0f;
		pi_type_random_velocity->attributes["isz"] = 0.0f;
		particle_initializer_instance* pi_inst_random_velocity = pi_type_random_velocity->create_instance();

		particle_initializer_type* pi_type_random_particle_type = ps.add_particle_initializer_type("random_particle_type_15", "random_particle_type");
		particle_initializer_instance* pi_inst_random_particle_type = pi_type_random_particle_type->create_instance();
		pi_inst_random_particle_type->particle_types.push_back(p_type_flash_1);
		pi_inst_random_particle_type->particle_types.push_back(p_type_flash_2);

		particle_emitter_type* pe_type_field_flash = ps.add_particle_emitter_type("flash_field_emitter_15", "flash_15_1", mass, density, lifetime, rate, "field_emitter");
		pe_type_field_flash->batch_size = 1;
		pe_type_field_flash->attributes["grid_size_x"] = 3.0f;
		pe_type_field_flash->attributes["grid_size_y"] = 3.0f;
		pe_type_field_flash->attributes["grid_size_z"] = 3.0f;
		pe_type_field_flash->attributes["grid_dist"] = 50.0f;

		particle_emitter_instance* pe_inst_field_flash = pe_type_field_flash->create_instance(vec(512.0f, 512.0f, 514.0f), vec(0.0f, 0.0f, 0.0f));
		pe_inst_field_flash->add_modifier(pm_inst_velocity_transformation);
		pe_inst_field_flash->add_modifier(pm_inst_geometry_culling);
		pe_inst_field_flash->add_initializer(pi_inst_random_position);
		pe_inst_field_flash->add_initializer(pi_inst_random_velocity);
		pe_inst_field_flash->add_initializer(pi_inst_random_particle_type);
    }

	void setup16()
    {
		float mass = 1.0f;
		float density = 1.0f;
		int lifetime = 3000;
		int rate = 10;

		particle_renderer_type* pr_type_dust = ps.add_particle_renderer_type("dust_renderer_16", "media/particle/dust01.png", "shader", vec4(255.0f, 0.0f, 0.0f, 0.2f), "billboard_renderer");
		pr_type_dust->attributes["size"] = 45.0f;

		particle_renderer_instance* pr_inst_dust_1 = pr_type_dust->create_instance("dust_16_1");
		pr_inst_dust_1->color = vec4(255.0f, 192.0f, 0.0f, 0.1f);
		pr_inst_dust_1->texture = "media/particle/smalljunk01.png";
		particle_renderer_instance* pr_inst_dust_2 = pr_type_dust->create_instance("dust_16_2");
		pr_inst_dust_2->color = vec4(192.0f, 192.0f, 0.0f, 0.1f);
		pr_inst_dust_2->texture = "media/particle/smalljunk02.png";
		particle_renderer_instance* pr_inst_dust_3 = pr_type_dust->create_instance("dust_16_3");
		pr_inst_dust_3->color = vec4(128.0f, 192.0f, 0.0f, 0.1f);
		pr_inst_dust_3->texture = "media/particle/smalljunk03.png";

		particle_type* p_type_dust_1 = ps.add_particle_type("dust_16_1", pr_inst_dust_1);
		particle_type* p_type_dust_2 = ps.add_particle_type("dust_16_2", pr_inst_dust_2);
		particle_type* p_type_dust_3 = ps.add_particle_type("dust_16_3", pr_inst_dust_3);

		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation_16", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();
		particle_modifier_type* pm_type_geometry_culling = ps.add_particle_modifier_type("geometry_culling_16", "geometry_culling");
		particle_modifier_instance* pm_inst_geometry_culling = pm_type_geometry_culling->create_instance();

		particle_initializer_type* pi_type_random_velocity = ps.add_particle_initializer_type("random_velocity_16", "random_velocity");
		pi_type_random_velocity->attributes["osx"] = 200.0f;
		pi_type_random_velocity->attributes["osy"] = 200.0f;
		pi_type_random_velocity->attributes["osz"] = -5.0f;
		pi_type_random_velocity->attributes["isx"] = 100.0f;
		pi_type_random_velocity->attributes["isy"] = 100.0f;
		pi_type_random_velocity->attributes["isz"] = -2.5f;
		particle_initializer_instance* pi_inst_random_velocity = pi_type_random_velocity->create_instance();

		particle_initializer_type* pi_type_random_particle_type = ps.add_particle_initializer_type("random_particle_type_16", "random_particle_type");
		particle_initializer_instance* pi_inst_random_particle_type = pi_type_random_particle_type->create_instance();
		pi_inst_random_particle_type->particle_types.push_back(p_type_dust_1);
		pi_inst_random_particle_type->particle_types.push_back(p_type_dust_2);
		pi_inst_random_particle_type->particle_types.push_back(p_type_dust_3);

		particle_emitter_type* pe_type_box_dust = ps.add_particle_emitter_type("dust_box_emitter_16", p_type_dust_1, mass, density, lifetime, rate, "box_emitter");
		pe_type_box_dust->density = 512.0f;

		particle_emitter_instance* pe_inst_box_dust = pe_type_box_dust->create_instance(vec(512.0f, 512.0f, 514.0f), vec(0.0f, 0.0f, 0.0f));
		pe_inst_box_dust->add_modifier(pm_inst_velocity_transformation);
		pe_inst_box_dust->add_initializer(pi_inst_random_velocity);
		pe_inst_box_dust->add_initializer(pi_inst_random_particle_type);
    }

	void position_trace_modifier_test()
    {
		float mass = 1.0f;
		float density = 1.0f;
		int lifetime = 1000;
		int rate = 5;

		particle_renderer_type* pr_type_sparkle = ps.add_particle_renderer_type("sparkle_renderer_17", "media/particle/flash01.png", "shader", vec4(128.0f, 128.0f, 0.0f, 0.3f), "billboard_renderer");
		pr_type_sparkle->attributes["size"] = 60.0f;
		particle_renderer_instance* pr_inst_sparkle_0 = pr_type_sparkle->create_instance("sparkle_17_0");
		pr_inst_sparkle_0->color = vec4(255.0f, 0.0f, 0.0f, 0.5f);
		pr_inst_sparkle_0->attributes["size"] = 30.0f;
		particle_renderer_instance* pr_inst_sparkle_1 = pr_type_sparkle->create_instance("sparkle_17_1");
		pr_inst_sparkle_1->color = vec4(0.0f, 128.0f, 255.0f, 0.6f);
		pr_inst_sparkle_1->attributes["size"] = 30.0f;
		particle_renderer_instance* pr_inst_sparkle_2 = pr_type_sparkle->create_instance("sparkle_17_2");
		pr_inst_sparkle_2->color = vec4(128.0f, 128.0f, 255.0f, 0.3f);
		pr_inst_sparkle_2->attributes["size"] = 40.0f;
		particle_renderer_instance* pr_inst_sparkle_3 = pr_type_sparkle->create_instance("sparkle_17_3");
		pr_inst_sparkle_3->color = vec4(128.0f, 0.0f, 255.0f, 0.9f);
		pr_inst_sparkle_3->attributes["size"] = 50.0f;

		particle_type* p_type_sparkle_0 = ps.add_particle_type("sparkle_17_0", pr_inst_sparkle_0);
		particle_type* p_type_sparkle_1 = ps.add_particle_type("sparkle_17_1", pr_inst_sparkle_1);
		particle_type* p_type_sparkle_2 = ps.add_particle_type("sparkle_17_2", pr_inst_sparkle_2);
		particle_type* p_type_sparkle_3 = ps.add_particle_type("sparkle_17_3", pr_inst_sparkle_3);

		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation_17", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();
		particle_modifier_type* pm_type_geometry_culling = ps.add_particle_modifier_type("geometry_culling_17", "geometry_culling");
		particle_modifier_instance* pm_inst_geometry_culling = pm_type_geometry_culling->create_instance();
		particle_modifier_type* pm_type_position_trace = ps.add_particle_modifier_type("position_trace_17", "position_trace");
		particle_modifier_instance* pm_inst_position_trace = pm_type_position_trace->create_instance();
		pm_inst_position_trace->attributes["rate"] = 25;
		pm_inst_position_trace->attributes["lifetime"] = 750;

		particle_modifier_type* pm_type_sub_emitter = ps.add_particle_modifier_type("sub_emitter_17", "sub_emitter");
		particle_modifier_instance* pm_inst_sub_emitter = pm_type_sub_emitter->create_instance();

		particle_initializer_type* pi_type_random_velocity = ps.add_particle_initializer_type("random_velocity_17", "random_velocity");
		pi_type_random_velocity->attributes["osx"] = 100.0f;
		pi_type_random_velocity->attributes["osy"] = 100.0f;
		pi_type_random_velocity->attributes["osz"] = 50.0f;
		pi_type_random_velocity->attributes["isx"] = 50.0f;
		pi_type_random_velocity->attributes["isy"] = 50.0f;
		pi_type_random_velocity->attributes["isz"] = 0.0f;
		particle_initializer_instance* pi_inst_random_velocity = pi_type_random_velocity->create_instance();

		particle_initializer_type* pi_type_random_velocity_sub = ps.add_particle_initializer_type("random_velocity_17_sub", "random_velocity");
		pi_type_random_velocity_sub->attributes["osx"] = 30.0f;
		pi_type_random_velocity_sub->attributes["osy"] = 30.0f;
		pi_type_random_velocity_sub->attributes["osz"] = 30.0f;
		pi_type_random_velocity_sub->attributes["isx"] = 0.0f;
		pi_type_random_velocity_sub->attributes["isy"] = 0.0f;
		pi_type_random_velocity_sub->attributes["isz"] = 0.0f;
		particle_initializer_instance* pi_inst_random_velocity_sub = pi_type_random_velocity_sub->create_instance();

		particle_initializer_type* pi_type_random_particle_type = ps.add_particle_initializer_type("random_particle_type_17", "random_particle_type");
		particle_initializer_instance* pi_inst_random_particle_type = pi_type_random_particle_type->create_instance();
		pi_inst_random_particle_type->particle_types.push_back(p_type_sparkle_1);
		pi_inst_random_particle_type->particle_types.push_back(p_type_sparkle_2);
		pi_inst_random_particle_type->particle_types.push_back(p_type_sparkle_3);

		particle_emitter_type* pe_type_point_sparkle = ps.add_particle_emitter_type("sparkle_point_emitter_17", "sparkle_17_0", mass, density, lifetime, rate, "point_emitter");
		particle_emitter_instance* pe_inst_point_sparkle = pe_type_point_sparkle->create_instance(vec(512.0f, 512.0f, 514.0f), vec(0.0f, 0.0f, 0.0f));
		pe_inst_point_sparkle->add_modifier(pm_inst_velocity_transformation);
		// pe_inst_point_sparkle->add_modifier(pm_inst_geometry_culling);
		// pe_inst_point_sparkle->add_modifier(pm_inst_position_trace);
		pe_inst_point_sparkle->add_modifier(pm_inst_sub_emitter);
		pe_inst_point_sparkle->add_initializer(pi_inst_random_velocity);
		// pe_inst_point_sparkle->add_initializer(pi_inst_random_particle_type);

		particle_emitter_type* pe_type_point_sub_sparkle = ps.add_particle_emitter_type("sub_sparkle_point_emitter_17", "sparkle_17_3", mass, density, 50, 10, "point_emitter");
		particle_emitter_instance* pe_inst_point_sub_sparkle = pe_type_point_sub_sparkle->create_instance(vec(512.0f, 512.0f, 514.0f), vec(0.0f, 0.0f, 0.0f));
		pe_inst_point_sub_sparkle->add_modifier(pm_inst_velocity_transformation);
		pe_inst_point_sub_sparkle->add_initializer(pi_inst_random_velocity_sub);
		pe_inst_point_sub_sparkle->add_initializer(pi_inst_random_particle_type);

		pm_inst_sub_emitter->pointers["sub_emitter"] = pe_inst_point_sub_sparkle;

    }

	void vector_field_test()
    {
		float mass = 1.0f;
		float density = 1.0f;
		int lifetime = 5000;
		int rate = 10;

		particle_renderer_type* pr_type_sparkle = ps.add_particle_renderer_type("sparkle_renderer_18", "media/particle/flash01.png", "shader", vec4(128.0f, 128.0f, 0.0f, 0.3f), "billboard_renderer");
		pr_type_sparkle->attributes["size"] = 60.0f;
		particle_renderer_instance* pr_inst_sparkle_0 = pr_type_sparkle->create_instance("sparkle_18");
		pr_inst_sparkle_0->color = vec4(255.0f, 0.0f, 0.0f, 0.5f);
		pr_inst_sparkle_0->attributes["size"] = 30.0f;

		particle_type* p_type_sparkle_0 = ps.add_particle_type("sparkle_18", pr_inst_sparkle_0);

		particle_modifier_type* pm_type_velocity_transformation = ps.add_particle_modifier_type("velocity_transformation_18", "velocity_transformation");
		particle_modifier_instance* pm_inst_velocity_transformation = pm_type_velocity_transformation->create_instance();

		particle_modifier_type* pm_type_vector_field = ps.add_particle_modifier_type("vector_field_18", "vector_field");
		particle_modifier_instance* pm_inst_vector_field = pm_type_vector_field->create_instance(vec(512.0f, 512.0f, 512.0f));

		particle_initializer_type* pi_type_random_position = ps.add_particle_initializer_type("random_position_18", "random_position");
		pi_type_random_position->attributes["osx"] = 10.0f;
		pi_type_random_position->attributes["osy"] = 10.0f;
		pi_type_random_position->attributes["osz"] = 0.0f;
		pi_type_random_position->attributes["isx"] = 5.0f;
		pi_type_random_position->attributes["isy"] = 5.0f;
		pi_type_random_position->attributes["isz"] = 0.0f;
		particle_initializer_instance* pi_inst_random_position = pi_type_random_position->create_instance();

		particle_emitter_type* pe_type_point_sparkle = ps.add_particle_emitter_type("sparkle_point_emitter_18", "sparkle_18", mass, density, lifetime, rate, "point_emitter");
		particle_emitter_instance* pe_inst_point_sparkle = pe_type_point_sparkle->create_instance(vec(512.0f, 512.0f, 514.0f), vec(0.0f, 0.0f, 10.0f));
		pe_inst_point_sparkle->add_modifier(pm_inst_velocity_transformation);
		pe_inst_point_sparkle->add_modifier(pm_inst_vector_field);
		pe_inst_point_sparkle->add_initializer(pi_inst_random_position);
    }
};

ptest *ptest_inst = new ptest();

ICOMMAND(ptest, "i", (int *setup), ptest_inst->setup(*setup));
