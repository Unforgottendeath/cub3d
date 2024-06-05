#include "../../include/cub3d.h"

int check_input(char *s1, char *s2, char **s3)
{
    char **buffer;
    int i;
    i = 0;
    buffer = ft_split(s1, ' ');
    if (!*buffer || !ft_strcmp(buffer[0], s2) || !buffer[1])
    {
        free_buffer(buffer, 1);
        return (0);
    }
    *s3 = ft_strdup(buffer[1]);
    free_buffer(buffer, 1);
    if (i > 2)
        return (0);
    return (1);
}

int check_directions(char **str, int *i, t_data *data)
{
    char *options[5];
    int count;

    data->counting = 0;
    count = 0;
    options[0] = "NO";
    options[1] = "SO";
    options[2] = "WE";
    options[3] = "EA";
    options[4] = NULL;
    while(str[*i] && options[count])
    {
        if (!check_input(str[(*i)++], options[count++], &data->directions[data->counting++]))
            return (0);
    }
    data->directions[data->counting] = 0;
    return (1);
}

int check_colors(char **str, int *i, t_data *data)
{
    char *options[3];
    int count;

    data->counting = 0;
    count = 0;
    options[0] = "F";
    options[1] = "C";
    options[2] = NULL;
    while(str[*i] && options[count])
    {
        if (!check_input(str[(*i)++], options[count++], &data->colors[data->counting++]))
            return (0);
    }
    data->colors[data->counting] = 0;
    data->counting = 0;
    return (1);
}

int verify_content(char **str, t_data *data)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (str[i])
    {
        while (str[i] && !str[i][0])
            i++;
        if (!count)
        {
            if (!check_directions(str, &i, data))
                return (0);
            count++;
            continue;
        }
        if (!check_colors(str, &i, data))
            return (0);
        break;
    }
    if (!check_map(str + i, data))
        return (0);
    return (1);
}