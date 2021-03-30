/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:59:13 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/30 20:15:46 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_sleep(t_info *infos, t_philo *philos)
{
	printf("[%ums] %d is sleeping\n", timer() - infos->time_ref, philos->id + 1);
	usleep(infos->time_to_sleep * T_MILLI);
}

