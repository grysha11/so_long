/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc <hzakharc@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:01:27 by hzakharc          #+#    #+#             */
/*   Updated: 2024/12/03 20:06:42 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../include/ft_printf/ft_printf.h"
# include "../include/libft/libft.h"
# include "../include/gnl/gnl.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../include/minilibx-linux/mlx.h"
# include <math.h>

# define TRUE 0
# define FALSE 1

# define T_SIZE 120
# define TEXTURE_WALL "textures/Wall.xpm"
# define TEXTURE_FLOOR "textures/Floor.xpm"
# define TEXTURE_CHARACTER "textures/Character.xpm"
# define TEXTURE_DOOR "textures/Door.xpm"
# define TEXTURE_KEY "textures/Key.xpm"

# define COLOR "\033[0m"
# define COLOR_RED "\033[1;31m"
# define COLOR_GREEN "\033[1;32m"
# define COLOR_BLUE "\033[1;34m"
# define COLOR_PURPLE "\033[1;35m"
# define COLOR_CYAN "\033[1;36m"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_counts
{
	int		count_keys;
	int		player_count;
	int		exit_count;
}				t_counts;

typedef struct s_env
{
	t_counts	counts;
	void		*img[5];
	char		**map;
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
	int			colect;
	int			x;
	int			y;
	int			move_c;
	int			flood_c;
	int			flood_e;
}				t_env;

void	game(t_env *env);
int		key_press(int keycode, t_env *env);
void	init_textures(t_env *env, void *mlx);
void	render_screen(t_env *env);
void	render_texture(char t, t_env *env, int x, int y);
void	movement(t_env *env, int x, int y);
void	movement_util(t_env *env, int x, int y);

void	map_error(t_env *env, char *s);
void	ft_error_message(char *str);
void	free_map(char **map);
int		destroy(t_env *env);

int		find_player(char **map, char type);

void	parse_map(t_env *env, char **av);
int		take_map(char *path, t_env *env);
int		take_len(t_env *env);
int		check_colect(t_counts *counts, char **map);
int		check_map(char **map);
int		wall_checker(char **map, int size_y, int size_x);
int		flood_fill(t_env *env, char *path);
void	fill(char **map, t_env *env, int y, int x);
int		check_file(char **av);

#endif