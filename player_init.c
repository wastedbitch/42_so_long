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