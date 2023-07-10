#include "../include/so_long.h"

void	*img(t_game *game, char *img)
{
	int		img_w;
	int		img_h;
	void	*image;

	image = mlx_xpm_file_to_image(game->mlxwin, img, &img_w, &img_h);
	if (!image)
		error(4);
	return (image);
}

void	start_window(t_game *game)
{
	game->mlxwin = mlx_init();
	game->window = mlx_new_window(game->mlxwin, game->x * 64, \
		game->y * 64, "So_long");
	game->floor = img(game, "./xpm/floor.xpm");
	game->character = img(game, "./xpm/char.xpm");
	game->wall = img(game, "./xpm/wall.xpm");
	game->object = img(game, "./xpm/object.xpm");
	game->f_exit = img(game, "./xpm/f_exit.xpm");
}

void	player_move(t_game *game)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	mlx_put_image_to_window(game->mlxwin, game->window, \
		game->character, x * 64, y * 64);
}

void	set_image(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '0' || game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlxwin, game->window, \
					game->floor, x * 64, y * 64);
			else if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlxwin, game->window, \
					game->wall, x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlxwin, game->window, \
					game->object, x * 64, y * 64);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlxwin, game->window, \
					game->f_exit, x * 64, y * 64);
		}
	}
	player_move(game);
}
