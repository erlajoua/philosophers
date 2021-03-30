/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:07:56 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/30 18:08:16 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*test(void *arg)
{
	void	**args;
	int		i;
	t_info	*infos;
	t_philo *philos;

	args = (void **)arg;
	infos = (t_info *)args[0];
	philos = (t_philo *)args[1];

	i = 0;
	//printf("TEST index : %d\n", philos->id);
	//philos->start_usec = get_time_start(MICROSEC);
	//philos->start_sec = get_time_start(MILLESEC);
	infos->time_ref = get_time(infos->start_usec, infos->start_sec);
	philos->current_time = philos->last_meal;
	while (!infos->one_dead)
	{
		philos->last_meal = get_time(infos->start_usec, infos->start_sec);
		philo_eat(infos, philos);
		philo_sleep(infos, philos);
		philo_think(infos, philos);
		i++;
	}
	//printf("infos->nbphil0 : %d\n", infos->nb_philos);
	return (NULL);
}

int		init_threads(t_info *infos, t_philo *philos)
{
	int			i;
	void		*args[2];

	i = 0;
	args[0] = (void *)infos;
	while (i < infos->nb_philos)
	{
		args[1] = (void *)&philos[i];
		if (pthread_create(&(philos[i].th_phil), NULL, &test, args))
			return (0);
		usleep(5000);
		i++;
	}
	return (1);
}
