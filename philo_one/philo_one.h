/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:19:49 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/24 17:24:12 by erlajoua         ###   ########.fr       */
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

/*struct					s_fork
{
	int					is_taken;
	pthread_mutex_t		mutex_f;
};
typedef struct s_fork	t_fork;*/

struct					s_philo
{
	pthread_t				th_phil;
	//t_fork					*p_f;
	int						i;
	int						nb_of_phils;
};
typedef struct s_philo	t_philo;

struct					s_info
{
	int					nb_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	pthread_mutex_t		*forks;
	t_philo				*philos;
};
typedef struct s_info	t_info;

int		init_threads(t_info *);
int		init_forks(t_info *);
int		ft_atoi(char *);
int		ft_strlen(char *);
void	init_params(t_info *, char **);
void	ft_putstr_fd(char *, int);
void	ft_error(int);
void	join_and_destroy(t_info *);
void	*ft_memset(void *, int, size_t);

#endif
