#include "philo.h"

long long	get_ms(t_args *x)
{
	struct timeval	unix;

	if (gettimeofday(&unix, NULL) == -1)
		exit_invalid(x, "Error\n", "Fail to func gettimeofdat!\n");
	return (unix.tv_sec * 1000 - unix.tv_usec / 1000);
}

void	j_sleep(t_args *x, long long ms)
{
	while (get_ms(x) <= ms)
		usleep(100);//작은 값으로 잘 설정하자.
}

bool	is_over(struct timeval unix1, struct timeval unix2, long long ms)
{
	return (((unix2.tv_sec - unix1.tv_sec) * 1000 + (unix2.tv_usec - unix1.tv_usec) / 1000) >= ms);
}