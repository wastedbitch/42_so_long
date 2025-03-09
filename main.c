// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "MLX42/MLX42.h"

#define WIDTH 420
#define HEIGHT 420

static void error(void)
{
  puts(mlx_strerror(mlx_errno));
  exit(EXIT_FAILURE);
}

int32_t main(void)
{
	// Start mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Color Game", false);
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
	int x = 0;
	int y = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			if (mlx_image_to_window(mlx, img, x*42, y*42) < 0)
				error();
			y++;
		}
		x++;
	}

	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	
	// Optional, terminate will clean up any leftover images (not textures!)
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
