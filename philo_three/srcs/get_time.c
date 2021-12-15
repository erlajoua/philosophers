/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:23:23 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/30 20:12:47 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

unsigned int	timer(long start)
{
	struct timeval	tv;
	int				i;

	gettimeofday(&tv, NULL);
	i = ((tv.tv_sec * 1000) + tv.tv_usec / 1000) - start;
	return (i);
}

void			ft_usleep(int duration)
{
	long start;
	long current;

	start = timer(0);
	current = start;
	while (duration > current - start)
	{
		usleep(100);
		current = timer(0);
	}
}
