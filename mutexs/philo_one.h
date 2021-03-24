/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:19:49 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/19 22:10:24 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

struct					s_fork
{
	int					is_taken;
	pthread_mutex_t		mutex_f;
};
typedef struct s_fork	t_fork;

struct					s_philo
{
	pthread_t				*th_phil;
	t_fork					*p_f;
	int						index;
	int						nb_of_phils;
};
typedef struct s_philo	t_philo;

struct					s_info
{
	int					nb_of_phils;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	t_philo				*phil;	
};
typedef struct s_info	t_info;

int		ft_atoi(char *str);

#endif
