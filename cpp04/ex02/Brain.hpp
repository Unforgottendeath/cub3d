#pragma once
#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <iostream>
#include <string>

class Brain
{

private:
    std::string ideas[100];

public:
    Brain();
    ~Brain();
    Brain(const Brain& _copy);
    Brain& operator=(const Brain& _copy);
};


#endif