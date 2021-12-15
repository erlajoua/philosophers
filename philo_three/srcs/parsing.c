/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:03:28 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/29 11:03:28 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

int		is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		valid_params(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
			return (-1);
		if (!is_numeric(av[i]))
			return (-2);
		i++;
	}
	return (1);
}

int		parsing_params(int ac, char **av)
{
	int ret;

	ret = valid_params(ac, av);
	if (ret == -1)
		ft_putstr_fd("negative value not allowed\n", STDERR_FILENO);
	if (ret == -2)
		ft_putstr_fd("argument non numeric detected\n", STDERR_FILENO);
	if (ret < 0)
		return (0);
	return (1);
}
