/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_draw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aleseile <aleseile@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 18:46:25 by aleseile      #+#    #+#                 */
/*   Updated: 2025/06/09 16:27:09 by aleseile      ########   odam.nl         */
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

	if (!game || !game->img.wall || !game->mlx)
		return ;

	mlx_resize_image(game->img.wall, (game->tile_size * game->tile_scale), (game->tile_size * game->tile_scale));
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

void	draw_player(t_game *game)
{
	if (!game || !game->img.player || !game->mlx)
		return ;

	mlx_resize_image(game->img.player, (game->tile_size * game->tile_scale), (game->tile_size * game->tile_scale));
	mlx_image_to_window(game->mlx, game->img.player, game->player.x * (game->tile_size * game->tile_scale), game->player.y * (game->tile_size * game->tile_scale));
}

void	draw_enemy(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->img.enemy || !game->mlx)
		return ;

	mlx_resize_image(game->img.enemy, (game->tile_size * game->tile_scale), (game->tile_size * game->tile_scale));
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
			// ft_printf("%c\n", game->map.tiles[y][x]);
			x++;
		}
		y++;
	}
}

void	draw_collectible(t_game *game)
{
	int	x;
	int	y;
	int c;

	c = 0;

	if (!game || !game->img.collectible || !game->mlx)
		return ;

	mlx_resize_image(game->img.collectible, (game->tile_size * game->tile_scale), (game->tile_size * game->tile_scale));
	y = 0;
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
				game->img.collectible,
				x * (game->tile_size * game->tile_scale),
				y * (game->tile_size * game->tile_scale));
			}
			x++;
		}
		y++;
	}
	game->items = c;

}

void	draw_exit(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->img.exit || !game->mlx)
		return ;

	mlx_resize_image(game->img.exit, (game->tile_size * game->tile_scale), (game->tile_size * game->tile_scale));
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
				game->img.exit,
				x * (game->tile_size * game->tile_scale),
				y * (game->tile_size * game->tile_scale));
				return ;
			}
			x++;
		}
		y++;
	}
}

void draw_game(t_game *game)
{
	draw_bg(game);
	draw_walls(game);
	draw_enemy(game);
	draw_collectible(game);
	draw_exit(game);
	draw_player(game);
}