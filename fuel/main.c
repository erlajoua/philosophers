/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:00:13 by erlajoua          #+#    #+#             */
/*   Updated: 2021/03/25 15:15:56 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//let's go philosophers

#include "philo_one.h"
#include <pthread.h>
#include <errno.h>

pthread_mutex_t mutexFuel;
int fuel = 0;

void	*fuel_filling(void *arg)
{
	for (int i = 0; i < 5; i++)
	{
		pthread_mutex_lock(&mutexFuel);
		fuel += 15;
		printf("Filled fuel... %d\n", fuel);
		sleep(1);
	}
	return (NULL);
}

void	*car(void *arg)
{
	while (fuel < 40)
	{
		printf("No fuel. Waiting...\n");
		sleep(1);
	}
	pthread_mutex_lock(&mutexFuel); //this lock
	fuel -= 40;
	printf("Got fuel. Now left: %d\n", fuel);
	pthread_mutex_unlock(&mutexFuel);
	return (NULL);
}

int main(void)
{
	pthread_t th[2];
	pthread_mutex_init(&mutexFuel, NULL); 
	for (int i = 0; i < 2; i++)
	{
		if (i == 1)
		{
			if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0)
				perror("Failed to create thread");
		}
		else
		{
			if (pthread_create(&th[i], NULL, &car, NULL) != 0)
				perror("Failed to create thread");
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (pthread_join(th[i], NULL))
			perror("Failed to join thread");
	}
	pthread_mutex_destroy(&mutexFuel);
	return (0);
}
