/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:53:04 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/16 19:27:37 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_checker(char **map, int size_y, int size_x)
{
	int	i;

	i = 0;
	while (i < size_x)
	{
		if (map[0][i] != '1' || map[size_y - 1][i] != '1')
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < size_y)
	{
		if (map[i][0] != '1' || map[i][size_x - 1] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	fill(char **map, t_env *env, int y, int x)
{
	if (map[y][x] == 'E')
	{
		env->flood_e = 1;
		return ;
	}
	if (x < 0 || y < 0 || y >= env->size_y || x >= env->size_x)
		return ;
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		env->flood_c++;
	map[y][x] = '1';
	fill(map, env, y + 1, x);
	fill(map, env, y - 1, x);
	fill(map, env, y, x + 1);
	fill(map, env, y, x - 1);
}

int	flood_fill(t_env *env, char *path)
{
	int		fd;
	int		x;
	int		y;
	char	**checker;

	fd = open(path, O_RDONLY);
	checker = ft_get_file(fd, 0);
	close(fd);
	env->flood_c = 0;
	x = find_player(checker, 'x');
	y = find_player(checker, 'y');
	env->flood_e = 0;
	fill(checker, env, y, x);
	free_map(checker);
	if (env->flood_c == env->counts.count_keys && env->flood_e == 1)
		return (TRUE);
	return (FALSE);
}

int	check_file(char **av)
{
	char	*file;
	int		len;

	file = ft_strdup(".ber");
	if (!file)
	{
		ft_error_message("ALLOCATION ERROR\n");
		exit(1);
	}
	len = ft_strlen(av[1]);
	if (len >= 4 && ft_strncmp(av[1] + len - 4, file, 4) == 0)
	{
		free(file);
		return (TRUE);
	}
	else
	{
		free(file);
		return (FALSE);
	}
}
