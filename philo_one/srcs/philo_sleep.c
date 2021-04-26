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

#include "../philo_one.h"

void	philo_sleep(t_info *infos, t_philo *philos)
{
	//if (infos->onedead == 1 || (int)infos->current_nb_meal >= infos->nb_philos)
	//	return ;
	pthread_mutex_lock(&infos->mutex_stdout);
	if ((int)infos->current_nb_meal >= infos->nb_philos)
		return ;
	printf("%6dms   %d   is sleeping\n",
	timer() - infos->time_ref, philos->id + 1);
	pthread_mutex_unlock(&infos->mutex_stdout);
	usleep(infos->time_to_sleep * T_MILLI);
}
