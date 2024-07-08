#include "Point.hpp"

Point::Point( void ) : x(0), y(0) {
    // std::cout << "Point created" << std::endl;
}

Point::Point( const float x, const float y ) : x(x), y(y) {
    // std::cout << "Point created" << std::endl;
}

Point::Point( const Point &src ) : x(src.x), y(src.y) {
    // std::cout << "Point created" << std::endl;
}

Point::~Point() {
    // std::cout << "Point destroyed" << std::endl;
}

Point&  Point::operator=( const Point &rhs ) {
    if ( this != &rhs ) {
        ( Fixed ) this->x = rhs.getX();
        ( Fixed ) this->y = rhs.getY();
    }
    return *this;
}

Fixed Point::getX( void ) const {
    return this->x;
}

Fixed Point::getY( void ) const {
    return this->y;
}