/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:39:44 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/06 22:22:48 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_thinking(t_philo *p)
{
	t_args	*x;

	x = p->x;
	ft_log(p, THINKING);
	pick_up_fork(p, x);
}

static void	_eating(t_philo *p)
{
	t_args		*x;
	long long	now;

	x = p->x;
	p->last_eat = ft_get_ms(x);
	ft_log(p, EATING);
	if (++(p->eaten) == x->number_goal_eat && --(x->remain) == 0)
	{
		ft_log(p, ACHIEVING);
		ft_mutex_unlock(x, &x->end_mutex);
	}
	now = ft_get_ms(x);
	ft_usleep(x, now, x->time_eat);
	put_down_fork(p, x);
}

static void	_sleeping(t_philo *p)
{
	t_args		*x;
	long long	now;

	x = p->x;
	ft_log(p, SLEEPING);
	now = ft_get_ms(x);
	ft_usleep(x, now, x->time_sleep);
}

void	*philo_func(void *ptr)
{
	t_philo		*p;
	t_args		*x;
	long long	now;

	p = (t_philo *)ptr;
	x = p->x;
	p->last_eat = x->begin_time;
	now = ft_get_ms(x);
	if (p->id % 2 == 0)
		usleep(EPSILON);
	while (true)
	{
		_thinking(p);
		_eating(p);
		_sleeping(p);
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
	ft_usleep(x, x->begin_time, x->time_die / 2);
	while (true)
	{
		now = ft_get_ms(x);
		if (now - p->last_eat >= (long long)x->time_die)
		{
			ft_mutex_lock(x, &x->dead);
			x->finish = true;
			ft_log(p, DYING);
			ft_mutex_unlock(x, &x->end_mutex);
		}
		usleep(EPSILON);
	}
	return (NULL);
}
