/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_draw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aleseile <aleseile@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 18:46:25 by aleseile      #+#    #+#                 */
/*   Updated: 2025/06/09 15:41:32 by aleseile      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_bg(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->img.bg || !game->mlx)
		return ;

	mlx_resize_image(game->img.bg, (game->tile_size * game->tile_scale), (game->tile_size * game->tile_scale));
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

	if (!game || !game->img.bg || !game->mlx)
		return ;

	mlx_resize_image(game->img.bg, (game->tile_size * game->tile_scale), (game->tile_size * game->tile_scale));
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
			// ft_printf("%c\n", game->map.tiles[y][x]);
			x++;
		}
		y++;
	}
}