#pragma once
#ifndef __ICE_HPP__
#define __ICE_HPP__

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        AMateria* clone (void) const override;
        Ice();
        virtual ~Ice();
};

#endif