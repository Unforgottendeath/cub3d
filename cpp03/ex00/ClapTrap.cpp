#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& _name) : Name(_name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap(" << Name << ") constructed\n";
}

ClapTrap::ClapTrap(const ClapTrap& _copy)
{
    *this = _copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& _copy)
{
    std::cout << "ClapTrap copy assignment operator called !\n";
    if (this == &_copy)
        return *this;
    Name = _copy.Name;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap(" << Name << ") destructed\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HitPoints == 0)
        std::cout << "ClapTrap " << Name << " is already dead\n";
    else{
        std::cout << "ClapTrap " << Name << " is getting attacked, getting damaged by " << amount << "hp\n";
        HitPoints = (static_cast<int>(amount) > HitPoints ? 0 : amount - HitPoints);
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->EnergyPoints == 0)
    {
        std::cout << "Out of EnergyPoints !\n";
        return;
    }
    std::cout << "ClapTrap(" << Name << ") healed by "<< amount << "hp\n" ;
    this->HitPoints = amount;
    this->EnergyPoints--;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->EnergyPoints == 0)
    {
        std::cout << "Out of EnergyPoints !\n";
        return;
    }
    std::cout << "ClapTrap " << Name << " attacks " <<
        target << " , causing " << AttackDamage << " points of damage!\n";
    this->EnergyPoints--;
}
