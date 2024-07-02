#include "Weapon.hpp"

const std::string  Weapon::getType(){return _name;};

void                Weapon::setType(std::string new_name){_name = new_name;};

Weapon::Weapon(std::string weapon_name){_name = weapon_name;};

Weapon::~Weapon(){std::cout << "Destructing Weapon object : " << _name << "\n";};