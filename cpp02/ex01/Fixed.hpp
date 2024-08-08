#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{

private:
    int                 fixed_point_nb;
    const static int    nb_bits = 8;

public:
    Fixed();
    Fixed(const Fixed& _copy);
    Fixed(const int _param);
    Fixed(const float _param);
    float toFloat( void ) const;
    int   toInt( void) const;
    Fixed& operator=(const Fixed& _copy);
    ~Fixed();
    int     getRawBits( void) const;
    void    setRawBits( int const raw );

};
std::ostream& operator<<(std::ostream& out, const Fixed& _object);


#endif