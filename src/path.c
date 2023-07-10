#include "../include/so_long.h"

void	path(t_game *game, int y, int x)
{
	if (game->secondmap[y][x] == 'C')
		game->consumcpy++;
	if (game->secondmap[y][x] == 'E')
	{
		game->exitcpy = 1;
		game->secondmap[y][x] = '1';
		return ;
	}
	game->secondmap[y][x] = '1';
	if (x + 1 < game->x && game->secondmap[y][x + 1] != '1')
		path(game, y, x + 1);
	if (x - 1 >= 0 && game->secondmap[y][x - 1] != '1')
		path(game, y, x - 1);
	if (y + 1 < game->y && game->secondmap[y + 1][x] != '1')
		path(game, y + 1, x);
	if (y - 1 >= 0 && game->secondmap[y - 1][x] != '1')
		path(game, y - 1, x);
}

void	checking_path(t_game *game)
{
	if (game->consumcpy != game->consum || game->exitcpy == 0)
		error(7);
}

int	secondmap(t_game *game)
{
	int	x;
	int	y;

	game->secondmap = ft_calloc(game->line.y + 1, (sizeof(char *)));
	if (!game->secondmap)
		return (0);
	x = 0;
	while (x < game->line.y)
	{
		game->secondmap[x] = ft_calloc(game->line.x + 1, sizeof(char));
		if (!game->secondmap)
			return (0);
		y = -1;
		while (game->map[x][++y])
			game->secondmap[x][y] = game->map[x][y];
		x++;
	}
	return (1);
}

int	*search_player(t_game *game)
{
	int	*tab;
	int	x;
	int	y;

	tab = malloc(sizeof(int) * 2);
	y = -1;
	while (game->secondmap[++y])
	{
		x = -1;
		while (game->secondmap[y][++x])
		{
			if (game->secondmap[y][x] == 'P')
			{
				tab[0] = y;
				tab[1] = x;
				game->player_posx = x;
				game->player_posy = y;
				return (tab);
			}
		}
	}
	return (NULL);
}
