/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:19:01 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/25 10:19:19 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_philo		*init_philos(t_info *infos)
{
	t_philo		*philos;
	int			i;

	i = 0;
	philos = malloc(sizeof(t_philo) * infos->nb_philos);
	if (!philos)
		return (NULL);
	memset(philos, 0, sizeof(t_philo));
	while (i < infos->nb_philos)
	{
		philos->last_meal = 0;
		philos[i].id = i;
		i++;
	}
	return (philos);
}
