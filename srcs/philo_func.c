#include "philo.h"

static void	_thinking(t_philo *p)
{
	t_args	*x;

	x = p->x;
	/* ===== print about thinking ======== */
	// earn two fork
	pthread_mutex_lock(&(x->forks[p->l]));
	pthread_mutex_lock(&(x->forks[p->r]));
}

static void	_eating(t_philo *p)
{
	t_args	*x;

	x = p->x;
	// update last_eat
	p->last_eat = get_ms(p->x);
	/* ===== print about eat ======== */
	// while (to_eat) sleep
	j_sleep(x, p->last_eat + x->time_eat);
	// drop fork
	pthread_mutex_unlock(&(x->forks[p->l]));
	pthread_mutex_unlock(&(x->forks[p->r]));
}

static void	_sleeping(t_philo *p)
{
	t_args	*x;

	x = p->x;
	/* ===== print about sleeping ======== */
	// while (to_sleep) sleep
	j_sleep(x, p->last_eat + x->time_eat + x->time_sleep);
}

void	*philo_func(t_philo *p)
{
	t_args	*x;

	x = p->x;
	// update last_eat
	p->last_eat = get_ms(x);
	// avoid deadlock
	if (p->id % 2)
		usleep(100);
	// routine
	while (*(p->finish_ptr))
	{
		thinking(p);
		eating(p);
		sleeping(p);
	}
	return (NULL);
}
