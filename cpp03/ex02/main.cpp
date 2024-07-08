#include "FragTrap.hpp"

int main(void)
{
    FragTrap humanA("Combattant");
    humanA.attack("Rabie");
    humanA.takeDamage(500);
    humanA.takeDamage(500);
    humanA.beRepaired(500);
    humanA.highFiveGuys();
}