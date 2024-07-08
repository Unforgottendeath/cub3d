#pragma once
#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap , public ScavTrap
{

private:
    std::string Name;

public:
    DiamondTrap(std::string dia_name, std::string clap_name, int frag_hit_points = 100,
        int scav_energy_points = 50, int frag_attack_damage = 30);
    void whoAmI(void);
};

#endif