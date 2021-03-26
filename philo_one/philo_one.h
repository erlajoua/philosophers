/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:19:49 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/26 18:13:50 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/time.h>

# define T_MILLI 1000

enum
{
	MALLOC
};

enum
{
	MICROSEC,
	MILLESEC
};

struct					s_philo
{
	pthread_t			th_phil;
	pthread_mutex_t		*fork_l;
	pthread_mutex_t		*fork_r;
	int					id;
	unsigned int		last_meal;
	unsigned int		start_usec;
	unsigned int		start_sec;
	unsigned int		current_time;
};
typedef struct s_philo	t_philo;

struct					s_info
{
	int					nb_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					one_dead;
	unsigned int		time_ref;
};
typedef struct s_info	t_info;

int					init_threads(t_info *infos, t_philo *philos);
int					ft_atoi(char *);
int					ft_strlen(char *str);
void				init_params(t_info *infos, char **av);
void				ft_putstr_fd(char *str, int fd);
void				ft_error(int index);
void				philo_eat(t_info *infos, t_philo *philos);
void				philo_sleep(t_info *infos, t_philo *philos);
void				philo_think(t_info *infos, t_philo *philos);
void				join_and_destroy(t_info *infos, t_philo *philos, pthread_mutex_t *forks);
void				*ft_memset(void *b, int c, size_t len);
unsigned int		get_time(unsigned int start_usec, unsigned int start_sec);
unsigned int		get_time_start(int time);
t_philo				*init_philos(t_info *infos);
pthread_mutex_t		*init_forks(t_info *infos, t_philo *philos);

#endif
