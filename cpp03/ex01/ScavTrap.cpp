#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& _name) : ClapTrap(_name, 100, 50, 20)
{
    std::cout << "ScavTrap (" << _name << ") Constructed\n";
}

ScavTrap::ScavTrap(const ScavTrap& _copy) : ClapTrap(_copy)
{
    std::cout << "Calling copy constructor !\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& _copy)
{
    std::cout << "Calling assignment operator for ScavTrap !\n";
    if (this == &_copy)
        return *this;
    ClapTrap::operator=(_copy);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Calling ScavTrap destructor !\n";
}

void ScavTrap::guardGate()
{
    std::cout << "Scavtrap " << getName() << " is now in Gate Keeper mode !\n";
    setonGuardGate();
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (getHitPoints() == 0)
    {
        std::cout << "ScavTrap " << getName() << " is dead\n";
        return;
    }
    if (getGuardGateid())
    {
        std::cout << "ScavTrap (" << getName() << ") is immune !\n";
        return;
    }
    else{
        std::cout << "ScavTrap " << getName() << " is getting attacked, getting damaged by " << amount << "hp\n";
        setHitPoints(static_cast<int>(amount) > getHitPoints() ? 0 : amount - getHitPoints());
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (getHitPoints() == 0)
    {
        std::cout << "ScavTrap " << getName() << " is dead\n";
        return;
    }
    if (getEnergyPoints() == 0)
    {
        std::cout << "ScavTrap " << getName() << " is out of EnergyPoints !\n";
        return;
    }
    std::cout << "ScavTrap(" << getName() << ") healed by "<< amount << "hp\n" ;
    setHitPoints(amount);
    setEnergyPoints(getEnergyPoints() - 1);
}

void ScavTrap::attack(const std::string& target)
{
    if ( getHitPoints() == 0 )
    {
        std::cout << "ScavTrap " << getName() << " is dead\n";
        return;
    }
    if (getEnergyPoints() == 0 )
    {
        std::cout << "Out of EnergyPoints !\n";
        return;
    }
    std::cout << "ScavTrap " << getName() << " attacks " <<
        target << " , causing " << getAttackDamage() << " points of damage!\n";
    setEnergyPoints(getEnergyPoints() - 1);
}