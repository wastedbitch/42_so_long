/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aleseile <aleseile@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/03 15:52:11 by aleseile      #+#    #+#                 */
/*   Updated: 2025/06/08 18:49:25 by aleseile      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

#define MAX_LINE_LENGTH 1024

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
