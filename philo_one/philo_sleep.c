/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:59:13 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/25 11:03:20 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	philo_sleep(t_info *infos, t_philo *philos)
{
	printf("%d is sleeping\n", philos->id);
	usleep(infos->time_to_sleep * T_MILLI);
}

