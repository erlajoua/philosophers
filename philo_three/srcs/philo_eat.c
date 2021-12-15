/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:03:32 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/29 11:03:33 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

int		finish(t_info *infos)
{
	if (infos->onedead == 1)
	{
		sem_post(infos->sem_stdout);
		sem_post(infos->forks);
		sem_post(infos->forks);
		return (0);
	}
	return (1);
}

void	philo_eat(t_info *infos, t_philo *philos)
{
	if (infos->onedead == 1)
		return ;
	if (sem_wait(infos->forks)
	|| sem_wait(infos->forks))
		perror("error fourchette");
	sem_wait(infos->sem_stdout);
	if (!finish(infos))
		return ;
	printf("%6d   %d   has taken a fork\n",
	timer(philos->time_ref), philos->id + 1);
	printf("%6d   %d   has taken a fork\n",
		timer(philos->time_ref), philos->id + 1);
	printf("%6d   %d   is eating\n",
	timer(philos->time_ref), philos->id + 1);
	sem_post(infos->sem_stdout);
	philos->last_meal = timer(philos->time_ref);
	ft_usleep(infos->time_to_eat);
	if (sem_post(infos->forks)
	|| sem_post(infos->forks))
		perror("error fourchette");
}
