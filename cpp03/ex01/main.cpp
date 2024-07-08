#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap humanA("Combattant");
    humanA.attack("Rabie");
    humanA.takeDamage(500);
    humanA.takeDamage(500);
    humanA.beRepaired(500);
    humanA.guardGate();
}