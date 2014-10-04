#include "engine.h"
#include "particles.h"

void particle_system::add_spring(spring_instance *spring_inst)
{
	spring_instances.push_back(spring_inst);
	count_spring_instances++;
}

void particle_system::add_spring_construction_rule(std::string name, ivec rule)
{
	ps.spring_construction_rules[name] = rule;
}

void particle_system::add_spring_construction_rule(std::string name, int x, int y, int z)
{
	ps.spring_construction_rules[name] = ivec(x, y, z);
}

/**
 * Some useful default rules for stretch, sheer and bend springs.
 */
void particle_system::init_spring_construction_rules()
{
	add_spring_construction_rule("stretch_x", ivec(1, 0, 0));
	add_spring_construction_rule("stretch_y", ivec(0, 1, 0));
	add_spring_construction_rule("stretch_z", ivec(0, 0, 1));
	add_spring_construction_rule("sheer_xy_p", ivec(1, 1, 0));
	add_spring_construction_rule("sheer_xy_n", ivec(-1, 1, 0));
	add_spring_construction_rule("sheer_xz_p", ivec(1, 0, 1));
	add_spring_construction_rule("sheer_xz_n", ivec(-1, 0, 1));
	add_spring_construction_rule("sheer_yz_p", ivec(0, 1, 1));
	add_spring_construction_rule("sheer_yz_n", ivec(0, -1, 1));
	add_spring_construction_rule("sheer_xyz_ppp", ivec(1, 1, 1));
	add_spring_construction_rule("sheer_xyz_npp", ivec(-1, 1, 1));
	add_spring_construction_rule("sheer_xyz_pnp", ivec(1, -1, 1));
	add_spring_construction_rule("sheer_xyz_ppn", ivec(1, 1, -1));
	add_spring_construction_rule("bend_x", ivec(2, 0, 0));
	add_spring_construction_rule("bend_y", ivec(0, 2, 0));
	add_spring_construction_rule("bend_z", ivec(0, 0, 2));
	add_spring_construction_rule("sheer_xy2_p", ivec(2, 2, 0));
	add_spring_construction_rule("sheer_xy2_n", ivec(-2, 2, 0));
}

spring_builder::spring_builder()
{
	rules = new std::vector<std::string>;
}

spring_builder::~spring_builder() { }

spring_builder* spring_builder::stretch_x()
{
	rules->push_back("stretch_x");
	return this;
}

spring_builder* spring_builder::stretch_y()
{
	rules->push_back("stretch_y");
	return this;
}

spring_builder* spring_builder::stretch_z()
{
	rules->push_back("stretch_z");
	return this;
}

spring_builder* spring_builder::stretch_xy()
{
	rules->push_back("stretch_x");
	rules->push_back("stretch_y");
	return this;
}

spring_builder* spring_builder::stretch_xz()
{
	rules->push_back("stretch_x");
	rules->push_back("stretch_z");
	return this;
}

spring_builder* spring_builder::stretch_yz()
{
	rules->push_back("stretch_y");
	rules->push_back("stretch_z");
	return this;
}

spring_builder* spring_builder::stretch_xyz()
{
	rules->push_back("stretch_x");
	rules->push_back("stretch_y");
	rules->push_back("stretch_z");
	return this;
}

spring_builder* spring_builder::sheer_xy()
{
	rules->push_back("sheer_xy_p");
	rules->push_back("sheer_xy_n");
	return this;
}

spring_builder* spring_builder::sheer_xy2()
{
	rules->push_back("sheer_xy2_p");
	rules->push_back("sheer_xy2_n");
	return this;
}

spring_builder* spring_builder::sheer_xz()
{
	rules->push_back("sheer_xz_p");
	rules->push_back("sheer_xz_n");
	return this;
}

spring_builder* spring_builder::sheer_yz()
{
	rules->push_back("sheer_yz_p");
	rules->push_back("sheer_yz_n");
	return this;
}

spring_builder* spring_builder::sheer_xyz()
{
	rules->push_back("sheer_xy_p");
	rules->push_back("sheer_xy_n");
	rules->push_back("sheer_xz_p");
	rules->push_back("sheer_xz_n");
	rules->push_back("sheer_yz_p");
	rules->push_back("sheer_yz_n");
	rules->push_back("sheer_xyz_ppp");
	rules->push_back("sheer_xyz_npp");
	rules->push_back("sheer_xyz_pnp");
	rules->push_back("sheer_xyz_ppn");
	return this;
}

spring_builder* spring_builder::bend_x()
{
	rules->push_back("bend_x");
	return this;
}

spring_builder* spring_builder::bend_y()
{
	rules->push_back("bend_y");
	return this;
}

spring_builder* spring_builder::bend_z()
{
	rules->push_back("bend_z");
	return this;
}

spring_builder* spring_builder::bend_xy()
{
	rules->push_back("bend_x");
	rules->push_back("bend_y");
	return this;
}

spring_builder* spring_builder::bend_xz()
{
	rules->push_back("bend_x");
	rules->push_back("bend_z");
	return this;
}

spring_builder* spring_builder::bend_yz()
{
	rules->push_back("bend_y");
	rules->push_back("bend_z");
	return this;
}

spring_builder* spring_builder::bend_xyz()
{
	rules->push_back("bend_x");
	rules->push_back("bend_y");
	rules->push_back("bend_z");
	return this;
}

std::vector<std::string>* spring_builder::get()
{
	return rules;
}
