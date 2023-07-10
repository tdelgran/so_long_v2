#include "../include/so_long.h"

void	init_struc(t_game *game)
{
	game->map = NULL;
	game->line.x = 0;
	game->line.y = 0;
	game->y = 0;
	game->x = 0;
	game->player = 0;
	game->consum = 0;
	game->exit = 0;
	game->consumcpy = 0;
	game->exitcpy = 0;
	game->secondmap = 0;
	game->step = 0;
}

void	declar_struct(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i] && game->map != NULL)
		game->y++;
	game->x = ft_strlen(game->map[0]) - 1;
}

static unsigned int	counter_lines(const char *file)
{
	char			*line;
	unsigned int	nbr;
	int				fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(8);
	line = get_next_line(fd);
	nbr = 0;
	while (line != NULL)
	{
		nbr++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (nbr);
}

void	map(const char *file, t_game *game)
{
	char	*line;
	int		i;
	int		fd;

	game->line.y = count_lines(file);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		error(8);
	game->line.x = ft_strlen(line);
	game->map = malloc(sizeof(char *) * (game->line.y + 1));
	if (!game->map)
		return ;
	i = 0;
	while (line != NULL)
	{
		game->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	game->map[i] = NULL;
	if (*game->map == NULL)
		error(8);
}
