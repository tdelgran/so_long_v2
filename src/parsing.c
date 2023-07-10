#include "../include/so_long.h"

void	rectangular(t_game *game)
{
	int		i;
	size_t	line;

	i = 0;
	line = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != 0 && line != ft_strlen(game->map[i]))
			error(1);
		if (ft_strlen(game->map[i]) == 0 && game->map[i + 1] \
			&& ft_strlen(game->map[i + 1]) == 0)
			error(2);
	}
    i++;
}

void	wall(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[++y])
	{
		x = 0;
		while (game->map[y][++x])
		{
			if ((game->map[0][x] != '1' \
				|| game->map[game->y - 1][x] != '1') \
				&& game->map[0][x] != '\n')
				error(0);
			if (game->map[y][0] != '1' || game->map[y][game->x - 1] != '1')
				error(0);
		}
        x++;
	}
    y++;
}

void	character(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
				game->consum++;
			else if (game->map[y][x] == 'E')
				game->exit++;
			else if (game->map[y][x] == 'P')
				game->player++;
			else if (game->map[y][x] != '0' && game->map[y][x] != '1' \
				&& game->map[y][x] != '\n')
				the_error(6);
		}
	}
	if (game->consum < 1 || game->exit != 1 || game->player != 1)
		error(5);
}

void	parsing(t_game *game, char *av)
{
	int	*tab;

	map(av, game);
	declar_struct(game);
	rectangular(game);
	wall(game);
	character(game);
	mapcpy(game);
	tab = player(game);
	path(game, tab[0], tab[1]);
	checking_path(game);
	free(tab);
}