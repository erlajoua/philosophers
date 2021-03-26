/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:33:07 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/25 14:23:53 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_eat(t_info *infos, t_philo *philos)
{
	//printf("arrive dans philo_eat avec l'id : %d\n", philos->id);
	if (pthread_mutex_lock(philos->fork_l) || pthread_mutex_lock(philos->fork_r))
	{
		printf("error mutex lock\n");
		return ;
	}
	printf("[%ums] %d has taken fork L\n", philos->last_meal, philos->id);
	printf("[%ums] %d has taken fork R\n", philos->last_meal, philos->id);
	printf("[%ums] %d is eating\n", get_time(philos->start_usec, philos->start_sec), philos->id);
	usleep(infos->time_to_eat * T_MILLI);
	philos->last_meal = get_time(philos->start_usec, philos->start_sec);
	//printf("TIME X : %d\n", philos->last_meal - infos->time_ref);
	printf("[%ums] %d left the fork L\n", philos->last_meal, philos->id);
	if (pthread_mutex_unlock(philos->fork_r) || pthread_mutex_unlock(philos->fork_l))
	{
		printf("error mutex unlock\n");
		return ;
	}
	printf("[%ums] %d left the fork R\n", philos->last_meal, philos->id);
}
