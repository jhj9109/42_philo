#include "philo.h"

void	monitoring(t_args *x)
{
	int		i;

	while (true)
	{
		i = -1;
		while (++i < x->number_philo)
		{
			if (get_ms(x) > x->philos[i].last_eat + x->time_die)
			{
				x->finish = true;
				x->died = x->philos[i].id;
				pthread_mutex_unlock(&(x->print));
				/* ===== print about die ======== */
				exit_valid(x);
			}
		}		
	}
}
