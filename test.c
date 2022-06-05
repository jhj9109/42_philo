#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

void	time_print(void)
{
	struct timeval	unix;

	if (gettimeofday(&unix, NULL) == -1)
		return ;
	printf("tv_sec: %ld\ntv_usec: %d\n",
		unix.tv_sec, unix.tv_usec);
}

int	main(void)
{
	time_print();
	usleep(1000);
	time_print();
	usleep(1000);
	time_print();
	usleep(1000);

	return (-1);
}