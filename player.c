/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aleseile <aleseile@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/09 16:20:35 by aleseile      #+#    #+#                 */
/*   Updated: 2025/07/03 18:00:59 by aleseile      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	init_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.tiles[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_fish(t_game *game, int dx, int dy)
{
	if (game->map.tiles[game->player.y + dy][game->player.x + dx] == 'C')
	{
		game->map.tiles[game->player.y + dy][game->player.x + dx] = '0';
	}
	game->player.x = game->player.x + dx;
	game->player.y = game->player.y + dy;
	draw_game(game);
	game->moves++;
	ft_printf("%d\n", game->moves);
}

void	move_player(t_game *game, int dx, int dy)
{
	if (game->map.tiles[game->player.y + dy][game->player.x + dx] == '1')
		return ;
	else if (game->map.tiles[game->player.y + dy][game->player.x + dx] == 'X')
	{
		ft_printf("U DIED");
		mlx_close_window(game->mlx);
	}
	else if (game->map.tiles[game->player.y + dy][game->player.x + dx] == 'E'
			&& game->items == 0)
	{
		game->moves++;
		ft_printf("YOU HAVE REACHED THE EXIT IN %d MOVES! <:3><", game->moves);
		mlx_close_window(game->mlx);
	}
	else if (game->map.tiles[game->player.y + dy][game->player.x + dx] == 'E'
			&& game->items != 0)
		move_fish(game, dx, dy);
	else
		move_fish(game, dx, dy);
}

void	handle_input(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	if (keydata.action != MLX_PRESS)
		return ;
	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		move_player(game, 0, -1);
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		move_player(game, 0, 1);
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		move_player(game, -1, 0);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		move_player(game, 1, 0);
}
