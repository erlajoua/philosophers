/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:00:24 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/29 11:00:25 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	philo_think(t_info *infos, t_philo *philos)
{
	if (infos->onedead == 1)
		return ;
	pthread_mutex_lock(&infos->mutex_stdout);
	printf("%6d   %d   is thinking\n",
	timer(philos->time_ref), philos->id + 1);
	pthread_mutex_unlock(&infos->mutex_stdout);
}
