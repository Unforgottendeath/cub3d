#include "Sed.hpp"

int main(const int ac, const char **av)
{
    if (ac == 4 && *av[2]){
        Sed mini_sed(av[1], av[2], av[3]);
        mini_sed.Replace();
    }
    else{
        std::cerr << "arg1 = filename arg2 = non empty string to be replaced  arg3 = string to replace with !" << "\n";
        return (1);
    }
    return (0);
}