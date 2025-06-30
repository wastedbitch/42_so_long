/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_static.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aleseile <aleseile@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/30 13:58:59 by aleseile      #+#    #+#                 */
/*   Updated: 2025/06/30 14:05:46 by aleseile      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_bg(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->img.bg || !game->mlx)
		return ;
	mlx_resize_image(game->img.bg, (game->tile_size * game->tile_scale),
		(game->tile_size * game->tile_scale));
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			mlx_image_to_window(game->mlx,
				game->img.bg,
				x * (game->tile_size * game->tile_scale),
				y * (game->tile_size * game->tile_scale));
			x++;
		}
		y++;
	}
}

void	draw_walls(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->img.wall || !game->mlx)
		return ;
	mlx_resize_image(game->img.wall, (game->tile_size * game->tile_scale),
		(game->tile_size * game->tile_scale));
	y = 0;
	x = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.tiles[y][x] == '1')
			{
				mlx_image_to_window(game->mlx,
					game->img.wall,
					x * (game->tile_size * game->tile_scale),
					y * (game->tile_size * game->tile_scale));
			}
			x++;
		}
		y++;
	}
}

void	draw_exit(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->img.exit || !game->mlx)
		return ;
	mlx_resize_image(game->img.exit, (game->tile_size * game->tile_scale),
		(game->tile_size * game->tile_scale));
	y = 0;
	x = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.tiles[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx,
					game->img.exit, x * (game->tile_size * game->tile_scale),
					y * (game->tile_size * game->tile_scale));
				return ;
			}
			x++;
		}
		y++;
	}
}

void	draw_game(t_game *game)
{
	draw_bg(game);
	draw_walls(game);
	draw_enemy(game);
	draw_collectible(game);
	draw_exit(game);
	draw_player(game);
}
