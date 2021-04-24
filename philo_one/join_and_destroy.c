/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:13:44 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/23 18:58:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	join_and_destroy(t_info *infos, t_philo *philos, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while (i < infos->nb_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		if (i == infos->nb_philos - 1)
			free(forks);
		i++;
	}
}
