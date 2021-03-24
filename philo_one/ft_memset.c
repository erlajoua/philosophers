#include "philo_one.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = (unsigned char *)b;
	while (len > 0)
	{
		str[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}
