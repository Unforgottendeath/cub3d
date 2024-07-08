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

    //  returning by reference and not by value cause the class ostream prevent that
    /*
    However, we are not able to overload operator<< as a member function.
    Why not? Because the overloaded operator must be added as a member of the left operand. 
    In this case, the left operand is an object of type std::ostream. std::ostream is fixed as part of the standard library.
    We can’t modify the class declaration to add the overload as a member function of std::ostream.
    */
    friend std::ostream& operator<<(std::ostream& out, const Fixed& _object);

    //  returning by value cause we're returning a new object
    /*
    In the member function version, the expression cents1 + 2 becomes function call cents1.operator+(2).
    Note that there is now only one explicit function parameter, and cents1 has become an object prefix. 
    However, we mentioned that the compiler implicitly converts an object prefix into a hidden leftmost parameter named *this.
    So in actuality, cents1.operator+(2) becomes operator+(&​cents1, 2), which is almost identical to the friend version.
    */
    Fixed operator+(const Fixed& _f1);
    Fixed operator/(const Fixed& _f1);
    Fixed operator*(const Fixed& _f1);
    Fixed operator-(const Fixed& _f1);

    //  returning by value cause we're not changing any of the arguments
    int operator==(const Fixed& _f1);
    int operator<(const Fixed& _f1);
    int operator>(const Fixed& _f1);
    int operator<=(const Fixed& _f1);
    int operator>=(const Fixed& _f1);
    int operator!=(const Fixed& _f1);

    //  returning by reference cause we're modifyin the operand
    Fixed& operator++();
    Fixed& operator--();
    Fixed operator--(int);
    Fixed operator++(int);

    //  returning by ref 

    static const Fixed& min(const Fixed& _f1, const Fixed& _f2);
    static Fixed& min(Fixed& _f1, Fixed& _f2);
    static const Fixed& max(const Fixed& _f1,const  Fixed& _f2);
    static Fixed& max( Fixed& _f1,  Fixed& _f2);

};


#endif