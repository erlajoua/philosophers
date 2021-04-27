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

void	check(t_info *infos, t_philo *philos)
{
	if (infos->nb_meals_max == 0)
	{
		philo_dead(infos, philos);
		return ;
	}
	while (!infos->onedead && (int)infos->current_nb_meal < infos->nb_philos)
		usleep(10);
	if ((!infos->onedead || infos->current_nb_meal >= infos->nb_meals_max))
	{
		usleep(1500 * T_MILLI);
		pthread_mutex_lock(&infos->mutex_stdout);
		if (infos->time2)
		{
			printf("%6dms   all philosophers ate.\n",
			infos->time2);
		}
		pthread_mutex_unlock(&infos->mutex_stdout);
	}
	if (infos->onedead || infos->current_nb_meal >= infos->nb_meals_max)
		philo_dead(infos, philos);
	
}

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
