#include "../../include/cub3d.h"

int is_orientation(char c)
{
    char    *str;
    int     i;

    i = 0;
    str = "NSEW";
    while (str[i])
    {
        if (str[i++] == c)
            return (1);
    }
    return (0);
}

int check_partline(t_data *data, char **buffer)
{
    int i;
    size_t j;

    i = 0;
    while (buffer[i])
    {
        j = 0;
        while (buffer[i][j])
        {
            if ((j == 0 || j == (ft_strlen(buffer[i]) - 1)) && buffer[i][j] != '1')
                return (0);
            else
            {
                if (buffer[i][j] != '1' && buffer[i][j] != '0' && !is_orientation(buffer[i][j]))
                    return (0);
                if (is_orientation(buffer[i][j]))
                    data->counting++;
            }
            j++;
        }
        i++;
    }
    return (1);
}

void check_line(char *str, int *check, t_data *data)
{
    int     i;
    char    **buffer;
    int     j;

    buffer = ft_split(str, ' ');
    i = 0;
    if (!*check)
    {
        while (buffer[i])
        {
            j = 0;
            while (buffer[i][j])
            {
                if (buffer[i][j++] != '1')
                    *check = 2;
            }
            i++;
        }
        *check = 1;
    }
    else if (*check)
    {
        if (!check_partline(data, buffer))
            *check = 2;
    }
    free_buffer(buffer, 1);
}

int check_map(char **str, t_data *data)
{
    int     i;
    int     check;

    i = 0;
    while (str[i] && !str[i][0])
        i++;
    if (!str[i])
        return (0);
    check = 0;
    while (str[i] && str[i][0] && check < 2)
    {
        check_line(str[i], &check, data);
        i++;
        if (str[i + 1] && !str[i + 1][0])
            check = 0;
    }
    while (str[i] && !str[i][0])
        i++;
    if (str[i] || check == 2 || data->counting != 1)
        return (0);
    return (1);
}