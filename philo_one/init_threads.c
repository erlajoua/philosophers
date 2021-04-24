/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:07:56 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/23 19:04:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*faucheuse(void *arg)
{
	void	**args;
	t_philo *philos;
	t_info	*infos;
	int		timing;

	args = (void **)arg;
	infos = (t_info *)args[0];
	philos = (t_philo *)args[1];
	usleep(infos->time_to_die * T_MILLI);
	timing = timer() - infos->time_ref;
	if (timing >= infos->time_to_die + philos->last_meal)
	{
		if (infos->crever != 1)
		{
			infos->crever = 1;
			pthread_mutex_lock(&infos->mutex_stdout);
			printf("[%6dms] |%d| is dead\n", timing, philos->id + 1);
			pthread_mutex_unlock(&infos->mutex_stdout);
		}
	}
	return (NULL);
}

void	*philosophers(void *arg)
{
	void	**args;
	int		i;
	t_info	*infos;
	t_philo *philos;
	pthread_t reaper;

	args = (void **)arg;
	infos = (t_info *)args[0];
	philos = (t_philo *)args[1];
	i = 0;
	pthread_create(&reaper, NULL, &faucheuse, arg);
	while (!infos->crever)
	{	
		pthread_detach(reaper);
		pthread_create(&reaper, NULL, &faucheuse, arg);
		philo_eat(infos, philos);
		philo_sleep(infos, philos);
		philo_think(infos, philos);
		i++;
	}
	infos->crever = 1;
	pthread_join(reaper, NULL);
	return (NULL);
}

void	check(t_info *infos, t_philo *philos)
{
	while (infos->crever != 1)
		usleep(1 * T_MILLI);
	if (infos->crever == 1)
	{
		for (int i = 0; i < infos->nb_philos; i++)
			pthread_join(philos[i].th_phil, NULL);
	}
}

int		init_threads(t_info *infos, t_philo *philos)
{
	int			i;
	void		*args[2];

	i = 0;
	args[0] = (void *)infos;
	infos->time_ref = timer();
	while (i < infos->nb_philos)
	{
		args[1] = (void *)&philos[i];
		if (pthread_create(&(philos[i].th_phil), NULL, &philosophers, args))
			return (0);
		usleep(30);
		i++;
	}
	check(infos, philos);
	return (1);
}
