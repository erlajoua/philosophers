/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:03:42 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/29 11:03:43 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void	philo_think(t_info *infos, t_philo *philos)
{
	if (infos->onedead == 1)
		return ;
	sem_wait(infos->sem_stdout);
	printf("%6d   %d   is thinking\n",
	timer(philos->time_ref), philos->id + 1);
	sem_post(infos->sem_stdout);
}
