/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:07:57 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/24 17:23:28 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int main(int ac, char **av)
{
	t_info infos;

	ft_memset(&infos, 0, sizeof(infos));
	if (ac != 5)
	{
		printf("usage %s [nb_phils] [t_die] [t_eat] [t_sleep]\n", av[0]);
		return (0);
	}
	init_params(&infos, av);
	if (!(init_forks(&infos)))
		ft_error(MALLOC);
	if (!(init_threads(&infos)))
		ft_error(MALLOC);
	join_and_destroy(&infos);
}
