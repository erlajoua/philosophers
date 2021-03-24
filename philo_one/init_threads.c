/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:07:56 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/24 17:25:28 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*test(void *arg)
{
	t_philo *phil;

	phil = (t_philo *)arg;
	printf("TEST index : %d\n", phil->i);
	return (NULL);
}

int		init_threads(t_info *infos)
{
	int i;

	i = 0;
	infos->philos = malloc(sizeof(t_philo) * infos->nb_philos);
	if (!infos->philos)
		return (0);
	while (i < infos->nb_philos)
	{
		infos->philos[i].i = i;
		//infos->philos.th_phil = malloc(sizeof(pthread
		if (pthread_create(&infos->philos[i].th_phil, NULL, &test, &infos->philos[i]))
			return (0);
		i++;
	}
	return (1);
}
