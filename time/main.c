# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/time.h>

#define ONE_MILLISEC     1000
# define MICROSEC    0
# define MILLESEC    1

# define TIME_TO_EAT 5 //s
# define TIME_TO_DIE 4.8

unsigned int last_meal;
unsigned int mytime;

unsigned int get_time(unsigned int start_usec, unsigned int start_sec)
{
	struct timeval current_time;
    int                sec;

    gettimeofday(&current_time, NULL);
    sec = current_time.tv_sec - start_sec;
    return (((unsigned int)(sec * 1000000 + current_time.tv_usec) - start_usec)
    / ONE_MILLISEC);
}

unsigned int    get_time_start(int time)
{
    struct timeval    current_time;

    gettimeofday(&current_time, NULL);
  	//printf("===\nUSEC:%ld\n SEC:%ld\n===\n", current_time.tv_usec, current_time.tv_sec);
    if (time == 0)
        return (current_time.tv_usec);
    else
        return (current_time.tv_sec);
    return (0);
}

void	*bonjour(void *arg)
{
	unsigned int *tab_sec;

	tab_sec = (unsigned int *)arg;
	//usleep(TIME_TO_WAIT);
	printf("entrain de manger\n");
	usleep(TIME_TO_EAT * 1000000);
	last_meal = get_time(tab_sec[0], tab_sec[1]);
	//printf("%u\n", last_meal);
	return (NULL);
}

void	*manger(void *arg)
{
	unsigned int *tab_sec;

	tab_sec = (unsigned int *)arg;
	printf("checker time...\n");
	usleep(TIME_TO_DIE * 1000000); //usleep(1)     1microseconde 1*10^-6    5420 millisecondes 5420000
	mytime = get_time(tab_sec[0], tab_sec[1]);
	return NULL;
}

int main(void)
{
	pthread_t th[2];
	unsigned int *tab_sec;

	tab_sec = malloc(sizeof(unsigned int) * 2);
	tab_sec[0] = get_time_start(MICROSEC); //usec 0
	tab_sec[1] = get_time_start(MILLESEC); //sec 1

	last_meal = get_time(tab_sec[0], tab_sec[1]);
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			if (pthread_create(&th[i], NULL, &bonjour, tab_sec))
				perror("Failed to create thread");
		}
		else
		{
			if (pthread_create(&th[i], NULL, &manger, tab_sec))
				perror("Failed to create thread");
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (pthread_join(th[i], NULL))
			perror("Failed to join thread");
	}
	if (mytime >= last_meal)
		printf("T'as réussi à bouffer gros porc\n");
	else
		printf("T'es crevé enculer\n");
	return 0;
}
