/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:07:56 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/24 11:29:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	*faucheuse(void *arg)
{
	void			**args;
	t_philo			*philos;
	t_info			*infos;
	unsigned int	timing;

	args = (void **)arg;
	infos = (t_info *)args[0];
	philos = (t_philo *)args[1];
	usleep(infos->time_to_die * T_MILLI);
	timing = timer() - infos->time_ref;
	if (infos->onedead != 1 && timing - philos->last_meal >= infos->time_to_die)
	{
		if (infos->onedead != 1)
		{
			infos->onedead = 1;
			pthread_mutex_lock(&infos->mutex_stdout);
			printf("%6dms   %d   died\n", timing, philos->id + 1);
			pthread_mutex_unlock(&infos->mutex_stdout);
		}
	}
	return (NULL);
}

void	*philosophers(void *arg)
{
	void		**args;
	t_info		*infos;
	t_philo		*philos;
	pthread_t	reaper;

	args = (void **)arg;
	infos = (t_info *)args[0];
	philos = (t_philo *)args[1];
	pthread_create(&reaper, NULL, &faucheuse, arg);
	while (!infos->onedead && (int)infos->current_nb_meal < infos->nb_philos)
	{
		pthread_detach(reaper);
		pthread_create(&reaper, NULL, &faucheuse, arg);
		philo_eat(infos, philos);
		philo_sleep(infos, philos);
		philo_think(infos, philos);
		philos->nb_meals++;
		if (philos->nb_meals == infos->nb_meals_max)
			infos->current_nb_meal++;
	}
	pthread_join(reaper, NULL);
	return (NULL);
}

void	philo_dead(t_info *infos, t_philo *philos)
{
	int i;

	i = 0;
	while (infos->onedead != 1)
		usleep(10);
	if (infos->onedead == 1)
	{
		while (i < infos->nb_philos)
		{
			pthread_join(philos[i].th_phil, NULL);
			i++;
		}
	}
}

void	check(t_info *infos, t_philo *philos)
{
	if (infos->nb_meals_max == 0)
	{
		philo_dead(infos, philos);
		return ;
	}
	while (!infos->onedead && (int)infos->current_nb_meal < infos->nb_philos)
		usleep(10);
	if (infos->onedead && infos->current_nb_meal >= infos->nb_meals_max)
	{
		pthread_mutex_lock(&infos->mutex_stdout);
			printf("%6dms   all phisolophers ate.\n",
			timer() - infos->time_ref);
		pthread_mutex_unlock(&infos->mutex_stdout);
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
