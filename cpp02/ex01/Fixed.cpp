#include "Fixed.hpp"

int     Fixed::getRawBits( void) const
{
    std::cout << "getRawBits member function called\n";
    return (fixed_point_nb >> nb_bits);
}

void    Fixed::setRawBits( int const raw)
{
    fixed_point_nb = raw * ( 1 << nb_bits);
}

Fixed::Fixed(void):fixed_point_nb(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed (const int _param)
{
    setRawBits(_param);
    std::cout << "Int constructor called\n";
}

Fixed::Fixed (const float _param)
{
    std::cout << "Float constructor called\n";
    fixed_point_nb = roundf(_param * (float)(1 << nb_bits));
}

float   Fixed::toFloat( void ) const
{
    return fixed_point_nb / (float)(1 << nb_bits);
}

int     Fixed::toInt( void) const
{
    return (fixed_point_nb >> nb_bits);
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
    (void)_copy;
    std::cout << "Copy assignment operator called" << "\n";
    fixed_point_nb = _copy.fixed_point_nb;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& _object)
{
    out << _object.toFloat();
    return out;
}