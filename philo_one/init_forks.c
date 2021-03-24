/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:02:02 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/24 17:23:15 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		init_forks(t_info *infos)
{
	infos->forks = malloc(sizeof(pthread_mutex_t) * infos->nb_philos);
	if (!infos->forks)
		return (0);
	return (1);
}
