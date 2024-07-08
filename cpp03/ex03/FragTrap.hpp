#pragma once
#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

public:
    FragTrap(const std::string& _name);
    FragTrap(const FragTrap& _copy);
    FragTrap& operator=(const FragTrap& _copy);
    ~FragTrap();
    void highFiveGuys(void);
};


#endif