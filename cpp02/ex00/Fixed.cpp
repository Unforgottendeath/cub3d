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

Fixed::Fixed(void)
{
    std::cout << "Default constructor called\n";
    fixed_point_nb = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& _copy)
{
    std::cout << "Copy constructor called\n";
    fixed_point_nb = _copy.fixed_point_nb;
}

Fixed& Fixed::operator=(const Fixed& _copy)
{
    std::cout << "Copy assignment operator called" << "\n";
    return *this;
}