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
