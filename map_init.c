/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: aleseile <aleseile@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/03 15:52:11 by aleseile      #+#    #+#                 */
/*   Updated: 2025/06/03 16:10:36 by aleseile      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "so_long.h"

#define MAX_LINE_LENGTH 1024

typedef struct {
    char **tiles;
    int width;
    int height;
} Map;

t_map *load_map(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open map file");
        return NULL;
    }



    t_map *map = malloc(sizeof(t_map));

    // if (map == NULL) {
    //     return 1;

    map->height = 0;
    map->width = 0;

    char line[MAX_LINE_LENGTH];
    char **rows = NULL;

    while (fgets(line, sizeof(line), file)) {
        int len = strcspn(line, "\r\n"); // remove newline chars
        line[len] = '\0';

        if (map->width == 0)
            map->width = len;

        rows = realloc(rows, sizeof(char*) * (map->height + 1));
        rows[map->height] = malloc(map->width + 1);
        strcpy(rows[map->height], line);

        map->height++;
    }

    map->tiles = rows;

    fclose(file);
    return map;
}

void free_map(t_map *map) {
    for (int i = 0; i < map->height; i++) {
        free(map->tiles[i]);
    }
    free(map->tiles);
    free(map);
}