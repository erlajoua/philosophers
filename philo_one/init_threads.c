/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:07:56 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/24 22:05:53 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

struct s_willy
{
	t_philo *sp;
	t_info  *si;
};
typedef struct s_willy t_willy;

void	*test(void *arg)
{
	t_willy *mgl;
	t_info	*infos;
	t_philo *philos;

	mgl = (t_willy *)arg;
	infos = (t_info *)mgl->si;
	philos = (t_philo *)mgl->sp;

	printf("infos->nbphilo : %d\n", infos->nb_philos);
	printf("TEST index : %d\n", philos->id);
	return (NULL);
}

int		init_threads(t_info *infos, t_philo *philos)
{
	int			i;
	t_willy *prout;

	i = 0;
	prout = malloc(sizeof(t_willy));
	prout->si = infos;
	while (i < infos->nb_philos)
	{
		prout->sp = &philos[i];
		if (pthread_create(&(philos[i].th_phil), NULL, &test, prout))
			return (0);
		usleep(4000);
		i++;
	}
	return (1);
}
