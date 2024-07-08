#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& _name) : ClapTrap(_name, 100, 100, 30)
{
    std::cout << "FragTrap (" << _name << ") Constructed\n";
}

FragTrap::FragTrap(const FragTrap& _copy) : ClapTrap(_copy)
{
    std::cout << "Calling copy constructor !\n";
}

FragTrap& FragTrap::operator=(const FragTrap& _copy)
{
    std::cout << "Calling assignment operator for FragTrap !\n";
    if (this == &_copy)
        return *this;
    ClapTrap::operator=(_copy);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "Calling FragTrap destructor !\n";
}

void FragTrap::highFiveGuys()
{
    std::cout << "High Five Guys !\n";
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (getHitPoints() == 0)
        std::cout << "FragTrap " << getName() << " is already dead\n";
    if (getGuardGateid())
    {
        std::cout << "FragTrap (" << getName() << ") is immune !\n";
        return;
    }
    else{
        std::cout << "FragTrap " << getName() << " is getting attacked, getting damaged by " << amount << "hp\n";
        setHitPoints(static_cast<int>(amount) > getHitPoints() ? 0 : amount - getHitPoints());
    }
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (getEnergyPoints() == 0)
    {
        std::cout << "Out of EnergyPoints !\n";
        return;
    }
    std::cout << "FragTrap(" << getName() << ") healed by "<< amount << "hp\n" ;
    setHitPoints(amount);
    setEnergyPoints(getEnergyPoints() - 1);
}

void FragTrap::attack(const std::string& target)
{
    if ( getHitPoints() == 0 )
    {
        std::cout << "FragTrap " << getName() << " is already dead\n";
        return;
    }
    if (getEnergyPoints() == 0 )
    {
        std::cout << "Out of EnergyPoints !\n";
        return;
    }
    std::cout << "FragTrap " << getName() << " attacks " <<
        target << " , causing " << getAttackDamage() << " points of damage!\n";
    setEnergyPoints(getEnergyPoints() - 1);
}