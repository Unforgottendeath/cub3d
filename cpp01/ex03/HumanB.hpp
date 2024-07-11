#pragma once
#ifndef __HUMANB_H__
#define __HUMANB_H__
#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <cstddef>

class HumanB
{

private:
    std::string     name;
    Weapon*         Weapon_B;

public:
    void attack();
    void setWeapon(Weapon &t_Weapon);
    HumanB(std::string _name);
    ~HumanB();
};


#endif