#include "Fixed.hpp"

int     Fixed::getRawBits( void) const
{
    // std::cout << "getRawBits member function called\n";
    return (fixed_point_nb >> nb_bits);
}

void    Fixed::setRawBits( int const raw)
{
    fixed_point_nb = raw * ( 1 << nb_bits);
}

Fixed::Fixed(void)
{
    // std::cout << "Default constructor called\n";
    fixed_point_nb = 0;
}

Fixed::Fixed (const int _param) : fixed_point_nb (roundf(_param * (float)(1 << nb_bits)))
{
    // std::cout << "Int constructor called\n";
}

Fixed::Fixed (const float _param) : fixed_point_nb (roundf(_param * (float)(1 << nb_bits)))
{
    // std::cout << "Float constructor called\n";
    
}

float   Fixed::toFloat( void ) const
{
    return fixed_point_nb / (float)(1 << nb_bits);
}

int     Fixed::toInt( void) const
{
    return (fixed_point_nb >> 8);
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& _copy)
{
    // std::cout << "Copy constructor called\n";
    *this = _copy;
}


Fixed& Fixed::operator=(const Fixed& _copy)
{
    // std::cout << "Copy assignment operator called" << "\n";
    if (this == &_copy)
        return *this;
    fixed_point_nb = _copy.fixed_point_nb;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& _object)
{
    out << _object.fixed_point_nb / (float)(1 << _object.nb_bits);
    return out;
}

Fixed Fixed::operator-(const Fixed& _f1)
{
    return Fixed(this->toFloat() - _f1.toFloat());
}

Fixed Fixed::operator/(const Fixed& _f1)
{
    return Fixed(this->toFloat() / _f1.toFloat());
}

Fixed Fixed::operator+(const Fixed& _f1)
{
    return Fixed(this->toFloat() + _f1.toFloat());
}

Fixed Fixed::operator*(const Fixed& _f1)
{
    return Fixed(this->toFloat() * _f1.toFloat());
}

int Fixed::operator<(const Fixed& _f1)
{
    return (this->toFloat() < _f1.toFloat());
}

int Fixed::operator>(const Fixed& _f1)
{
    return (this->toFloat() > _f1.toFloat());
}

int Fixed::operator<=(const Fixed& _f1)
{
    return (this->toFloat() <= _f1.toFloat());
}

int Fixed::operator>=(const Fixed& _f1)
{
    return (this->toFloat() >= _f1.toFloat());
}

int Fixed::operator!=(const Fixed& _f1)
{
    return (this->toFloat() != _f1.toFloat());
}

int Fixed::operator==(const Fixed& _f1)
{
    return (this->toFloat() == _f1.toFloat());
}

Fixed& Fixed::operator++()
{
    ++fixed_point_nb;
    return *this;
}

Fixed& Fixed::operator--()
{
    --fixed_point_nb;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --(*this);
    return temp;
}

const Fixed& Fixed::min(const Fixed& _f1, const Fixed& _f2)
{
    return (_f1.fixed_point_nb < _f2.fixed_point_nb ? _f1 : _f2);
}

Fixed& Fixed::min(Fixed& _f1, Fixed& _f2)
{
    return (_f1.fixed_point_nb < _f2.fixed_point_nb ? _f1 : _f2);
}


const Fixed& Fixed::max(const Fixed& _f1, const Fixed& _f2)
{
    return (_f1.fixed_point_nb > _f2.fixed_point_nb ? _f1 : _f2);
}

Fixed& Fixed::max(Fixed& _f1, Fixed& _f2)
{
    return (_f1.fixed_point_nb > _f2.fixed_point_nb ? _f1 : _f2);
}