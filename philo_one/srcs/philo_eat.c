/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:00:16 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/29 11:00:16 by erlajoua         ###   ########.fr       */
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
	printf("%6d   %d   has taken a fork\n",
	timer(philos->time_ref), philos->id + 1);
	printf("%6d   %d   has taken a fork\n",
		timer(philos->time_ref), philos->id + 1);
	printf("%6d   %d   is eating\n",
	timer(philos->time_ref), philos->id + 1);
	pthread_mutex_unlock(&infos->mutex_stdout);
	philos->last_meal = timer(philos->time_ref);
	ft_usleep(infos->time_to_eat);
	if (pthread_mutex_unlock(philos->fork_l)
	|| pthread_mutex_unlock(philos->fork_r))
		perror("error fourchette");
}
