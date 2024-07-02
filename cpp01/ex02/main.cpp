#include <iostream>
#include <string>

int main(void)
{
    std::string     _string     = "HI THIS IS BRAIN";
    std::string*    ptr_string  = &_string;
    std::string&    ref_string  = _string;
    std::cout << &_string << "\n";
    std::cout << ptr_string << "\n";
    std::cout << &ref_string << "\n";
    std::cout << _string << "\n";
    std::cout << *ptr_string << "\n";
    std::cout << ref_string << "\n";
}