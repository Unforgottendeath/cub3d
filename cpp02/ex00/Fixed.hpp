#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
#include <string>

class Fixed
{

private:
    int                 fixed_point_nb;
    const static int    nb_bits = 8;

public:
    Fixed();
    Fixed(const Fixed& _copy);
    Fixed& operator=(const Fixed& t);
    ~Fixed();
    int     getRawBits( void) const;
    void    setRawBits( int const raw );

};

#endif