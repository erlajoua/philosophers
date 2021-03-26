/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:23:23 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/25 10:31:02 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

unsigned int get_time(unsigned int start_usec, unsigned int start_sec)
{
	struct timeval current_time;
    int                sec;

    gettimeofday(&current_time, NULL);
    sec = current_time.tv_sec - start_sec;
    return (((unsigned int)(sec * 1000000 + current_time.tv_usec) - start_usec)
    / 1000);
}

unsigned int    get_time_start(int time)
{
    struct timeval    current_time;

    gettimeofday(&current_time, NULL);
    if (time == 0)
        return (current_time.tv_usec);
    else
        return (current_time.tv_sec);
    return (0);
}
