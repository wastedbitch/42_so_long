/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aleseile <aleseile@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 18:47:09 by aleseile      #+#    #+#                 */
/*   Updated: 2025/06/08 18:47:11 by aleseile      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_mlx(t_game *game)
{
    game->tile_size = 42;
	game->tile_scale = 2;

	game->mlx = mlx_init((game->map.width * game->tile_size) * game->tile_scale, (game->map.height * game->tile_size) * game->tile_scale, "so_long", false);
	if (!game->mlx)
		return (1);
	return (0);
}