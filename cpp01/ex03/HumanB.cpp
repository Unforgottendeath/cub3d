#include "HumanB.hpp"

void HumanB::attack()
{
    std::cout << Human_name << " attacks with their " 
        << Weapon_type->getType() << "\n";
}

HumanB::HumanB(std::string _name)
{
    Human_name = _name;
}

void HumanB::setWeapon(Weapon &Weapon_t)
{
    Weapon_type = &Weapon_t;
}

HumanB::~HumanB()
{
    std::cout << "Destructing " << Human_name << " and " 
        << Weapon_type->getType() << "\n";
}
