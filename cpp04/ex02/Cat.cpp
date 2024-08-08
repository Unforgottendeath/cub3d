#include "Cat.hpp"

Cat::Cat() : Animal("Cat") , brain(new Brain) , _name((""))
{
    std::cout << "Cat (" << _name << ") constructed !\n";
}

Cat::Cat(const std::string& name) : Animal("Cat"), brain(new Brain), _name(name)
{
    std::cout << "Cat (" << _name << ") constructed !\n";
}

Cat::~Cat()
{
    delete brain;
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