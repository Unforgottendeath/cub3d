#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat (" << type << ") constructed !\n";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat (" << this->type << ") Destructed !\n";
}

WrongCat& WrongCat::operator=(const WrongCat& _copy)
{
    std::cout << "WrongCat copy assignment operator called !\n";
    if (this == &_copy)
        return *this;
    type = _copy.type;
    return *this;
}

WrongCat::WrongCat(const WrongCat& _copy) : WrongAnimal(_copy.type)
{
    *this = _copy;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow \n";
}