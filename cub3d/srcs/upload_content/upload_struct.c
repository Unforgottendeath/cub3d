#include "../../include/cub3d.h"

void    get_map(char *string, t_data *data)
{
    int     fd;
    int     i;
    char    *str;

    i = 0;
    fd = open(string, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error\n", 7);
        perror(string);
        exit(1);
    }
    str = ft_substr(get_next_line(fd));
    while (str)
    {
        data->map[i++] = str;
        str = ft_substr(get_next_line(fd));
    }
    data->map[i] = str;
}