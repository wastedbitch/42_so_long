/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aleseile <aleseile@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/09 16:20:35 by aleseile      #+#    #+#                 */
/*   Updated: 2025/06/09 16:24:09 by aleseile      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				return;
			}
			// ft_printf("%c\n", game->map.tiles[y][x]);
			x++;
		}
		y++;
	}
}

void move_player(t_game *game, int dx, int dy) {
	if (game->map.tiles[game->player.y + dy][game->player.x + dx] == '1')
		return;
	else if (game->map.tiles[game->player.y + dy][game->player.x + dx] == 'X')
		mlx_close_window(game->mlx);
	else if (game->map.tiles[game->player.y + dy][game->player.x + dx] == 'E' && game->items == 0)
		mlx_close_window(game->mlx);
	else {
		if (game->map.tiles[game->player.y + dy][game->player.x + dx] == 'C')
		{
			game->map.tiles[game->player.y + dy][game->player.x + dx] = '0';
		}
		game->player.x = game->player.x + dx;
		game->player.y = game->player.y + dy;
		draw_bg(game);
		draw_walls(game);
		draw_enemy(game);
		draw_collectible(game);
		draw_exit(game);
		draw_player(game);
		game->moves++;
		ft_printf("%d\n", game->moves);
	}
}

void handle_input (mlx_key_data_t keydata, void *param)
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