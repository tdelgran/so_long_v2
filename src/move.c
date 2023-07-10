#include "../include/so_long.h"

void	w(t_game *game)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	if (game->map[y - 1][x] == '1' || (game->map[y - 1][x] == 'E' \
		&& game->consum > 0))
		return ;
	else
	{
		if (game->map[y - 1][x] == 'C')
			game->consum--;
		else if (game->map[y - 1][x] == 'E' && game->consum == 0)
			exit(EXIT_SUCCESS);
		game->map[y - 1][x] = 'p';
		game->map[y][x] = '0';
	}
	game->step += 1;
	ft_printf("%d\n", game->step);
	game->player_posy = y - 1;
}

void	s(t_game *game)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	if (game->map[y + 1][x] == '1' || (game->map[y + 1][x] == 'E' \
		&& game->consum > 0))
		return ;
	else
	{
		if (game->map[y + 1][x] == 'C')
			game->consum--;
		else if (game->map[y + 1][x] == 'E' && game->consum == 0)
			exit(EXIT_SUCCESS);
		game->map[y + 1][x] = 'p';
		game->map[y][x] = '0';
	}
	game->step += 1;
	ft_printf("%d\n", game->step);
	game->player_posy = y + 1;
}

void	a(t_game *game)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	if (game->map[y][x - 1] == '1' || (game->map[y][x - 1] == 'E' \
		&& game->consum > 0))
		return ;
	else
	{
		if (game->map[y][x - 1] == 'C')
			game->consum--;
		else if (game->map[y][x - 1] == 'E' && game->consum == 0)
			exit(EXIT_SUCCESS);
		game->map[y][x - 1] = 'p';
		game->map[y][x] = '0';
	}
	game->step += 1;
	ft_printf("%d\n", game->step);
	game->player_posx = x - 1;
}

void	d(t_game *game)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	if (game->map[y][x + 1] == '1' || (game->map[y][x + 1] == 'E' \
		&& game->consum > 0))
		return ;
	else
	{
		if (game->map[y][x + 1] == 'C')
			game->consum--;
		else if (game->map[y][x + 1] == 'E' && game->consum == 0)
			exit(EXIT_SUCCESS);
		game->map[y][x + 1] = 'p';
		game->map[y][x] = '0';
	}
	game->step += 1;
	ft_printf("%d\n", game->step);
	game->player_posx = x + 1;
}

int	key_code(int key_code, t_game *game)
{
	if (key_code == KEY_ECHAP)
		exit(EXIT_SUCCESS);
	if (key_code == KEY_W)
		w(game);
	if (key_code == KEY_S)
		s(game);
	if (key_code == KEY_A)
		a(game);
	if (key_code == KEY_D)
		d(game);
	return (0);
}