/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: aleseile <aleseile@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/04 17:31:58 by aleseile      #+#    #+#                 */
/*   Updated: 2025/06/04 17:40:01 by aleseile      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int32_t main(int argc, char **argv)
{
	t_game game;

	if (argc == 2)
	{
		game.map.filename = argv[1];
		validate_map(game.map.filename);
	}
	return 0;
}