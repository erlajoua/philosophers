/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:07:56 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/05 11:45:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*faucheuse(void *arg)
{
	void	**args;
	t_philo *philos;
	t_info	*infos;

	args = (void **)arg;
	infos = (t_info *)args[0];
	philos = (t_philo *)args[1];
	usleep(infos->time_to_die * T_MILLI);

	if ((timer() - infos->time_ref) >= infos->time_to_die /*+ philos->last_meal*/)
	{
		pthread_mutex_lock(&infos->mutex_stdout);
		printf("[%6dms] |%d| is dead\n", timer() - infos->time_ref, philos->id + 1);
		infos->crever = 1;
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
	while (!infos->one_dead)
	{	
		pthread_create(&reaper, NULL, &faucheuse, args);
		philo_eat(infos, philos);
		philo_sleep(infos, philos);
		philo_think(infos, philos);
		pthread_detach(reaper);
		i++;
	}
	infos->crever = 1;
	pthread_detach(reaper);
	return (NULL);
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
	return (1);
}
