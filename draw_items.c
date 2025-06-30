/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_items.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: aleseile <aleseile@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/30 13:59:29 by aleseile      #+#    #+#                 */
/*   Updated: 2025/06/30 14:07:44 by aleseile      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_game *game)
{
	if (!game || !game->img.player || !game->mlx)
		return ;
	mlx_resize_image(game->img.player, (game->tile_size * game->tile_scale),
		(game->tile_size * game->tile_scale));
	mlx_image_to_window(game->mlx, game->img.player,
		game->player.x * (game->tile_size * game->tile_scale),
		game->player.y * (game->tile_size * game->tile_scale));
}

void	draw_enemy(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->img.enemy || !game->mlx)
		return ;
	mlx_resize_image(game->img.enemy, (game->tile_size * game->tile_scale),
		(game->tile_size * game->tile_scale));
	y = 0;
	x = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.tiles[y][x] == 'X')
			{
				mlx_image_to_window(game->mlx,
					game->img.enemy,
					x * (game->tile_size * game->tile_scale),
					y * (game->tile_size * game->tile_scale));
			}
			x++;
		}
		y++;
	}
}

void	colloop(t_game *game, int y, int c)
{
	int	x;

	x = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.tiles[y][x] == 'C')
			{
				c++;
				mlx_image_to_window(game->mlx,
					game->img.col, x * (game->tile_size * game->tile_scale),
					y * (game->tile_size * game->tile_scale));
			}
			x++;
		}
		y++;
	}
	game->items = c;
}

void	draw_collectible(t_game *game)
{
	int	y;
	int	c;

	c = 0;
	y = 0;
	if (!game || !game->img.col || !game->mlx)
		return ;
	mlx_resize_image(game->img.col, (game->tile_size * game->tile_scale),
		(game->tile_size * game->tile_scale));
	colloop(game, y, c);
}
