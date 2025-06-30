#include "so_long.h"
#include <string.h>

int	init_mlx(t_game *game)
{
	game->tile_size = TILE_SIZE;
	game->tile_scale = TILE_SCALE;
	game->mlx = mlx_init((game->map.width * game->tile_size) * game->tile_scale, (game->map.height * game->tile_size) * game->tile_scale, "so_long", false);
	if (!game->mlx)
		return (1);
	return (0);
}

void	init_img(t_game *game)
{
	game->img.bg = mlx_texture_to_image(game->mlx, mlx_load_png("textures/bg.png"));
	game->img.wall = mlx_texture_to_image(game->mlx, mlx_load_png("textures/wall.png"));
	game->img.col = mlx_texture_to_image(game->mlx, mlx_load_png("textures/collectible.png"));
	game->img.player = mlx_texture_to_image(game->mlx, mlx_load_png("textures/player.png"));
	game->img.enemy = mlx_texture_to_image(game->mlx, mlx_load_png("textures/enemy.png"));
	game->img.exit = mlx_texture_to_image(game->mlx, mlx_load_png("textures/exit.png"));
}

static char	**read_map_lines(FILE *file, int *width, int *height)
{
	char	line[MAX_LINE_LENGTH];
	char	**rows;
	char	**temp;
	int		len;

	rows = NULL;
	*width = 0;
	*height = 0;
	while (fgets(line, sizeof(line), file))
	{
		len = strcspn(line, "\r\n");
		line[len] = '\0';
		if (*width == 0)
			*width = len;
		else if (len != *width)
			return (NULL);
		temp = realloc(rows, sizeof(char *) * (*height + 1));
		if (!temp)
			return (NULL);
		rows = temp;
		rows[*height] = malloc(len + 1);
		if (!rows[*height])
			return (NULL);
		strcpy(rows[*height], line);
		(*height)++;
	}
	return (rows);
}

int	load_map_into(t_map *map)
{
	FILE	*file;

	file = fopen(map->filename, "r");
	if (!file)
		return (perror("fopen"), 1);
	map->tiles = read_map_lines(file, &map->width, &map->height);
	fclose(file);
	if (!map->tiles)
		return (ft_printf("Failed to read map lines\n"), 1);
	return (0);
}

void	free_map_tiles(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->tiles[i]);
		i++;
	}
	free(map->tiles);
}