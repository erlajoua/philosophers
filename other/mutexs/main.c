/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:19:44 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/21 10:22:25 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*philo_action(void *arg)
{
	t_philo *p = (t_philo *)arg;
	
	printf("je suis un p : %d\n", p->index);
	if (p->p_f[p->index].is_taken == 0 && p->p_f[(p->index + 1) % p->nb_of_phils].is_taken == 0)
	{
		pthread_mutex_lock(&(p->p_f[p->index].mutex_f));
		pthread_mutex_lock(&(p->p_f[p->index + 1 % p->nb_of_phils].mutex_f));
		p->p_f[p->index].is_taken = 1;
		p->p_f[p->index].is_taken = 1;
		printf("JE PRENDS MES FOURCHETTES [%d] et je vais bouffer\n", p->index);
		usleep(1500000);
		p->p_f[(p->index + 1) % p->nb_of_phils].is_taken = 1;
		pthread_mutex_unlock(&(p->p_f[p->index].mutex_f));
		pthread_mutex_unlock(&(p->p_f[(p->index + 1) % p->nb_of_phils].mutex_f));
		p->p_f[p->index].is_taken = 0;
		p->p_f[p->index].is_taken = 0;
		printf("JE RELACHE MES FOURCHETTES [%d]\n", p->index);
	}
	return (NULL);
}

int		main(int ac, char **av)
{
	t_info				infos;
	t_fork				*forks;

	if (ac != 5)
	{
		printf("usage %s [nb_phils] [t_die] [t_eat] [t_sleep]\n", av[0]);
		return (0);
	}
	infos.nb_of_phils = ft_atoi(av[1]);
	infos.time_to_die = ft_atoi(av[2]);
	infos.time_to_eat = ft_atoi(av[3]);
	infos.time_to_sleep = ft_atoi(av[4]);
	forks = malloc(sizeof(t_fork) * (infos.nb_of_phils));
	if (!forks)
		return (-1);
	for (int i = 0; i < infos.nb_of_phils; ++i)
	{
		pthread_mutex_init(&forks[i].mutex_f, NULL);
		forks[i].is_taken = 0;
	}
	infos.phil = malloc(sizeof(t_philo) * (infos.nb_of_phils));
	if (!infos.phil)
		return (-1);
	for (int i = 0; i < infos.nb_of_phils; i++)
	{
		infos.phil[i].th_phil = malloc(sizeof(pthread_t));
		infos.phil[i].p_f = forks;
		infos.phil[i].nb_of_phils = infos.nb_of_phils;
	}
	if (!infos.phil->th_phil)
		return (-1);
	for (int i = 0; i < infos.nb_of_phils; i++)
	{
		infos.phil[i].index = i;
		pthread_create(&infos.phil->th_phil[i], NULL, &philo_action, &infos.phil[i]);
		usleep(100);
	}
	for (int i = 0; i < infos.nb_of_phils; i++)
	{
		pthread_join((infos.phil)->th_phil[i], NULL);
	}
	for (int i = 0; i < infos.nb_of_phils; i++)
	{
		pthread_mutex_destroy(&forks[i].mutex_f);
	}
	return (0);
}
