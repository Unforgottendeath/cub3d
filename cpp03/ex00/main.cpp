#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap humanA("Combattant");
    for(int i = 0; i< 15; i++)
        humanA.attack("Rabie");
    humanA.takeDamage(15);
    humanA.beRepaired(10);
    humanA.takeDamage(15);
}