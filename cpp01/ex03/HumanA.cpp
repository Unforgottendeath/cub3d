#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << name << " attacks with their " 
        << Weapon_A->getType() << "\n";
}

HumanA::HumanA(std::string _name, Weapon& Weapon_t)
{
    name = _name;
    Weapon_A = &Weapon_t;
}

HumanA::~HumanA()
{
    std::cout << "Destructing HumanA objects : " << name << " and " 
        << Weapon_A->getType() << "\n";
}