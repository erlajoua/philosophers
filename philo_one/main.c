/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:07:57 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/24 20:59:37 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_philo		*init_philos(t_info *infos)
{
	t_philo		*philos;
	int			i;

	i = 0;
	philos = malloc(sizeof(t_philo) * infos->nb_philos);
	if (!philos)
		return (NULL);
	ft_memset(philos, 0, sizeof(t_philo *));
	while (i < infos->nb_philos)
	{
		philos[i].id = i;
		i++;
	}
	return (philos);
}

int		main(int ac, char **av)
{
	t_info				infos;
	t_philo				*philos;
	pthread_mutex_t		*forks;

	ft_memset(&infos, 0, sizeof(t_info));
	if (ac != 5)
	{
		printf("usage %s [nb_phils] [t_die] [t_eat] [t_sleep]\n", av[0]);
		return (0);
	}
	init_params(&infos, av);
	philos = init_philos(&infos);
	if (!(forks = init_forks(&infos, philos)))
		ft_error(MALLOC);
	if (!(init_threads(&infos, philos)))
		ft_error(MALLOC);
	join_and_destroy(&infos, philos, forks);
}
