#pragma once
#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"
#include "Cat.hpp"

class Dog : public Animal
{

private:
    Brain* brain;
    std::string _name;

public:
    Dog();
    virtual ~Dog();
    Dog(const std::string& Name);
    Dog& operator=(const Dog& _copy);
    Dog(const Dog& _copy);
    virtual void makeSound(void) const;

};

#endif