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

typedef struct s_tiles {
    int     amount_x_tiles;
    int     amount_y_tiles;
    int     tile_size;
    float   tile_scale;
} t_sl;


typedef struct s_map {
    int x;
    int y;
} t_map;


int validate_map(const char *mapfile);

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
