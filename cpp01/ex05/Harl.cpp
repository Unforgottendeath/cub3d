#include "Harl.hpp"

int     get_index(std::string level)
{
    int i = 0;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while (i < 4)
    {
        if (!level.compare(levels[i]))
            return (i);
        i++;
    }
    return i;
}

void    Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
        << "ketchup burger. I really do!" << "\n\n";
}

void    Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put" <<
        "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << "\n\n";
}

void    Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for" << 
        "years whereas you started working here since last month." << "\n\n";
}

void    Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << "\n\n";
}

void    Harl::complain(std::string level)
{
    fct_ptr _Harl[5] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, NULL};
    fct_ptr func = _Harl[get_index(level)];
    if (func != NULL)
        (this->*func)();
}