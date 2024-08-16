/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:56:24 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/16 16:44:40 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_env *env, char **av)
{
	if (check_file(av) == FALSE)
	{
		free(env);
		ft_error_message("FILE DOES NOT CONTAIN .ber ENDING\n");
		exit(1);
	}
	if (take_map(av[1], env) == FALSE)
		map_error(env, "CANNOT READ THE MAP\n");
	if (take_len(env) == FALSE)
		map_error(env, "INCORRECT SIZE OF MAP\n");
	env->counts.player_count = 0;
	env->counts.exit_count = 0;
	env->counts.count_keys = 0;
	if (check_colect(&(env->counts), env->map) == FALSE)
		map_error(env, "INCORRECT AMOUNT OF OBJECTS\n");
	if (check_map(env->map) == FALSE)
		map_error(env, "INCORRECT MAP\n");
	if (wall_checker(env->map, env->size_y, env->size_x) == FALSE)
		map_error(env, "INCORRECT WALLS IN MAP\n");
	if (flood_fill(env, av[1]) == FALSE)
		map_error(env, "INCORRECT MAP\n");
}

int	take_map(char *path, t_env *env)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(env);
		ft_error_message("CANNOT READ THE MAP\n");
		exit(1);
	}
	env->map = ft_get_file(fd, 0);
	if (!env->map)
	{
		close(fd);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}

int	take_len(t_env *env)
{
	int	check;
	int	check_x;

	env->size_y = 0;
	env->size_x = 0;
	while (env->map[env->size_y] != NULL)
		env->size_y++;
	while (env->map[0][env->size_x] != '\0')
		env->size_x++;
	check = 1;
	while (env->map[check] != NULL)
	{
		check_x = 0;
		while (env->map[check][check_x] != '\0')
			check_x++;
		if (check_x != env->size_x)
			return (FALSE);
		check++;
	}
	if (env->size_y < 3 && env->size_x < 3)
		return (FALSE);
	return (TRUE);
}

int	check_colect(t_counts *counts, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				counts->player_count++;
			else if (map[i][j] == 'E')
				counts->exit_count++;
			else if (map[i][j] == 'C')
				counts->count_keys++;
			j++;
		}
		i++;
	}
	if (counts->player_count != 1
		|| counts->exit_count != 1
		|| counts->count_keys < 1)
		return (FALSE);
	return (TRUE);
}

int	check_map(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1'
			&& map[i][j] != 'C' && map[i][j] != 'P'
			&& map[i][j] != 'E')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
