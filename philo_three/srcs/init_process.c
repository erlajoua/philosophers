/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:07:56 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/24 11:29:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

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
		if (infos->onedead != 1 &&
		(int)infos->current_nb_meal < infos->nb_philos)
		{
			infos->onedead = 1;
			sem_wait(infos->sem_stdout);
			printf("%6dms   %d   died\n", timing, philos->id + 1);
			sem_post(infos->sem_stdout);
		}
		exit(2);
	}
	return (NULL);
}

void	check_death(pthread_t *reaper, t_info *infos)
{
	if (!infos->onedead && infos->time2 == 0)
		infos->time2 = timer() - infos->time_ref;
	pthread_join(*reaper, NULL);
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
		if (philos->nb_meals == infos->nb_meals_max)
			infos->current_nb_meal++;
		if ((int)infos->current_nb_meal >= infos->nb_philos)
			break ;
		philo_sleep(infos, philos);
		if ((int)infos->current_nb_meal >= infos->nb_philos)
			break ;
		philo_think(infos, philos);
	}
	check_death(&reaper, infos);
	if ((int)infos->current_nb_meal >= infos->nb_philos)
		exit(4);
	exit(2);
	return (NULL);
}

void	philo_dead(t_info *infos, t_philo *philos)
{
	int i;

	i = 0;
	while (infos->onedead != 1 && infos->current_nb_meal < infos->nb_meals_max)
		usleep(10);
	if (infos->onedead == 1 || infos->current_nb_meal >= infos->nb_meals_max)
	{
		while (i < infos->nb_philos)
		{
			pthread_join(philos[i].th_phil, NULL);
			i++;
		}
	}
}

int		init_process(t_info *infos, t_philo *philos)
{
	int			i;
	void		*args[2];

	i = 0;
	args[0] = (void *)infos;
	infos->time_ref = timer();
	while (i < infos->nb_philos)
	{
		args[1] = (void *)&philos[i];
		philos[i].pid = fork();
		if (philos[i].pid == 0)
			philosophers(args);
		usleep(30);
		i++;
	}
	check(infos, philos);
	return (1);
}
