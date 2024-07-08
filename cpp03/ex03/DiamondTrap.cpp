#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string dia_name, std::string clap_name, int frag_hit_points,
    int scav_energy_points, int frag_attack_damage) :  ClapTrap(clap_name + "_clap_name", frag_hit_points, scav_energy_points, frag_attack_damage), 
        FragTrap(clap_name) , ScavTrap(clap_name) , Name(dia_name) 
{
    std::cout << "DiamondTrap (" << dia_name << ") Contructed !\n";
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap (" << this->Name << ") and ClapTrap (" << getName() << ") !\n";
}