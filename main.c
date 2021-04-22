# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/time.h>

# define T_MILLI 1000

//change ici 

# define EATTIME 600
# define SLEEPTIME 120
# define DIETIME 700

//


struct s_philo
{
	int id;
};
typedef struct s_philo t_philo;

//

unsigned int time_ref;
unsigned int last_meal;
unsigned int crever = 0;

pthread_mutex_t mystdout;
pthread_mutex_t fourchette;

unsigned int	timer(void)
{
	struct timeval	tv;
	int				i;

	gettimeofday(&tv, NULL);
	i = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (i);
}

void	*faucheuse(void *args)
{
	t_philo *philos;

	philos = (t_philo *)args;
	usleep(DIETIME * T_MILLI);
	if ((timer() - time_ref) - last_meal >=  DIETIME) //1500
	{
		pthread_mutex_lock(&mystdout);
		printf("\n/!\\ [%dms] | %d est mort\n", timer() - time_ref, philos->id);
		crever = 1;
	}
	return (NULL);
}

void    peat(int index)
{
		pthread_mutex_lock(&fourchette);
		pthread_mutex_lock(&mystdout);
		printf("() [%dms] | %d has taken forks\n", (timer() - time_ref), index + 1);
		printf("() [%dms] | %d is eating\n", (timer() - time_ref), index + 1);
		pthread_mutex_unlock(&mystdout);
		last_meal = timer() - time_ref;
		usleep(EATTIME * T_MILLI);

		//pthread_mutex_lock(&mystdout);
		//printf("() [%dms] | %d a fini de manger\n", (timer() - time_ref), index + 1);
		//pthread_mutex_unlock(&mystdout);
		pthread_mutex_unlock(&fourchette);
} 

void	psleep(int index)
{
	pthread_mutex_lock(&mystdout);
	printf("== [%dms] | %d is sleeping\n", (timer() - time_ref), index + 1);
	usleep(SLEEPTIME * T_MILLI);
	pthread_mutex_unlock(&mystdout);
	//printf("== [%dms] | %d a fini de dormir\n", (timer() - time_ref), index + 1);
	//pthread_mutex_unlock(&mystdout);
}

void	pthink(int index)
{
	printf("$$ [%dms] | %d is thinking\n", (timer() - time_ref), index + 1);
}


void	*philosophers(void *args)
{
	pthread_t reaper;
	t_philo *philos = (t_philo *)args;
	
	while (crever != 1)
	{
		pthread_detach(reaper);
		pthread_create(&reaper, NULL, &faucheuse, philos);

		peat(philos->id);
		psleep(philos->id);
		pthink(philos->id);
	}
	pthread_detach(reaper);
	return (NULL);
}

# define NUMBER_PHILOS 2

void check(pthread_t *th)
{
	while (crever != 1)
		usleep(1 * T_MILLI);
	if (crever == 1)
	{
		for (int i = 0; i < NUMBER_PHILOS; i++)
		{
			pthread_detach(th[i]);
		}
	}
}

int main(void)
{
	pthread_t th[NUMBER_PHILOS];

	//mutexs init
	pthread_mutex_init(&mystdout, NULL);
	pthread_mutex_init(&fourchette, NULL);

	//init philo
	t_philo *philos = malloc(sizeof(t_philo) * 2);
	if (!philos)
		return (-4);
	time_ref = timer();
	for (int i = 0; i < NUMBER_PHILOS; i++)
	{
		philos[i].id = i;
		pthread_create(&th[i], NULL, &philosophers, &philos[i]);
		usleep(30);
	}
	check(th);
	pthread_mutex_destroy(&mystdout);
	return (0);
}

