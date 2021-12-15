/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:01:42 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/29 11:01:43 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

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
		sem_wait(infos->sem_stdout);
		if (infos->time2)
		{
			printf("%6d   all philosophers ate.\n",
			infos->time2);
		}
		sem_post(infos->sem_stdout);
	}
	if (infos->onedead || infos->current_nb_meal >= infos->nb_meals_max)
		philo_dead(infos, philos);
}

int		main(int ac, char **av)
{
	t_info				infos;
	t_philo				*philos;

	infos.onedead = 0;
	memset(&infos, 0, sizeof(t_info));
	if (ac != 5 && ac != 6)
	{
		printf("usage %s 2 500 300 100 (?)\n", av[0]);
		return (0);
	}
	if (!(init_params(&infos, ac, av)))
		ft_error(PARAMS);
	if (!(philos = init_philos(&infos)))
		ft_error(MALLOC);
	init_forks(&infos);
	if (!(init_threads(&infos, philos)))
		ft_error(MALLOC);
	sem_close(infos.forks);
	sem_close(infos.sem_stdout);
	free(philos);
}
