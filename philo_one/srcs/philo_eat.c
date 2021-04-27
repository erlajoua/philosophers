/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:33:07 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/24 11:29:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

int		finish(t_info *infos, t_philo *philos)
{
	if (infos->onedead == 1)
	{
		pthread_mutex_unlock(&infos->mutex_stdout);
		pthread_mutex_unlock(philos->fork_l);
		pthread_mutex_unlock(philos->fork_r);
		return (0);
	}
	return (1);
}

void	philo_eat(t_info *infos, t_philo *philos)
{
	philos->nb_meals++;
	if (infos->onedead == 1)
		return ;
	if (pthread_mutex_lock(philos->fork_l)
	|| pthread_mutex_lock(philos->fork_r))
		perror("error fourchette");
	pthread_mutex_lock(&infos->mutex_stdout);
	if (!finish(infos, philos))
		return ;
	printf("%6dms   %d   has taken a fork\n",
	timer() - infos->time_ref, philos->id + 1);
	printf("%6dms   %d   has taken a fork\n",
		timer() - infos->time_ref, philos->id + 1);
	printf("%6dms   %d   is eating\n",
	timer() - infos->time_ref, philos->id + 1);
	pthread_mutex_unlock(&infos->mutex_stdout);
	philos->last_meal = timer() - infos->time_ref;
	usleep(infos->time_to_eat * T_MILLI);
	if (pthread_mutex_unlock(philos->fork_l)
	|| pthread_mutex_unlock(philos->fork_r))
		perror("error fourchette");
}
