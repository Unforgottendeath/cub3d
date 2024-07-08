#pragma once
#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.hpp"

class Cat : public Animal
{

public:
    Cat();
    ~Cat();
    Cat& operator=(const Cat& _copy);
    Cat(const Cat& _copy);
    virtual void makeSound() const;
    
};

#endif