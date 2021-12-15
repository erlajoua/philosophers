/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:01:16 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/29 11:01:17 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

void	philo_sleep(t_info *infos, t_philo *philos)
{
	if (infos->onedead == 1)
		return ;
	sem_wait(infos->sem_stdout);
	printf("%6d   %d   is sleeping\n",
	timer(philos->time_ref), philos->id + 1);
	sem_post(infos->sem_stdout);
	ft_usleep(infos->time_to_sleep);
}
