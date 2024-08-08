#pragma once
#ifndef __WRONGANIMAL_H__
#define __WRONGANIMAL_H__

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal(const std::string _name);
    ~WrongAnimal();
    WrongAnimal();
    WrongAnimal& operator=(const WrongAnimal& _copy);
    WrongAnimal(const WrongAnimal& _copy);
    void makeSound() const;
    const std::string& getType (void) const;
};

#endif