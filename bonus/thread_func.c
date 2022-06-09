/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:31:06 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/09 23:01:56 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	_eating(t_philo *p)
{
	t_args		*x;

	x = p->x;
	pick_up_fork(p, x);
	p->last_eat = ft_get_ms(x);
	ft_log(p, EATING);
	if (++(p->eaten) == x->number_eat)
		ft_sem_post(x, x->aggregate);
	ft_usleep(x, ft_get_ms(x), x->time_eat);
	put_down_fork(x);
}

static void	_sleeping(t_philo *p)
{
	t_args		*x;

	x = p->x;
	ft_log(p, SLEEPING);
	ft_usleep(x, ft_get_ms(x), x->time_sleep);
}

static void	_thinking(t_philo *p)
{
	ft_log(p, THINKING);
}

void	*philo_func(void *ptr)
{
	t_philo		*p;
	t_args		*x;

	p = (t_philo *)ptr;
	x = p->x;
	if (p->id % 2 == 0)
		ft_usleep(x, 0, x->time_eat / 2);
	while (!x->finish)
	{
		_eating(p);
		_sleeping(p);
		_thinking(p);
	}
	return (NULL);
}

void	*monitoring_func(void *ptr)
{
	t_philo		*p;
	t_args		*x;
	long long	now;

	p = (t_philo *)ptr;
	x = p->x;
	ft_usleep(x, 0, x->time_die / 2);
	while (!x->finish)
	{
		now = ft_get_ms(x);
		if (now - p->last_eat > (long long)x->time_die)
			ft_log(p, DYING);
		usleep(EPSILON);
	}
	return (NULL);
}
