/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aleseile <aleseile@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/04 17:31:58 by aleseile      #+#    #+#                 */
/*   Updated: 2025/06/09 16:28:14 by aleseile      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Missing map file\n");
		return (1);
	}
	game.map.filename = argv[1];
	game.moves = 0;
	if (validate_map(game.map.filename) != 0)
		return (1);
	if (load_map_into(&game.map) != 0)
		return (1);
	ft_printf("Map loaded successfully\n");
	print_map(&game.map);

	init_mlx(&game);
	if (!game.mlx)
	{
		ft_printf("Failed to initialize MLX\n");
		return (1);
	}
	init_img(&game);
	init_player(&game);
	draw_bg(&game);
	draw_walls(&game);
	draw_player(&game);
	ft_printf("yay");
	mlx_loop(game.mlx);
	return (0);
}
