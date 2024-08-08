#include "Weapon.hpp"

const std::string&  Weapon::getType(){return type;};

void                Weapon::setType(std::string new_name){type = new_name;};

Weapon::Weapon(std::string weapon_name) : type(weapon_name)
{
    std::cout << "Constructing Weapon object : " << type << "\n";
}

Weapon::~Weapon(){std::cout << "Destructing Weapon object : " << type << "\n";};
