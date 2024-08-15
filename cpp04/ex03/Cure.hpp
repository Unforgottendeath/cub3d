#pragma once
#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        AMateria* clone (void) const override;
        Cure();
        virtual ~Cure();
        Cure(const Cure& _copy);
        Cure& operator=(const Cure& _copy);
};

#endif