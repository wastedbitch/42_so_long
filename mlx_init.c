#include "so_long.h"

int	init_mlx(t_game *game)
{
    game->tile_size = 42;
	game->tile_scale = 1;

	game->mlx = mlx_init((game->map.width * game->tile_size), (game->map.height * game->tile_size), "so_long", false);
	if (!game->mlx)
		return (1);
	return (0);
}