#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << _name << ": " << " BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name)
{
    _name = name;
}

Zombie::~Zombie()
{
    std::cout << "destructing " << _name << "...\n";
}