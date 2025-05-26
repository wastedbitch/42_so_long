#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAP_SIZE 100

char map[MAX_MAP_SIZE][MAX_MAP_SIZE];
int visited[MAX_MAP_SIZE][MAX_MAP_SIZE];
int rows = 0, cols = 0;
int collectibles = 0, reachable_c = 0, exit_found = 0;
int exit_count = 0;
int player_found = 0;
int player_x = -1, player_y = -1;

void flood_fill(int x, int y) {
    if (x < 0 || x >= rows || y < 0 || y >= cols)
        return;
    if (visited[x][y] || map[x][y] == '1')
        return;

    visited[x][y] = 1;
    if (map[x][y] == 'C') reachable_c++;
    if (map[x][y] == 'E') exit_found = 1;

    flood_fill(x + 1, y);
    flood_fill(x - 1, y);
    flood_fill(x, y + 1);
    flood_fill(x, y - 1);
}

int validate_walls() {
    for (int i = 0; i < cols; i++) {
        if (map[0][i] != '1' || map[rows - 1][i] != '1') {
            printf("Top or bottom wall is not enclosed\n");
            return 0;
        }
    }

    for (int i = 1; i < rows - 1; i++) {
        if (map[i][0] != '1' || map[i][cols - 1] != '1') {
            printf("Side wall not enclosed at row %d\n", i);
            return 0;
        }
    }

    return 1;
}

int validate_map() {
    FILE *file = fopen("test2.map", "r");
    if (!file) {
        perror("Error opening file");
        return 0;
    }

    char line[MAX_MAP_SIZE + 2]; // +2 for newline and null terminator
    int line_len = -1;

    while (fgets(line, sizeof(line), file)) {
        int len = strlen(line);
        if (line[len - 1] == '\n') line[--len] = '\0';

        if (line_len == -1)
            line_len = len;
        else if (line_len != len) {
            printf("Map is not square (inconsistent row lengths)\n");
            fclose(file);
            return 0;
        }

        for (int i = 0; i < len; i++) {
            char c = line[i];
            if (c != '1' && c != '0' && c != 'P' && c != 'C' && c != 'E') {
                printf("Invalid character '%c' in map\n", c);
                fclose(file);
                return 0;
            }

            if (c == 'P') {
                if (player_found) {
                    printf("Multiple players found\n");
                    fclose(file);
                    return 0;
                }
                player_found = 1;
                player_x = rows;
                player_y = i;
            } else if (c == 'C') {
                collectibles++;
            } else if (c == 'E') {
                exit_count++;
            }

            map[rows][i] = c;
        }
        rows++;
    }

    fclose(file);
    cols = line_len;

    // Basic element validation
    if (!player_found) {
        printf("No player found\n");
        return 0;
    }

    if (exit_count != 1) {
        printf("There must be exactly one exit, found %d\n", exit_count);
        return 0;
    }

    if (collectibles < 1) {
        printf("There must be at least one collectible\n");
        return 0;
    }

    if (!validate_walls()) {
        return 0;
    }

    // Check reachability
    flood_fill(player_x, player_y);

    if (reachable_c != collectibles) {
        printf("Not all collectibles are reachable (found %d of %d)\n", reachable_c, collectibles);
        return 0;
    }

    if (!exit_found) {
        printf("Exit is not reachable\n");
        return 0;
    }

    printf("Map is valid\n");
    return 1;
}

int main(void) {
    if (validate_map()) {
        printf("Validation passed.\n");
    } else {
        printf("Validation failed.\n");
    }
    return 0;
}
