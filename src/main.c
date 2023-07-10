#include "../include/so_long.h"

void	check_extension(char *ber)
{
	int	i;

	i = ft_strlen(ber);
	if ((ber[i - 4] != '.') || (ber[i - 3] != 'b') || (ber[i - 2] != 'e') \
		|| (ber[i - 1] != 'r'))
		error (4);
}

void	error(int error)
{
	if (error == 0)
		ft_printf("Error\nnot walls\n");
	if (error == 1)
		ft_printf("Error\nnot rectangular map\n");
	if (error == 2)
		ft_printf("Error\ninvalid map\n");
	if (error == 3)
		ft_printf("Error\narguments\n");
	if (error == 4)
		ft_printf("Error\nnot good file\n");
	if (error == 5)
		ft_printf("Error\ninvalid char\n");
	if (error == 6)
		ft_printf("Error\nYou are not char\n");
	if (error == 7)
		ft_printf("Error\nproblem path\n");
	if (error == 8)
		ft_printf("Error\nmap\n");
	exit(EXIT_FAILURE);
}

int	loop(t_game *game)
{
	set_image(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		error(3);
	check_extension(av[1]);
	init_struc(&game);
	parsing(&game, av[1]);
	start_window(&game);
	mlx_loop_hook(game.mlxwin, &loop, &game);
	mlx_hook(game.window, 2, 0, &key_code, &game);
	mlx_loop(game.mlxwin);
}