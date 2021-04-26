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

#include "../philo_one.h"

int		main(int ac, char **av)
{
	t_info				infos;
	t_philo				*philos;
	pthread_mutex_t		*forks;

	infos.onedead = 0;
	memset(&infos, 0, sizeof(t_info));
	if (ac != 5 && ac != 6)
	{
		printf("usage %s 2 500 300 100 (?)\n", av[0]);
		return (0);
	}
	init_params(&infos, ac, av);
	if (!(philos = init_philos(&infos)))
		ft_error(MALLOC);
	if (!(forks = init_forks(&infos, philos)))
		ft_error(MALLOC);
	infos.time_ref = timer();
	if (!(init_threads(&infos, philos)))
		ft_error(MALLOC);
	join_and_destroy(&infos, forks);
	free(philos);
}
