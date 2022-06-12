/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:40:13 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/09 22:12:46 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_begin_time(t_args *x)
{
	struct timeval		unix;

	if (gettimeofday(&unix, NULL) == -1)
		exit_invalid(x, "Error\n", "Fail to func gettimeofdat!\n");
	x->begin_time_sec = unix.tv_sec;
	x->begin_time_usec = unix.tv_usec;
}

long long	ft_get_ms(t_args *x)
{
	struct timeval		unix;

	if (gettimeofday(&unix, NULL) == -1)
		exit_invalid(x, "Error\n", "Fail to func gettimeofdat!\n");
	return ((unix.tv_sec - x->begin_time_sec) * MILLI + \
			(unix.tv_usec - x->begin_time_usec) / MILLI);
}

void	ft_usleep(t_args *x, long long from_time, long long interval)
{
	long long	now;

	now = ft_get_ms(x);
	while (!x->finish && now - from_time < interval)
	{
		if (usleep(EPSILON) == ERROR)
			exit_invalid(x, "Error\n", "Fail to sleep_little\n");
		now = ft_get_ms(x);
	}
}

void	ft_log(t_philo *p, t_msg_state msg_state)
{
	static char	*msg[6] = {
		"has taken a fork",
		"is eating",
		"is sleeping",
		"is thinking",
		"died",
		"Achieved program's goal!",
	};
	t_args		*x;

	x = p->x;
	ft_mutex_lock(x, &x->print);
	if (!x->finish)
	{
		if (msg_state == ACHIEVING)
			printf("%lld %d %s\n", ft_get_ms(x), x->number_eat, msg[msg_state]);
		else
			printf("%lld %d %s\n", ft_get_ms(x), p->id + 1, msg[msg_state]);
		if (msg_state >= DYING)
		{
			x->finish = true;
			ft_mutex_unlock(x, &x->end_mutex);
		}
	}
	ft_mutex_unlock(x, &x->print);
}

void	ft_thread_create_detached(
	t_args *x,
	t_philo *philo,
	pthread_t *thread,
	void *(*fp)(void *))
{
	if (pthread_create(thread, NULL, fp, (void *)(philo)))
		exit_invalid(x, "Error\n", "Fail to phtread_create at philo_thread\n");
	if (pthread_detach(*thread))
		exit_invalid(x, "Error\n", "Fail to pthread_detach at philo_thread\n");
}
