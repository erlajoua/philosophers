/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:33:07 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/24 11:29:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

int		finish(t_info *infos)
{
	if (infos->onedead == 1)
	{
		sem_post(infos->sem_stdout);
		sem_post(infos->forks);
		sem_post(infos->forks);
		return (0);
	}
	return (1);
}

void	philo_eat(t_info *infos, t_philo *philos)
{
	if (infos->onedead == 1)
		return ;
	if (sem_wait(infos->forks)
	|| sem_wait(infos->forks))
		perror("error fourchette");
	sem_wait(infos->sem_stdout);
	if (!finish(infos))
		return ;
	//printf("%6dms   %d   has taken a fork\n",
	//timer() - infos->time_ref, philos->id + 1);
	ft_putnbr(timer() - infos->time_ref);
	ft_putstr_fd("ms   ", STDOUT_FILENO);
	ft_putnbr(philos->id + 1);
	ft_putstr_fd("   has taken a fork\n", STDOUT_FILENO);
	//
	//printf("%6dms   %d   has taken a fork\n",
	//	timer() - infos->time_ref, philos->id + 1);
	ft_putnbr(timer() - infos->time_ref);
	ft_putstr_fd("ms   ", STDOUT_FILENO);
	ft_putnbr(philos->id + 1);
	ft_putstr_fd("   has taken a fork\n", STDOUT_FILENO);
	//
	//printf("%6dms   %d   is eating\n",
	//timer() - infos->time_ref, philos->id + 1);
	ft_putnbr(timer() - infos->time_ref);
	ft_putstr_fd("ms   ", STDOUT_FILENO);
	ft_putnbr(philos->id + 1);
	ft_putstr_fd("   is eating\n", STDOUT_FILENO);
	//
	sem_post(infos->sem_stdout);
	philos->last_meal = timer() - infos->time_ref;
	usleep(infos->time_to_eat * T_MILLI);
	if (sem_post(infos->forks)
	|| sem_post(infos->forks))
		perror("error fourchette");
}
