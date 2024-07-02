#pragma once
#ifndef __HARL_H__
#define __HARL_H__

#include <iostream>
#include <string>
#include <stddef.h>

class Harl
{

private:
    void    debug( void );
    void    info( void);
    void    warning( void );
    void    error( void );

public:
    void complain( std::string level );
};

typedef void (Harl::*fct_ptr) (void);

int get_index(std::string level);

#endif