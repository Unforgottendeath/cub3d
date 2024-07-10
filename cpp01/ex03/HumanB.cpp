#include "HumanB.hpp"

void HumanB::attack()
{
    if (Weapon_type != NULL)
    {
        std::cout << Human_name << " attacks with their " 
            << Weapon_type->getType() << "\n";
    }
}

HumanB::HumanB(std::string _name) : Human_name(_name) , Weapon_type(NULL)
{
    std::cout << "Constructing " << Human_name << "\n";
}

void HumanB::setWeapon(Weapon &Weapon_t)
{
    Weapon_type = &Weapon_t;
}

HumanB::~HumanB()
{
    std::cout << "Destructing " << Human_name << "\n";
}
