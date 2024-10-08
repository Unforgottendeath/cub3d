#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << " Ice (materia) is created " << std::endl;
}

Ice::Ice( Ice const & src ) : AMateria("ice")
{
    *this = src;
}

Ice&   Ice::operator=( const Ice& rhs ) {
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return *this;
}

Ice::~Ice()
{
    // std::cout << " Ice: ice is destroyed " << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void    Ice::use( ICharacter& target )
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}