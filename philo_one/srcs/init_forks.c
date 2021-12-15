/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 10:59:55 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/29 10:59:55 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

static int			init_mutex_stdout(t_info *infos)
{
	if (pthread_mutex_init(&infos->mutex_stdout, NULL))
		return (0);
	return (1);
}

pthread_mutex_t		*init_forks(t_info *infos, t_philo *philos)
{
	int					i;
	pthread_mutex_t		*forks;

	forks = malloc(sizeof(pthread_mutex_t) * infos->nb_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < infos->nb_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL)
		|| (i == 0 && !init_mutex_stdout(infos)))
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
