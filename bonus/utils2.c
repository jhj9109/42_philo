/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:31:22 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/06 22:31:00 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	ft_get_ms(t_args *x)
{
	struct timeval	unix;
	long long		res;

	if (gettimeofday(&unix, NULL) == -1)
		exit_invalid(x, "Error\n", "Fail to func gettimeofdat!\n");
	res = (long long)(unix.tv_sec * MILLI + unix.tv_usec / MILLI);
	if (unix.tv_usec % MILLI >= 500)
		++res;
	return (res);
}

void	ft_usleep(t_args *x, long long from_time, long long interval)
{
	long long	now;

	now = ft_get_ms(x);
	while (now - from_time < interval)
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
	long long	now;
	int			number;

	x = p->x;
	ft_sem_wait(x, x->print);
	now = ft_get_ms(x);
	number = p->id + 1;
	if (msg_state == ACHIEVING)
		number = x->number_goal_eat;
	printf("%lld %d %s\n", now - x->begin_time, number, msg[msg_state]);
	if (msg_state < DYING)
		ft_sem_post(x, x->print);
}

void	ft_thread_create_detached(
	t_args *x,
	t_philo *philo,
	t_thread *thread,
	void *(*fp)(void *))
{
	if (pthread_create(thread, NULL, fp, (void *)(philo)))
		exit_invalid(x, "Error\n", "Fail to phtread_create at philo_thread\n");
	if (pthread_detach(*thread))
		exit_invalid(x, "Error\n", "Fail to pthread_detach at philo_thread\n");
}
