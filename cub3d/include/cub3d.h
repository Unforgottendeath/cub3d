#ifndef CUB3D_H
#define CUB3D_H

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 42

typedef struct s_player
{
    double      i;
    double      j;
    double      pdi;
    double      pdj;
    double      pa;
    char    orientation;
}t_player;

typedef struct s_data
{
    char        *map[4096];
    char        *directions[5];
    char        *no;
    char        *so;
    char        *ew;
    char        *ea;
    int         counting;
    char        *colors[3];
    t_player    player;
}t_data;

// utils

int ft_strcmp(char *s1, char *s2);
size_t ft_strlen(char *str);
void	read_and_update_buffer(char **buffer, ssize_t *bytes, int fd,
		char **new_buffer);
int	ft_memchr_line(char *s, char c);
char	*ft_strdup_line(const char *s1, int j);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void    get_map(char *str, t_data *data);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void    free_and_exit(int exit_numb, t_data *data);
char	**ft_split(char const *str, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char *str);
void    free_buffer(char **buffer, int flag);

// parsing

int verify_extension(char *arg);
int verify_content(char **str, t_data *data);
int check_map(char **str, t_data *data);
int correct_map(char *argument, t_data *data);

// gameplay


#endif
