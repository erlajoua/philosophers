/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:33:07 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/05 11:34:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_eat(t_info *infos, t_philo *philos)
{
	//printf("arrive dans philo_eat avec l'id : %d\n", philos->id);
	if (pthread_mutex_lock(philos->fork_l) || pthread_mutex_lock(philos->fork_r))
	{
		printf("error mutex lock\n");
		return ;
	}
	ft_putnbr(timer() - infos->time_ref);
	ft_putstr_fd("|", STDOUT_FILENO);
	ft_putnbr(philos->id + 1);
	ft_putstr_fd("has taken a fork L\n", STDOUT_FILENO);
	//
	ft_putnbr(timer() - infos->time_ref);
	ft_putstr_fd("|", STDOUT_FILENO);
	ft_putnbr(philos->id + 1);
	ft_putstr_fd("has taken a fork R\n", STDOUT_FILENO);
	//
	ft_putnbr(timer() - infos->time_ref);
	ft_putstr_fd("|", STDOUT_FILENO);
	ft_putnbr(philos->id + 1);
	ft_putstr_fd("is eating\n", STDOUT_FILENO);
	usleep(infos->time_to_eat * T_MILLI);
	//
	if (pthread_mutex_unlock(philos->fork_r) || pthread_mutex_unlock(philos->fork_l))
	{
		printf("error mutex unlock\n");
		return ;
	}
	ft_putstr_fd("has left both forks\n", STDOUT_FILENO);
	//

	//printf("[%ums] %d left the fork L\n", timer() - infos->time_ref, philos->id + 1);
	//printf("[%ums] %d left the fork R\n", timer() - infos->time_ref, philos->id + 1);
}
