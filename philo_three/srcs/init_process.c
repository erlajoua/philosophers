/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:03:13 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/29 11:27:42 by erlajoua         ###   ########.fr       */
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
	ft_usleep(infos->time_to_die);
	timing = timer(philos->time_ref);
	if (timing - philos->last_meal >= infos->time_to_die)
	{
		if (infos->onedead != 1)
		{
			infos->onedead = 1;
			sem_wait(infos->sem_stdout);
			printf("%6d   %d   died\n", timing, philos->id + 1);
		}
		exit(2);
	}
	return (NULL);
}

void	exit_philo(t_philo *philos, t_info *infos, pthread_t *reaper)
{
	pthread_detach(*reaper);
	if (philos->nb_meals >= infos->nb_meals_max)
		exit(3);
	exit(2);
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
	philos->time_ref = timer(0);
	while (!infos->onedead && (infos->nb_meals_max == 0 ||
	philos->nb_meals < infos->nb_meals_max))
	{
		pthread_detach(reaper);
		pthread_create(&reaper, NULL, &faucheuse, arg);
		philo_eat(infos, philos);
		philos->nb_meals++;
		if (infos->nb_meals_max != 0 && philos->nb_meals >= infos->nb_meals_max)
			break ;
		philo_sleep(infos, philos);
		philo_think(infos, philos);
	}
	exit_philo(philos, infos, &reaper);
	return (NULL);
}

int		init_process(t_info *infos, t_philo *philos, int *general)
{
	int			i;
	void		*args[2];

	i = 0;
	args[0] = (void *)infos;
	philos->time_ref = timer(philos->time_ref);
	while (i < infos->nb_philos)
	{
		args[1] = (void *)&philos[i];
		philos[i].pid = fork();
		if (philos[i].pid == 0)
			philosophers(args);
		usleep(10);
		i++;
	}
	check(infos, philos, general);
	return (1);
}
