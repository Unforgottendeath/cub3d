#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure constructed !\n"; 
}

Cure::Cure(const Cure& _copy)
{
    std::cout << "Inside Cure copy constructor !\n";
    this->type = _copy.type;
}

Cure& Cure::operator=(const Cure& _copy)
{
    std::cout << "Inside Brain copy assignment operator !\n";
    if (this == &_copy)
        return *this;
    this->type = _copy.type;
    return *this;
}
AMateria* Cure::clone() const
{
    return new Cure;
}

Cure::~Cure()
{
    std::cout << "Cure destructed !\n";
}

/*
#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
    // std::cout << "* Cure: materia is created *" << std::endl;
}

Cure::Cure( Cure const & src ) : AMateria("cure")
{
    *this = src;
    // std::cout << "* Cure: materia is copied *" << std::endl;
}

Cure&   Cure::operator=( const Cure& rhs ) {
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}

Cure::~Cure()
{
    // std::cout << "* Ice: cure is destroyed *" << std::endl;
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void    Cure::use( ICharacter& target )
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
*/