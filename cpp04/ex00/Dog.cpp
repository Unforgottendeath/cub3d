#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog (" << type << ") constructed !\n";
}

Dog::~Dog()
{
    std::cout << "Dog (" << this->type << ") Destructed !\n";
}

Dog& Dog::operator=(const Dog& _copy)
{
    std::cout << "Dog copy assignment operator called !\n";
    if (this == &_copy)
        return *this;
    type = _copy.type;
    return *this;
}

Dog::Dog(const Dog& _copy) : Animal(_copy.type)
{
    *this = _copy;
}

void Dog::makeSound() const
{
    std::cout << "Bark \n";
}