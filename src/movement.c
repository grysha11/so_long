/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:05:33 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/16 14:47:24 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(t_env *env, int x, int y)
{
	if (env->map[y][x] == '1')
		return ;
	else if (env->map[y][x] == 'E')
	{
		if (env->counts.count_keys == env->colect)
			destroy(env);
	}
	else if (env->map[y][x] == 'C')
	{
		env->colect++;
		env->map[env->y][env->x] = '0';
		env->map[y][x] = 'P';
		mlx_put_image_to_window(env->mlx, env->win, env->img[2],
			env->x * 120, env->y * 120);
		mlx_put_image_to_window(env->mlx, env->win,
			env->img[0], x * 120, y * 120);
		env->y = y;
		env->x = x;
		env->move_c++;
		ft_printf("\033[0m\033[1;36m[%d]: MOVE COUNT\033[0m\n", env->move_c);
	}
	else
		movement_util(env, x, y);
}

void	movement_util(t_env *env, int x, int y)
{
	env->map[env->y][env->x] = '0';
	env->map[y][x] = 'P';
	mlx_put_image_to_window(env->mlx, env->win, env->img[2],
		env->x * 120, env->y * 120);
	mlx_put_image_to_window(env->mlx, env->win,
		env->img[0], x * 120, y * 120);
	env->y = y;
	env->x = x;
	env->move_c++;
	ft_printf("\033[0m\033[1;36m[%d]: MOVE COUNT\033[0m\n", env->move_c);
}
