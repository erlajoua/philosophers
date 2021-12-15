/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:01:57 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/29 11:26:27 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

int		init_params(t_info *infos, int ac, char **av)
{
	infos->onedead = 0;
	infos->time2 = 0;
	infos->nb_philos = ft_atoi(av[1]);
	if (infos->nb_philos <= 1)
	{
		ft_putstr_fd("you must have a nb_philo > 1\n", STDERR_FILENO);
		return (0);
	}
	infos->time_to_die = ft_atoi(av[2]);
	infos->time_to_eat = ft_atoi(av[3]);
	infos->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		infos->nb_meals_max = ft_atoi(av[5]);
		if (infos->nb_meals_max <= 0)
		{
			ft_putstr_fd("you must have a nb_meals > 0\n", STDERR_FILENO);
			return (0);
		}
	}
	else
		infos->nb_meals_max = 0;
	infos->onedead = 0;
	infos->current_nb_meal = 0;
	return (1);
}
