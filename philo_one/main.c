/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:19:44 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/19 16:39:47 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

#define N 5

void	*philo_action(void *arg)
{
	t_info *infos = (t_info *)arg;
	
	printf("time to die : %d\n", infos->time_to_die);
	printf("je suis un philosophers of index : %d\n", infos->philosophers->th_phil[5]);
	return (NULL);
}

int		main(int ac, char **av)
{
	t_info				infos;

	if (ac != 5)
	{
		printf("usage %s [nb_phils] [t_die] [t_eat] [t_sleep]\n", av[0]);
		return (0);
	}
	infos.nb_of_phils = ft_atoi(av[1]);
	infos.time_to_die = ft_atoi(av[2]);
	infos.time_to_eat = ft_atoi(av[3]);
	infos.time_to_sleep = ft_atoi(av[4]);
	infos.philosophers = malloc(sizeof(t_philo) * (infos.nb_of_phils));
	if (!infos.philosophers)
		return (-1);
	infos.fork = malloc(sizeof(pthread_mutex_t) * infos.nb_of_phils);
	if (!infos.fork)
		return (-1);
	for (int i = 0; i < infos.nb_of_phils; i++)
	{
		pthread_mutex_init(&infos.fork[i], NULL);
	}
	infos.philosophers->th_phil = malloc(sizeof(pthread_t) * (infos.nb_of_phils));
	if (!infos.philosophers->th_phil)
		return (-1);
	for (int i = 0; i < infos.nb_of_phils; i++)
	{
		pthread_create(&infos.philosophers->th_phil[i], NULL, &philo_action, &infos);
	}
	for (int i = 0; i < infos.nb_of_phils; i++)
	{
		pthread_join((infos.philosophers)->th_phil[i], NULL);
	}
	for (int i = 0; i < infos.nb_of_phils; i++)
	{
		pthread_mutex_destroy(&infos.fork[i]);
	}
	return (0);
}
