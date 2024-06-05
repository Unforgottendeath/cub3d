#include "../../include/cub3d.h"

int verify_extension(char *arg)
{
    int i;

    i = 0;
    if (ft_strlen(arg) <= 4)
        return (0);
    return (ft_strcmp(arg + ft_strlen(arg) - 4, ".cub"));
}

int correct_map(char *argument, t_data *data)
{
    if (!verify_extension(argument))
        return (write(2, "Error\nEnter a valid map file\n", 30), 0);
    get_map(argument, data);
    if (!verify_content(data->map, data))
        return (write(2, "Invalid map struction\n", 23), 0);
    return (1);
}
