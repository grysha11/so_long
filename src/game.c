/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:50:13 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/16 14:46:13 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game(t_env *env)
{
	env->move_c = 0;
	env->x = find_player(env->map, 'x');
	env->y = find_player(env->map, 'y');
	env->colect = 0;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, 120 * env->size_x,
			120 * env->size_y, "so_long");
	init_textures(env, env->mlx);
	render_screen(env);
	mlx_hook(env->win, 17, 1L << 17, destroy, env);
	mlx_hook(env->win, 2, 1, key_press, env);
	mlx_loop(env->mlx);
}

int	key_press(int keycode, t_env *env)
{
	if (keycode == KEY_W)
		movement(env, env->x, env->y - 1);
	else if (keycode == KEY_A)
		movement(env, env->x - 1, env->y);
	else if (keycode == KEY_S)
		movement(env, env->x, env->y + 1);
	else if (keycode == KEY_D)
		movement(env, env->x + 1, env->y);
	else if (keycode == KEY_ESC)
		destroy(env);
	return (0);
}

void	init_textures(t_env *env, void *mlx)
{
	int	i;
	int	j;

	env->img[0] = mlx_xpm_file_to_image(mlx, TEXTURE_CHARACTER, &i, &j);
	env->img[1] = mlx_xpm_file_to_image(mlx, TEXTURE_DOOR, &i, &j);
	env->img[2] = mlx_xpm_file_to_image(mlx, TEXTURE_FLOOR, &i, &j);
	env->img[3] = mlx_xpm_file_to_image(mlx, TEXTURE_KEY, &i, &j);
	env->img[4] = mlx_xpm_file_to_image(mlx, TEXTURE_WALL, &i, &j);
	i = 0;
	while (i <= 4)
	{
		if (!env->img[i])
		{
			ft_error_message("INCORRECT TEXUTRE\n");
			destroy(env);
		}
		i++;
	}
}

void	render_screen(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (y < env->size_y)
	{
		x = 0;
		while (x < env->size_x)
		{
			render_texture(env->map[y][x], env, x, y);
			x++;
		}
		y++;
	}
}

void	render_texture(char t, t_env *env, int x, int y)
{
	if (t == '1')
		mlx_put_image_to_window(env->mlx, env->win, env->img[4],
			x * 120, y * 120);
	else if (t == '0')
		mlx_put_image_to_window(env->mlx, env->win, env->img[2],
			x * 120, y * 120);
	else if (t == 'P')
		mlx_put_image_to_window(env->mlx, env->win, env->img[0],
			x * 120, y * 120);
	else if (t == 'C')
		mlx_put_image_to_window(env->mlx, env->win, env->img[3],
			x * 120, y * 120);
	else if (t == 'E')
		mlx_put_image_to_window(env->mlx, env->win, env->img[1],
			x * 120, y * 120);
}
