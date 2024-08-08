#include "Animal.hpp"

Animal::Animal(const std::string _name) : type(_name)
{
    std::cout << "Animal (" << _name << ") constructed !\n";
}

Animal::~Animal()
{
    std::cout << "Animal (" << this->type << ") Destructed !\n";
}

Animal& Animal::operator=(const Animal& _copy)
{
    std::cout << "Animal copy assignment operator called !\n";
    if (this == &_copy)
        return *this;
    type = _copy.type;
    return *this;
}

Animal::Animal() : type("Animal")
{
    std::cout << "Animal (" << "Animal) constructed !\n" ;
}

Animal::Animal(const Animal& _copy)
{
    *this = _copy;
}

void Animal::makeSound() const
{
    std::cout << "???? \n";
}

const std::string& Animal::getType() const
{
    return (type);
}