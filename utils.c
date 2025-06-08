#include "so_long.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		ft_printf("%s\n", map->tiles[i]);
		i++;
	}
}