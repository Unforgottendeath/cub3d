#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap humanA("Combattant", "Rabie");
    humanA.whoAmI();
    std::cout << "Attack damage :" << humanA.getAttackDamage() << " Hit Points : " << humanA.getHitPoints() << "\n";
    humanA.attack("dowla");
}