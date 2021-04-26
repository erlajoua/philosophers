/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:01:57 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/25 10:21:50 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	init_params(t_info *infos, int ac, char **av)
{
	infos->onedead = 0;
	infos->time_ref = 0;
	infos->time2 = 0;
	infos->nb_philos = ft_atoi(av[1]);
	infos->time_to_die = ft_atoi(av[2]);
	infos->time_to_eat = ft_atoi(av[3]);
	infos->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		infos->nb_meals_max = ft_atoi(av[5]);
	else
		infos->nb_meals_max = 0;
	infos->onedead = 0;
	infos->current_nb_meal = 0;
}
