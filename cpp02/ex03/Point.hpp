#pragma once
#ifndef __POINT_HPP__
# define __POINT_HPP__

#include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;

public:
    Point();
    Point( const float x, const float y );
    Point( const Point &_copy );
    ~Point();

    Point&  operator=( const Point &_copy );

    Fixed getX( void ) const ;
    Fixed getY( void ) const ;
    
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif 