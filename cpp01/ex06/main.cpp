#include "Harl.hpp"

int main(const int ac, const char **av)
{
    if (ac == 2)
    {
        HarlFilter(av[1]);
    }
    else
    {
        std::cerr << "Invalid number of arguments !\n";
        return (1);
    }
    return (0);
}