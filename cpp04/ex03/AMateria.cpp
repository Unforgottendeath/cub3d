#include "AMateria.hpp"

AMateria::AMateria( void ) : type("")
{
    // std::cout << "AMateria ("<< this->type << ") is created " << std::endl;
}

AMateria::AMateria( std::string const & Type )  : type(Type)
{
    // std::cout << "AMateria (" << this->type << ") is created" << std::endl;
}

AMateria::AMateria( AMateria const & src )
{
    *this = src;
}

AMateria::~AMateria( void )
{
    // std::cout << "AMateria (" << this->type << ") destroyed" << std::endl;
}

std::string const & AMateria::getType() const
{
    return this->type;
}

AMateria* AMateria::clone() const
{
    return (AMateria*)this;
}

void    AMateria::use( ICharacter& target )
{
    std::cout << "AMateria " << this->type << " used on " << target.getName() << std::endl;
}