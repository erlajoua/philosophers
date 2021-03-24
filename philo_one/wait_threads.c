/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:13:44 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/24 17:18:10 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	join_and_destroy(t_info *infos)
{
	int i;

	i = 0;
	while (i < infos->nb_philos)
	{
		pthread_join(infos->philos[i].th_phil, NULL);
		pthread_mutex_destroy(&infos->forks[i]);
		i++;
	}
}
