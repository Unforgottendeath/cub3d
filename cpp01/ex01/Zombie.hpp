#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>
#include <string>

class Zombie {

private:

     std::string _name;

public:

    Zombie(std::string name = "");
    ~Zombie();
    void     announce(void) ;
};

Zombie* zombieHorde( int N, std::string name );

#endif