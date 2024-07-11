#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *hordes = NULL;
    if (N > 0)
    {
        hordes = new Zombie [N];
        for(int i = 0; i < N; i++)
            hordes[i] = Zombie(name);
    }
    return hordes;
}