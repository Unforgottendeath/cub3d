#include "Zombie.hpp"

int main(void)
{
    randomChump("Zoe");
    randomChump("Cloe");
    Zombie *zombie_all = newZombie("Moe");
    zombie_all->announce();
    delete zombie_all;
}
