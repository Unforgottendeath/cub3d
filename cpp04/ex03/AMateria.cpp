#include "AMateria.hpp"

AMateria::AMateria(const std::string& Type) : type(Type)
{
    std::cout << "AMateria (" << Type << ") constructed !\n";
}

std::string const & AMateria::getType() const
{
    return type;
}