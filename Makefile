CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Sources and objects
SRCS_SL = main.c map_val.c map_init.c
OBJS_SL = $(SRCS_SL:.c=.o)
LIBFT_DIR = lib/libft
LIBFT_REPO = https://github.com/wastedbitch/42_libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = lib/ft_printf
FT_PRINTF_REPO = https://github.com/wastedbitch/42_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

MLX_DIR = lib/mlx
MLX_REPO = https://github.com/codam-coding-college/MLX42
MLX = $(MLX_DIR)/build/libmlx42.a

# Output executables
EXEC_SL = main

# Default target
all: $(MLX) $(LIBFT) $(FT_PRINTF) $(EXEC_SL)

# Clone and compile MLX42
$(MLX_DIR)/build/libmlx42.a:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	(cd $(MLX_DIR) && cmake -B build)
	$(MAKE) -C $(MLX_DIR)/build

# Clone and compile libft
$(LIBFT_DIR)/libft.a:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	$(MAKE) -C $(LIBFT_DIR)

# Clone and compile ft_printf
$(FT_PRINTF_DIR)/libftprintf.a:
	@if [ ! -d "$(FT_PRINTF_DIR)" ]; then \
		git clone $(FT_PRINTF_REPO) $(FT_PRINTF_DIR); \
	fi
	$(MAKE) -C $(FT_PRINTF_DIR)

# Compile SO_LONG
$(EXEC_SL): $(MLX) $(LIBFT) $(FT_PRINTF) $(OBJS_SL)
	$(CC) $(CFLAGS) $(OBJS_SL) -o $(EXEC_SL) -L$(LIBFT_DIR) -L$(FT_PRINTF_DIR) -L$(MLX_DIR)/build -lft -lftprintf -lmlx42 -lglfw
	# $(CC) $(CFLAGS) $(OBJS_SL) -o $(EXEC_SL) -L$(LIBFT_DIR) -L$(FT_PRINTF_DIR) -L$(MLX_DIR)/build -L/opt/homebrew/lib -lft -lftprintf -lmlx42 -lglfw

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR)/include -c $< -o $@

# Clean up object files, executables, and libraries
clean:
	rm -f $(OBJS_SL)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR)/build clean

# Remove everything
fclean: clean
	rm -f $(EXEC_SL)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -rf $(LIBFT_DIR) $(FT_PRINTF_DIR) $(MLX_DIR)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
