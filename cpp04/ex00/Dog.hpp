#pragma once
#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"
#include "Cat.hpp"

class Dog : public Animal
{

public:
    Dog();
    ~Dog();
    Dog& operator=(const Dog& _copy);
    Dog(const Dog& _copy);
    virtual void makeSound(void) const;

};

#endif