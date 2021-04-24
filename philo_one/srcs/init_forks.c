/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:02:02 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/05 11:52:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

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
		{
			printf("error init forks\n");
			return (NULL);
		}
		i++;
	}
	if (pthread_mutex_init(&infos->mutex_stdout, NULL))
		return (NULL);
	i = 0;
	while (i < infos->nb_philos)
	{
		philos[i].fork_l = &forks[i];
		philos[i].fork_r = &forks[(i + 1) % infos->nb_philos];
		i++;
	}
	return (forks);
}
