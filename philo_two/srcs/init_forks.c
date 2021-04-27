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

void			init_forks(t_info *infos)
{
	sem_unlink("stdout");
	sem_unlink("forks");
	infos->sem_stdout = sem_open("stdout", O_CREAT | O_EXCL, S_IRWXU, 1);
	infos->forks = sem_open("forks", O_CREAT | O_EXCL, S_IRWXU, infos->nb_philos);
}