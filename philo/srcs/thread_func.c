/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:39:44 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/14 23:07:13 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_eating(t_philo *p)
{
	t_args		*x;

	x = p->x;
	pick_up_fork(p, x);
	p->last_eat = ft_get_ms(x);
	ft_log(p, EATING);
	ft_usleep(x, p->last_eat, x->time_eat);
	if (++(p->eaten) == x->number_eat)
	{
		ft_mutex_lock(x, &x->aggregate);
		if (--(x->remain) == 0)
			ft_log(p, ACHIEVING);
		ft_mutex_unlock(x, &x->aggregate);
	}
	put_down_fork(p, x);
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
	ft_reduce_remain_thead(x);
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
	}
	ft_reduce_remain_thead(x);
	return (NULL);
}
