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

void    HarlFilter(std::string level)
{
    Harl    harl_filter;
    int     index = get_index(level);
    switch (index)
    {
    case 0:
        harl_filter.complain("DEBUG");
        break;
    
    case 1:
        harl_filter.complain("INFO");
        break;

    case 2:
        harl_filter.complain("WARNING");
        break;

    case 3:
        harl_filter.complain("ERROR");
        break;

    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << "\n";

    }
}
void    Harl::debug()
{
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
        << "ketchup burger. I really do!" << "\n\n";
}

void    Harl::info()
{
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put" <<
        "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << "\n\n";
}

void    Harl::warning()
{
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for" << 
        "years whereas you started working here since last month." << "\n\n";
}

void    Harl::error()
{
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << "\n\n";
}

void    Harl::complain(std::string level)
{
    int     index   = get_index(level);
    fct_ptr func ;

    fct_ptr _Harl[5] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, NULL};
    while ( index < 4 )
    {
        func = _Harl[index++];
        (this->*func)();
    }
}