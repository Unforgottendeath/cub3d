#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice constructed !\n"; 
}

AMateria* Ice::clone() const
{
    return new Ice;
}

Ice::~Ice()
{
    std::cout << "Ice destructed !\n";
}