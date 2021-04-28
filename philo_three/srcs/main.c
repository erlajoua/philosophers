/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:07:57 by erlajoua          #+#    #+#             */
/*   Updated: 2021/04/24 10:23:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

int		check_child(pid_t pid)
{
	int status;

	waitpid(pid, &status, WNOHANG);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 2)
			return (2);
	}
	return (0);
}

void	kill_all(t_philo *philos, t_info *infos)
{
	int i;

	i = 0;
	while (i < infos->nb_philos)
	{
		kill(philos[i].pid, SIGKILL);
		i++;
	}
}

void	check(t_info *infos, t_philo *philos)
{
	int		checker;
	int		i;

	i = 0;
	while (i < infos->nb_philos)
	{
		checker = check_child(philos[i].pid);
		if (checker == 2 || checker == 4)
			break ;
		i++;
		if (i == infos->nb_philos)
			i = 0;
	}
	kill_all(philos, infos);
	if (checker == 4)
	{
		sem_wait(infos->sem_stdout);
		printf("%6dms   all philosophers ate.\n",
		timer() - infos->time_ref);
		sem_post(infos->sem_stdout);
	}
}

int		main(int ac, char **av)
{
	t_info				infos;
	t_philo				*philos;

	infos.onedead = 0;
	memset(&infos, 0, sizeof(t_info));
	if (ac != 5 && ac != 6)
	{
		printf("usage %s 2 500 300 100 (?)\n", av[0]);
		return (0);
	}
	init_params(&infos, ac, av);
	if (!(philos = init_philos(&infos)))
		ft_error(MALLOC);
	init_forks(&infos);
	infos.time_ref = timer();
	if (!(init_process(&infos, philos)))
		ft_error(MALLOC);
	sem_close(infos.forks);
	sem_close(infos.sem_stdout);
	free(philos);
}
