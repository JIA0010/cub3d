/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:33:59 by cjia              #+#    #+#             */
/*   Updated: 2023/09/20 16:07:03 by yoshimurahi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/inc/libft.h"
# include <fcntl.h>
# include <mlx.h>
// # include "minilibx/mlx.h"
// # include "mlx.h"
# include <stdbool.h>
# include <stdlib.h>

//map_textures
# define P_IMG_PLAYER "./textures/player.xpm"
# define P_IMG_GRASS "./textures/grass.xpm"
# define P_IMG_WOOD "./textures/wood.xpm"
# define P_IMG_GOAL "./textures/goal.xpm"
# define P_IMG_ITEM "./textures/item.xpm"

//keycode
# define X_ESC 65307
# define X_UP 65362
# define X_DOWN 65364
# define X_RIGHT 65363
# define X_LEFT 65361

//imac keycode
# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct t_game_data
{
	void	*graphics_context;
	void	*window;
	int		map_width;
	int		map_height;
	int		coin_count;
	int		endpoint_count;
	char	**game_map;
	int		player_walk_count;

	void	*wood;
	void	*player;
	void	*goal;
	void	*grass;
	void	*item;
}			t_game_data;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		pixel;
	int		len;
	int		end;
}			t_data;

typedef struct s_player
{
	int		p_x;
	int		p_y;
}			t_player;

int			put_window(char **argv);
int			create_map(t_game_data *data);
size_t		check_map(t_game_data data);
void		map_search_all(t_game_data *data);
t_game_data	import_map(char **argv, t_game_data data);
t_game_data	place_images_in_game(t_game_data data);
t_game_data	set_null(t_game_data data);
void		hook(t_game_data *data);
t_player	search_player(t_game_data *data);
void		movement_player(t_game_data *data, char c);
int			close_window(t_game_data *data);
size_t		ft_strnlen(const char *str);
size_t		my_strchr(const char *s, int c);
void		error(char *msg);
void		all_free(char **str);
void		limit_and_check_map(t_game_data data, int i, char **argv);

#endif