#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat (" << type << ") constructed !\n";
}

Cat::~Cat()
{
    std::cout << "Cat (" << this->type << ") Destructed !\n";
}

Cat& Cat::operator=(const Cat& _copy)
{
    std::cout << "Cat copy assignment operator called !\n";
    if (this == &_copy)
        return *this;
    type = _copy.type;
    return *this;
}

Cat::Cat(const Cat& _copy) : Animal(_copy.type)
{
    *this = _copy;
}

void Cat::makeSound() const
{
    std::cout << "Meow \n";
}