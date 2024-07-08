#pragma once
#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>
#include <string>

class Animal
{

protected:
    std::string type;

public:
    Animal(const std::string _name = "Animal");
    ~Animal();
    Animal& operator=(const Animal& _copy);
    Animal(const Animal& _copy);
    virtual void makeSound() const;
    const std::string& getType (void) const;

};

#endif