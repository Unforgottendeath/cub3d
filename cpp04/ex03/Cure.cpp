#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure constructed !\n"; 
}

Cure::Cure(const Cure& _copy)
{
    std::cout << "Inside Cure copy constructor !\n";
    this->type = _copy.type;
}

Cure& Cure::operator=(const Cure& _copy)
{
    std::cout << "Inside Brain copy assignment operator !\n";
    if (this == &_copy)
        return *this;
    this->type = _copy.type;
    return *this;
}
AMateria* Cure::clone() const
{
    return new Cure;
}

Cure::~Cure()
{
    std::cout << "Cure destructed !\n";
}