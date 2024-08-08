#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& _name, int x, int y, int z) : Name(_name), HitPoints(x), EnergyPoints(y), AttackDamage(z), isonGuardGuate(0)
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
    {
        std::cout << "ClapTrap " << Name << " is already dead\n";
        return;
    }
    else{
        std::cout << "ClapTrap " << Name << " is getting attacked, getting damaged by " << amount << "hp\n";
        HitPoints = (static_cast<int>(amount) > HitPoints ? 0 : amount - HitPoints);
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->HitPoints == 0)
    {
        std::cout << "ClapTrap " << Name << " is dead\n";
        return;
    }
    if (this->EnergyPoints == 0)
        std::cout << "Out of EnergyPoints !\n";
    else
    {
        std::cout << "ClapTrap(" << Name << ") healed by "<< amount << "hp\n" ;
        this->HitPoints = amount;
        this->EnergyPoints--;
    }
}

void ClapTrap::attack(const std::string& target)
{
    if (this->HitPoints == 0)
    {
        std::cout << "ClapTrap " << Name << " is dead\n";
        return;
    }
    if (this->EnergyPoints == 0)
        std::cout << "Out of EnergyPoints !\n";
    else
    {
        std::cout << "ClapTrap " << Name << " attacks " <<
            target << " , causing " << AttackDamage << " points of damage!\n";
        this->EnergyPoints--;
    }
}

const std::string& ClapTrap::getName()
{
    return Name;
}

const int& ClapTrap::getHitPoints()
{
    return HitPoints;
}

const int& ClapTrap::getAttackDamage()
{
    return AttackDamage;
}

const int& ClapTrap::getEnergyPoints()
{
    return EnergyPoints;
}

void ClapTrap::setonGuardGate()
{
    isonGuardGuate = 1;
}

const int& ClapTrap::getGuardGateid(void)
{
    return isonGuardGuate;
}

void ClapTrap::setEnergyPoints(const int& _val)
{
    EnergyPoints = _val;
}

void ClapTrap::setHitPoints(const int& _val)
{
    HitPoints = _val;
}