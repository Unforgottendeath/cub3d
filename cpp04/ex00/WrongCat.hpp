#pragma once
#ifndef __WRONGCAT_H__
#define __WRONGCAT_H__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    ~WrongCat();
    WrongCat& operator=(const WrongCat& _copy);
    WrongCat(const WrongCat& _copy);
    void makeSound() const;
};

#endif