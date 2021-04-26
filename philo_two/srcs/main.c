/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:07:57 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/24 10:23:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

int		main(int ac, char **av)
{
	t_info				infos;
	t_philo				*philos;

	infos.crever = 0;
	memset(&infos, 0, sizeof(t_info));
	if (ac != 5)
	{
		printf("usage %s 2 500 300 100 (?)\n", av[0]);
		return (0);
	}
	init_params(&infos, av);
	if (!(philos = init_philos(&infos)))
		ft_error(MALLOC);
	init_forks(&infos, philos);
	infos.time_ref = timer();
	if (!(init_threads(&infos, philos)))
		ft_error(MALLOC);
	//join_and_destroy(&infos, forks);
	sem_destroy(&infos.forks);
	free(philos);
}
