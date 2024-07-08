#pragma once
#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <iostream>
#include <string>

class ClapTrap
{
    
private:
    std::string Name;
    int HitPoints;
    int EnergyPoints;
    int AttackDamage;

public:
    ClapTrap(const std::string& _name);
    ClapTrap(const ClapTrap& _copy);
    ClapTrap& operator=(const ClapTrap& _copy);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
};

#endif