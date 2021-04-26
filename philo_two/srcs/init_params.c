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

#include "../philo_two.h"

void	init_params(t_info *infos, char **av)
{
	infos->crever = 0;
	infos->time_ref = 0;
	infos->nb_philos = ft_atoi(av[1]);
	infos->time_to_die = ft_atoi(av[2]);
	infos->time_to_eat = ft_atoi(av[3]);
	infos->time_to_sleep = ft_atoi(av[4]);
	infos->one_dead = 0;
}
