#pragma once
#ifndef __CAT_H__
#define __CAT_H__

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{

private :
    Brain* brain;
    std::string _name;

public:
    Cat();
    virtual ~Cat();
    Cat(const std::string& Name);
    Cat& operator=(const Cat& _copy);
    Cat(const Cat& _copy);
    virtual void makeSound() const;
    
};

#endif