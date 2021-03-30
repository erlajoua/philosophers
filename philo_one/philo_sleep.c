/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:59:13 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/30 18:10:40 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_sleep(t_info *infos, t_philo *philos)
{
	printf("[%ums] %d is sleeping\n", infos->time_ref, philos->id + 1);
	usleep(infos->time_to_sleep * T_MILLI);
	infos->time_ref = get_time(infos->start_usec, infos->start_sec);
}

