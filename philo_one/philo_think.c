/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:56:34 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/05 11:34:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_think(t_info *infos, t_philo *philos)
{
	ft_putnbr(timer() - infos->time_ref);
	ft_putstr_fd("|", STDOUT_FILENO);
	ft_putnbr(philos->id + 1);
	ft_putstr_fd("is thinking\n", STDOUT_FILENO);
	//printf("[%ums] %d is thinking\n", timer() - infos->time_ref, philos->id + 1);
	usleep(4000 * T_MILLI);
}
