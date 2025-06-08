#include "so_long.h"

void draw_map(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->img.bg || !game->mlx)
		return ;

    mlx_resize_image(game->img.bg, game->tile_size, (game->tile_size * game->tile_scale));
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			mlx_image_to_window(game->mlx,
				game->img.bg,
				x * game->tile_size,
				y * game->tile_size);
			x++;
		}
		y++;
	}
}
