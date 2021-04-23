/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:07:57 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/05 11:28:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	check(t_info *infos, t_philo *philos, pthread_mutex_t *forks)
{
	int tmp;

	tmp = 0;
	while (infos->crever != 1)
		usleep(1 * T_MILLI);
	if (infos->crever == 1)
	{
		tmp = 1;
		for (int i = 0; i < infos->nb_philos; i++)
			pthread_detach(philos[i].th_phil);
	}
}

int		main(int ac, char **av)
{
	t_info				infos;
	t_philo				*philos;
	pthread_mutex_t		*forks;

	infos.crever = 0;
	memset(&infos, 0, sizeof(t_info));
	if (ac != 5)
	{
		printf("usage %s [nb_phils] [t_die] [t_eat] [t_sleep]\n", av[0]);
		return (0);
	}
	init_params(&infos, av);
	if (!(philos = init_philos(&infos)))
		ft_error(MALLOC);
	if (!(forks = init_forks(&infos, philos)))
		ft_error(MALLOC);
	infos.time_ref = timer();
	if (!(init_threads(&infos, philos)))
		ft_error(MALLOC);
	check(&infos, philos, forks);
	join_and_destroy(&infos, philos, forks);
}
