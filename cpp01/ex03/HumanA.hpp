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
    std::string     Human_name;
    Weapon*          Weapon_type;

public:
    void attack();
    HumanA(std::string _name, Weapon& Weapon_t);
    ~HumanA();
};


#endif