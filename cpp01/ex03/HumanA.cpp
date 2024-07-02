#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << Human_name << " attacks with their " 
        << Weapon_type->getType() << "\n";
}

HumanA::HumanA(std::string _name, Weapon& Weapon_t)
{
    Human_name = _name;
    Weapon_type = &Weapon_t;
}

HumanA::~HumanA()
{
    std::cout << "Destructing HumanA objects : " << Human_name << " and " 
        << Weapon_type->getType() << "\n";
}