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

/*
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        ~Cure();

        Cure( Cure const & );
        Cure& operator=( Cure const & );

        virtual AMateria*   clone() const;
        virtual void        use(ICharacter& target);
};

#endif // CURE_HPP
*/