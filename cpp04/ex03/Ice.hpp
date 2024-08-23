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

/*
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{

    public:
        Ice();
        ~Ice();

        Ice( Ice const & );
        Ice& operator=( Ice const & );

        virtual AMateria*   clone() const;
        virtual void        use(ICharacter& target);
};

#endif // ICE_HPP
*/