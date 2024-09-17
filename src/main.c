/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:45:36 by hzakharc          #+#    #+#             */
/*   Updated: 2024/09/17 09:35:59 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
	{
		ft_error_message("INCORRECT AMOUNT OF ARGUMENTS\n");
		exit(1);
	}
	env = malloc(sizeof(t_env));
	if (!env)
	{
		ft_error_message("MEMORY ALLOCATION ERROR\n");
		exit(1);
	}
	parse_map(env, av);
	game(env);
	free(env);
	return (0);
}
