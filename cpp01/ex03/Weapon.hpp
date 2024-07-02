#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__
#include <iostream>
#include <string>
#include <cstddef>

class Weapon
{

private:
    std::string _name;

public:
    const std::string         getType();
    void                setType(std::string new_name);
    Weapon(std::string Weapon_name);
    ~Weapon();
};


#endif