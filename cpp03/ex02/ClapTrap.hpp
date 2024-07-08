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
    int isonGuardGuate;

public:
    ClapTrap(const std::string& _name, int _hit_points=10, int _energypoints=10, int _attackdamage=0);
    ClapTrap(const ClapTrap& _copy);
    ClapTrap& operator=(const ClapTrap& _copy);
    ~ClapTrap();
    virtual void attack(const std::string& target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);
    const std::string& getName(void);
    const int& getHitPoints(void);
    const int& getEnergyPoints(void);
    const int& getAttackDamage(void);
    const int& getGuardGateid(void);
    void setEnergyPoints(const int& val);
    void setHitPoints(const int& val);
    void setonGuardGate(void);
    
};

#endif