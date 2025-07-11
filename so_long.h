#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include "MLX42/MLX42.h"
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

# define TILE_SIZE 42
# define TILE_SCALE 2
# define MAX_LINE_LENGTH 1024

typedef struct	s_map {
	const char	*filename;
	char	**tiles;
	int		width;
	int		height;
} t_map;

typedef struct s_img {
	void	*bg;
	void	*wall;
	void	*col;
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
	int			tile_size;
	float		tile_scale;
	int			moves;
	int			items;
}	t_game;

int		validate_map(const char *filename);
int		load_map_into(t_map *map);
void	init_img(t_game *game);
int		init_mlx(t_game *game);
void	init_player(t_game *game);
void	print_map(t_map *map);
void	draw_bg(t_game *game);
void	draw_walls(t_game *game);
void	draw_player(t_game *game);
void	draw_enemy(t_game *game);
void	draw_collectible(t_game *game);
void	draw_exit(t_game *game);
void	draw_game(t_game *game);
void 	handle_input (mlx_key_data_t keydata, void *param);
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