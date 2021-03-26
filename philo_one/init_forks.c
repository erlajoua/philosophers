/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:02:02 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/25 10:56:27 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

pthread_mutex_t		*init_forks(t_info *infos, t_philo *philos)
{
	int					i;
	pthread_mutex_t		*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * infos->nb_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < infos->nb_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL))
			return (NULL);
		i++;
	}
	i = 0;
	while (i < infos->nb_philos)
	{
		philos[i].fork_l = &forks[i];
		philos[i].fork_r = &forks[(i + 1) % infos->nb_philos];
		i++;
	}
	return (forks);
}
