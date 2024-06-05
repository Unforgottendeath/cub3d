#include "include/cub3d.h"

int main(int ac, char **av)
{
    t_data  data;

    data.colors[0] = 0;
    data.directions[0] = 0;
    if (ac == 2)
    {
        if (!correct_map(av[1], &data))
            free_and_exit(1, &data);
    }
    else
    {
        return (write(2, "Error\nEnter a valid number of argument\n", 40), 1);
    }
    free_and_exit(0, &data);
}