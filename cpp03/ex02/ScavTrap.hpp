#pragma once
#ifndef __SCAVTRAP_H__
#define __SCAVTRAP__

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{

public:
    ScavTrap(const std::string& _name);
    ScavTrap(const ScavTrap& _copy);
    ScavTrap& operator=(const ScavTrap& _copy);
    ~ScavTrap();
    void guardGate(void);
    virtual void attack(const std::string& target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);
};

#endif