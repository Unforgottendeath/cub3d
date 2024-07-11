#include "Zombie.hpp"

int main(void)
{
    int N = -1;
    Zombie *horde = zombieHorde(N, "Zoe");
    if (horde != NULL)
    {
        for (int i = 0;i < N;i++)
            horde[i].announce();
    }
    delete [] horde;
}