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
