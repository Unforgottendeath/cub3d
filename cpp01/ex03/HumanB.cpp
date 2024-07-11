#include "HumanB.hpp"

void HumanB::attack()
{
    if (Weapon_B != NULL)
    {
        std::cout << name << " attacks with their " 
            << Weapon_B->getType() << "\n";
    }
}

HumanB::HumanB(std::string _name) : name(_name) , Weapon_B(NULL)
{
    std::cout << "Constructing " << name << "\n";
}

void HumanB::setWeapon(Weapon &Weapon_t)
{
    Weapon_B = &Weapon_t;
}

HumanB::~HumanB()
{
    std::cout << "Destructing " << name << "\n";
}
