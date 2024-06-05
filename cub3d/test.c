#include "include/cub3d.h"
#include <math.h>
#define DIMENSION 64
#define mapWidth 24
#define mapHeight 24
#define screenWidth (mapWidth * DIMENSION)
#define screenHeight (mapHeight * DIMENSION)
#define PI 3.1415926535
typedef struct s_image
{
    void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}   t_image;

typedef struct	s_pata {
	void	    *mlx;
    void        *win;
    t_image       background;
    t_image       player;
    t_image       line;
    t_player    player_pos;
}				t_pata;


int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,6,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
void    draw_cube(t_image *data, int x, int y, int color)
{
    int i = 0;
    while (i < 62)
    {
        int j = 0;
        while (j < 62)
        {
            my_mlx_pixel_put(data, x+i, y+j, color);
            j++;
        }
        i++;
    }
}
int key_hook(int keycode, t_pata *data)
{
    if (keycode == 65363 && worldMap[(int)((data->player_pos.i) / 64)][(int)((data->player_pos.j + 64) / 64)] == 0)
        data->player_pos.j += 5;
    else if (keycode == 65361 && worldMap[(int)((data->player_pos.i) / 64)][(int)((data->player_pos.j - 64) / 64)] == 0)
        data->player_pos.j -= 5;
    else if (keycode == 65362 && worldMap[(int)((data->player_pos.i - 64) / 64)][(int)((data->player_pos.j) / 64)] == 0)
        data->player_pos.i -= 5;
    else if (keycode == 65364 && worldMap[(int)((data->player_pos.i + 64) / 64)][(int)((data->player_pos.j) / 64)] == 0)
        data->player_pos.i += 5;
    mlx_put_image_to_window(data->mlx, data->win, data->background.img, 0, 0);
    mlx_put_image_to_window(data->mlx, data->win, data->player.img, data->player_pos.j , data->player_pos.i );
    return (0);
}

int movement(t_pata *data)
{
    mlx_hook(data->win, 3, 1L << 1, key_hook, data);
    return (0);
}
void    draw_line(t_image *data, int x, int y, int color)
{
    int i = 0;
    while (i < 12)
    {
        int j = 0;
        while (j < 32)
        {
            my_mlx_pixel_put(data, x+i, y+j, color);
            j++;
        }
        i++;
    }
}
int	main(void)
{
	t_pata	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, screenWidth, screenHeight, "Hello world!");
	data.background.img = mlx_new_image(data.mlx, screenWidth, screenHeight);
	data.background.addr = mlx_get_data_addr(data.background.img, &data.background.bpp, &data.background.line_length,
								&data.background.endian);
    int i = 0;
    while (i < mapHeight)
    {
        int j = 0;
        while (j < mapWidth)
        {
            if (worldMap[i][j] != 0 && worldMap[i][j] != 6)
                draw_cube(&data.background, j * 64, i * 64 , 0x00FFFFFF);
            else
                draw_cube(&data.background, j * 64 , i * 64 , 0x00000000);
            j++;
        }
        i++;
    }
    data.player.img = mlx_new_image(data.mlx, 64, 64);
	data.player.addr = mlx_get_data_addr(data.player.img, &data.player.bpp, &data.player.line_length,
								&data.player.endian);
    data.line.img = mlx_new_image(data.mlx, 12, 32);
	data.line.addr = mlx_get_data_addr(data.line.img, &data.line.bpp, &data.line.line_length,
								&data.line.endian);
    i = 0;
    int flag = 0;
    int j;
    draw_line(&data.line, 0, 0, 0x00FF0000);
    while (i < mapHeight)
    {
        j = 0;
        while (j < mapWidth)
        {
            if (worldMap[i][j] == 6)
            {
                draw_cube(&data.player,0, 0, 0x00FFFF00);
                flag = 1;
                break;
            }
            j++;
        }
        if(flag)
            break;
        i++;
    }
    data.player_pos.i = i *64;
    data.player_pos.j = j * 64;
	mlx_put_image_to_window(data.mlx, data.win, data.background.img, 0, 0);
    mlx_put_image_to_window(data.mlx, data.win, data.player.img, data.player_pos.j, data.player_pos.i);
    mlx_put_image_to_window(data.mlx, data.win, data.line.img, data.player_pos.j, data.player_pos.i);
    movement(&data);
	mlx_loop(data.mlx);
}
