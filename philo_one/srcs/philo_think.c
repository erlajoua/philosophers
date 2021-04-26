/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:56:34 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/05 11:53:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	philo_think(t_info *infos, t_philo *philos)
{
	//if (infos->onedead == 1 || (int)infos->current_nb_meal >= infos->nb_philos)
	//	return ;
	pthread_mutex_lock(&infos->mutex_stdout);
	printf("%6dms   %d   is thinking\n",
	timer() - infos->time_ref, philos->id + 1);
	pthread_mutex_unlock(&infos->mutex_stdout);
}
