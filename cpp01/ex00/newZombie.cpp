#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie* zombie_alloc = new Zombie(name);
    return (zombie_alloc);
}