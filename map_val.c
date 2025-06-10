/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_val.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aleseile <aleseile@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 18:47:02 by aleseile      #+#    #+#                 */
/*   Updated: 2025/06/08 18:47:03 by aleseile      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MAX_MAP_SIZE 100

char	map[MAX_MAP_SIZE][MAX_MAP_SIZE];
int		visited[MAX_MAP_SIZE][MAX_MAP_SIZE];
int		rows = 0;
int		cols = 0;
int		collectibles = 0;
int		reachable_c = 0;
int		exit_found = 0;
int		exit_count = 0;
int		enemy_count = 0;
int		player_found = 0;
int		player_x = -1;
int		player_y = -1;

void	flood_fill(int x, int y)
{
	if (x < 0 || x >= rows || y < 0 || y >= cols)
		return ;
	if (visited[x][y] || map[x][y] == '1')
		return ;
	visited[x][y] = 1;
	if (map[x][y] == 'C')
		reachable_c++;
	if (map[x][y] == 'E')
		exit_found = 1;
	flood_fill(x + 1, y);
	flood_fill(x - 1, y);
	flood_fill(x, y + 1);
	flood_fill(x, y - 1);
}

int	validate_walls(void)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
		{
			ft_printf("Top or bottom wall is not enclosed\n");
			return (0);
		}
		i++;
	}
	i = 1;
	while (i < rows - 1)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
		{
			ft_printf("Side wall not enclosed at row %d\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_map(const char *mapfile)
{
	FILE	*file;
	char	line[MAX_MAP_SIZE + 2];
	int		line_len;
	int		len;
	int		i;

	file = fopen(mapfile, "r");
	if (!file)
		return (perror("Error opening file"), 1);
	line_len = -1;
	while (fgets(line, sizeof(line), file))
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[--len] = '\0';
		if (line_len == -1)
			line_len = len;
		else if (line_len != len)
			return (ft_printf("Map is not square\n"), fclose(file), 1);
		i = 0;
		while (i < len)
		{
			if (line[i] != '1' && line[i] != '0' && line[i] != 'P'
				&& line[i] != 'C' && line[i] != 'E' && line[i] !='X')
				return (ft_printf("Invalid char '%c'\n", line[i]),
					fclose(file), 1);
			if (line[i] == 'P')
			{
				if (player_found)
					return (ft_printf("Multiple players found\n"),
						fclose(file), 1);
				player_found = 1;
				player_x = rows;
				player_y = i;
			}
			else if (line[i] == 'C')
				collectibles++;
			else if (line[i] == 'E')
				exit_count++;
			else if (line[i] == 'X')
				enemy_count++;
			map[rows][i] = line[i];
			i++;
		}
		rows++;
	}
	fclose(file);
	cols = line_len;
	if (!player_found)
		return (ft_printf("No player found\n"), 1);
	if (exit_count != 1)
		return (ft_printf("Expected 1 exit, found %d\n", exit_count), 1);
	if (collectibles < 1)
		return (ft_printf("At least 1 collectible required\n"), 1);
	if (!validate_walls())
		return (1);
	flood_fill(player_x, player_y);
	if (reachable_c != collectibles)
		return (ft_printf("Unreachable collectibles\n"), 1);
	if (!exit_found)
		return (ft_printf("Exit not reachable\n"), 1);
	return (0);
}
