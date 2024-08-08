#include "Point.hpp"

int main( void ) {
Point a(0, 0);
Point b(20, 0);
Point c(10 , 30);
Point point(10 , 0);
std::cout << std::boolalpha;   
std::cout << bsp(a, b, c, point) << std::endl;
return 0;
}