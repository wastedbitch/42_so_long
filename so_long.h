#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include "MLX42/MLX42.h"
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

# define WIDTH 1920
# define HEIGHT 1080
# define TILE_W 42
# define TILE_H 42
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UARROW 126
# define LARROW 123
# define DARROW 125
# define RARROW 124

typedef struct	s_map {
	const char	*filename;
	char	**tiles;
	int		width;
	int		height;
} t_map;

typedef struct s_img {
	void	*bg;
	void	*wall;
	void	*collectible;
	void	*player;
	void	*enemy;
	void	*exit;
}   t_img;

typedef struct	s_player {
	int	x;
	int	y;
} t_player;



typedef struct s_game {
	void		*mlx;
	void		*window;
	t_img		img;
	t_player	player;
	t_map		map;
	int		tile_size;
	float	tile_scale;
	int		moves;
}	t_game;



int validate_map(const char *mapfile);
t_map *load_map(const char *filename);
void free_map(t_map *map);

#endif


// map size x/y - tile
// tile size - pixel
// tile scale - float
// window size x/y - pixel
// map

// player x/y 
// counter
// collected

// todo:
// -assets
//     -fish all directions
//     -collectible
//     -wallz
// -make structs
// -map parsing/validation
