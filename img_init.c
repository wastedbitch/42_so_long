#include "so_long.h"

mlx_image_t	*load_image(void *mlx, const char *path)
{
	mlx_texture_t			*png;
	mlx_image_t		*img;

	png = mlx_load_png(path);
	if (!png) {
		ft_printf("xpm error");
		return (NULL);
	}
	img = mlx_texture_to_image(mlx, png);
	// mlx_delete_xmp42(xmp);
	return (img);
}


void	img_init(t_game *game)
{
	game->img.bg = load_image(game->mlx, "img/bg.png");
	// game->img.wall = load_image(game->mlx, "./assets/wall.xpm");
	// game->img.collectible = load_image(game->mlx, "./assets/collectible.xpm");
	// game->img.player = load_image(game->mlx, "./assets/player.xpm");
	// game->img.enemy = load_image(game->mlx, "./assets/enemy.xpm");
	// game->img.exit = load_image(game->mlx, "./assets/exit.xpm");
}