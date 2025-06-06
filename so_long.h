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


// 1. STUFF TO INIT
// - validate map
// - load map
// - load mlx
// - load images
// - init window

// 2. GAME LOOP
// - draw map to window
// - draw collectibles
// - draw enemies
// - draw player
// - move enemies
// - if collectibles are collected draw exit
// - player killed or exit reached exit game



// LAYERS:
// 5. Player - drawn every frame
// 4. EXIT - drawn once all collectibles are collected
// 3. ENEMIES - Drawn every fram & moving ever 2 seconds 
// 2. Collecitbels - drawn every frame is not picked up
// 1. Walls - drawn once on game start
// 0. BG - drawn once on game start


// NEXT TASKS:
// load .xmp to files
// display backgorund & walls

// dipsplay player, collectibles & enemies

// player movement

// get collectibles & display exit

// enemie movement

// animations ??

// fix bugs & norm & map validation edge cases YAY !!! :333

// & never KILL yo self !



// PROJECT STRUCTURE:
// main.c
// map_val.c - map valiation obv
// map_init.c - map parcing & loading
// img_init.c - loading all imgs
// gmae_init.c - game initialisation duh
// fish.c - player movement
// alien.c - enemie movement
// cex.c - collectibles & exit
// maps
// assets
// lib



// idk meow