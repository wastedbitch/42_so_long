/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aleseile <aleseile@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 18:47:32 by aleseile      #+#    #+#                 */
/*   Updated: 2025/06/08 18:47:34 by aleseile      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*load_image(void *mlx, const char *path)
{
	mlx_texture_t			*png;
	mlx_image_t		*img;

	png = mlx_load_png(path);
	if (!png) {
		ft_printf("png error");
		return (NULL);
	}
	img = mlx_texture_to_image(mlx, png);
	return (img);
}


void	img_init(t_game *game)
{
	game->img.bg = load_image(game->mlx, "img/player.png");
	game->img.wall = load_image(game->mlx, "img/wall.png");
	game->img.collectible = load_image(game->mlx, "img/collectible.png");
	game->img.player = load_image(game->mlx, "img/player.png");
	game->img.enemy = load_image(game->mlx, "img/enemy.png");
	game->img.exit = load_image(game->mlx, "img/exit.png");
}