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
	//printf("%6dms   %d   is sleeping\n",
	//timer() - infos->time_ref, philos->id + 1);
	ft_putnbr(timer() - infos->time_ref);
	ft_putstr_fd("ms   ", STDOUT_FILENO);
	ft_putnbr(philos->id + 1);
	ft_putstr_fd("   is sleeping\n", STDOUT_FILENO);
	//
	sem_post(infos->sem_stdout);
	usleep(infos->time_to_sleep * T_MILLI);
}
