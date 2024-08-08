#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string _name) : type(_name)
{
    std::cout << "WrongAnimal (" << _name << ") constructed !\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal (" << this->type << ") Destructed !\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& _copy)
{
    std::cout << "WrongAnimal copy assignment operator called !\n";
    if (this == &_copy)
        return *this;
    type = _copy.type;
    return *this;
}

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal (" << "WrongAnimal) constructed !\n" ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& _copy)
{
    *this = _copy;
}

void WrongAnimal::makeSound() const
{
    std::cout << "???? \n";
}

const std::string& WrongAnimal::getType() const
{
    return (type);
}