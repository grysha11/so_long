/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:22:28 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/16 14:55:47 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_env *env)
{
	if (env->img[0])
		mlx_destroy_image(env->mlx, env->img[0]);
	if (env->img[1])
		mlx_destroy_image(env->mlx, env->img[1]);
	if (env->img[2])
		mlx_destroy_image(env->mlx, env->img[2]);
	if (env->img[3])
		mlx_destroy_image(env->mlx, env->img[3]);
	if (env->img[4])
		mlx_destroy_image(env->mlx, env->img[4]);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	free_map(env->map);
	free(env);
	exit(0);
}

int	find_player(char **map, char type)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				if (type == 'x')
					return (x);
				else if (type == 'y')
					return (y);
			}
			x++;
		}
		y++;
	}
	return (-1);
}
