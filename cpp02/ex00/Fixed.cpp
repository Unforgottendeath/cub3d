#include "Fixed.hpp"

int     Fixed::getRawBits( void) const
{
    std::cout << "getRawBits member function called\n";
    return fixed_point_nb;
}

void    Fixed::setRawBits( int const raw)
{
    fixed_point_nb = raw;
}

Fixed::Fixed(void) : fixed_point_nb(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& _copy)
{
    std::cout << "Copy constructor called\n";
    *this = _copy;
}

Fixed& Fixed::operator=(const Fixed& _copy)
{
    std::cout << "Copy assignment operator called" << "\n";
    fixed_point_nb = _copy.getRawBits();
    return *this;
}