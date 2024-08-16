/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:13:34 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/16 14:53:32 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_message(char *str)
{
	ft_putstr_fd(COLOR, 2);
	ft_putstr_fd(COLOR_RED, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(COLOR, 2);
}

void	map_error(t_env *env, char *s)
{
	int	i;

	ft_error_message(s);
	if (env->map)
	{
		i = 0;
		while (i < env->size_y)
		{
			if (env->map[i])
				free(env->map[i]);
			i++;
		}
		free(env->map);
	}
	if (env)
		free(env);
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i] != NULL)
		{
			if (map[i])
				free(map[i]);
			i++;
		}
		free(map);
	}
}
