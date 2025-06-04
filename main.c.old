// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

# include "so_long.h"

static void error(void)
{
  puts(mlx_strerror(mlx_errno));
  exit(EXIT_FAILURE);
}

int	init(t_sl *sl)
{
	sl->tile_size = 42;
	sl->tile_scale = 2;
	sl->amount_x_tiles = WIDTH / (sl->tile_size * sl->tile_scale);
	sl->amount_y_tiles = HEIGHT / (sl->tile_size * sl->tile_scale);

	return (0);
}

int32_t main(int argc, char **argv)
{
    t_sl *sl = malloc(sizeof(t_sl));  // Allocate memory for sl

    if (sl == NULL) {
        // Handle memory allocation failure
        return 1;  // Or appropriate error handling
    }

	if (argc != 2) {
		ft_printf("Usage: %s <map_file>\n", argv[0]);
		return 1;
	}

    char *map_file = argv[1];

	if (validate_map(map_file)) {
		ft_printf("Map Validation passed.\n");
	} else {
		ft_printf("Map Validation failed.\n");
		error();
	}

    t_map *map = load_map(map_file);

    if (map) {
        for (int i = 0; i < map->height; i++) {
            printf("%s\n", map->tiles[i]);
        }
    }



	init(sl);
	// Start mlx
	mlx_t* mlx = mlx_init((map->width * (sl->tile_size * sl->tile_scale)), (map->height * (sl->tile_size * sl->tile_scale)), "Color Game", false);
	if (!mlx)
		error();

  // Try to load the file
	mlx_texture_t* texture = mlx_load_png("./ass/42x42_bg1.png");
	if (!texture)
		error();
  
  // Convert texture to a displayable image

	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();

  // Display the image
  	if (!mlx_resize_image(img, (sl->tile_size * sl->tile_scale), (sl->tile_size * sl->tile_scale)))
		error();
	int x = 0;
	int y = 0;
	while (x < sl->amount_x_tiles)
	{
		y = 0;
		while (y < sl->amount_y_tiles)
		{
			if (mlx_image_to_window(mlx, img, x*(sl->tile_size * sl->tile_scale), y*(sl->tile_size * sl->tile_scale)) < 0)
				error();
			y++;
		}
		x++;
	}

	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	free_map(map);
	// Optional, terminate will clean up any leftover images (not textures!)
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}