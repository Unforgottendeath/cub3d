#pragma once
#ifndef __HUMANA_H__
#define __HUMANA_H__
#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>
#include <string>
#include <cstddef>

class HumanA
{

private:
    std::string     name;
    Weapon*          Weapon_A;

public:
    void attack();
    HumanA(std::string _name, Weapon& Weapon_t);
    ~HumanA();
};


#endif