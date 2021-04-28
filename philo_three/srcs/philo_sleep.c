/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:59:13 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/05 11:52:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void	philo_sleep(t_info *infos, t_philo *philos)
{
	if (infos->onedead == 1)
		return ;
	sem_wait(infos->sem_stdout);
	printf("%6dms   %d   is sleeping\n",
	timer() - infos->time_ref, philos->id + 1);
	sem_post(infos->sem_stdout);
	usleep(infos->time_to_sleep * T_MILLI);
	printf("fini sleep de philo_eat [%d]\n", philos->id + 1);
}
