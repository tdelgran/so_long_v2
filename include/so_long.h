#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <string.h>
# include <mlx.h>

# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_ECHAP 53

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_game
{
	char	**map;
	char	**secondmap;
	void	*window;
	void	*mlxwin;
	t_pos	line;
	int		x;
	int		y;
	int		player;
	int		exit;
	int		consum;
	int		consumcpy;
	int		exitcpy;
	void	*floor;
	void	*character;
	void	*wall;
	void	*object;
	void	*f_exit;
	int		player_posy;
	int		player_posx;
	int		step;
}				t_game;

void	map(const char *file, t_game *game);
void	rectangular(t_game *game);
void	wall(t_game *game);
void	character(t_game *game);
void	parsing(t_game *game, char *av);
void	path(t_game *game, int y, int x);
void	check_path(t_game *game);
int	secondmap(t_game *game);
int	*search_player(t_game *game);
int	key_code(int key_code, t_game *game);
void	error(int error);
void	check_extension(char *ber);
void	start_window(t_game *game);
void	set_image(t_game *game);

#endif