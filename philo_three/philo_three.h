/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                        :+:    :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:19:49 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/24 11:53:11 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <semaphore.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

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
	int					id;
	unsigned int		last_meal;
	unsigned int		nb_meals;
	pid_t				pid;
};
typedef struct s_philo	t_philo;

struct					s_info
{
	int					nb_philos;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	unsigned int		nb_meals_max;
	unsigned int		current_nb_meal;
	unsigned int		time_ref;
	unsigned int		time2;
	sem_t				*sem_stdout;
	sem_t				*forks;
	int					onedead;
};
typedef struct s_info	t_info;

int						init_process(t_info *infos, t_philo *philos, int *general);
int						ft_atoi(char *str);
int						ft_strlen(char *str);
void					init_params(t_info *infos, int ac, char **av);
void					ft_putstr_fd(char *str, int fd);
void					ft_error(int index);
void					philo_eat(t_info *infos, t_philo *philos);
void					philo_sleep(t_info *infos, t_philo *philos);
void					philo_think(t_info *infos, t_philo *philos);
void					join_and_destroy(t_info *infos, pthread_mutex_t *forks);
void					*ft_memset(void *b, int c, size_t len);
void					ft_putnbr(int nb);
void					check(t_info *infos, t_philo *philos, int *general);
unsigned int			timer(void);
t_philo					*init_philos(t_info *infos);
void					init_forks(t_info *infos);
void					philo_dead(t_info *infos, t_philo *philos);

#endif
