/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:19:49 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/24 20:59:19 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

enum
{
	MALLOC
};

struct					s_philo
{
	pthread_t			th_phil;
	pthread_mutex_t		*fork_l;
	pthread_mutex_t		*fork_r;
	int					id;
};
typedef struct s_philo	t_philo;

struct					s_info
{
	int					nb_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
};
typedef struct s_info	t_info;

int					init_threads(t_info *infos, t_philo *philos);
int					ft_atoi(char *);
int					ft_strlen(char *str);
void				init_params(t_info *infos, char **av);
void				ft_putstr_fd(char *str, int fd);
void				ft_error(int index);
void				join_and_destroy(t_info *infos, t_philo *philos, pthread_mutex_t *forks);
void				*ft_memset(void *b, int c, size_t len);
pthread_mutex_t		*init_forks(t_info *infos, t_philo *philos);

#endif
