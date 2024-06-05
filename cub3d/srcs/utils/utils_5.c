#include "../../include/cub3d.h"

void    free_and_exit(int exit_numb, t_data *data)
{
    int i;

    i = 0;
    free_buffer(data->map, 0);
    free_buffer(data->directions, 0);
    free_buffer(data->colors, 0);
    exit(exit_numb);
}

void    free_buffer(char **buffer, int flag)
{
    int i;

    i = 0;
    while (buffer[i])
        free(buffer[i++]);
    if (flag)
        free(buffer);
}