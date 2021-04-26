/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:02:02 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/05 11:52:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

void			init_forks(t_info *infos, t_philo *philos)
{
	(void)philos;
	sem_init(&infos->sem_stdout, 0, 1);
	sem_init(&infos->forks, 0, infos->nb_philos);
}
