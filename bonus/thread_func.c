/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:31:06 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/08 22:24:20 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	_eating(t_philo *p)
{
	t_args		*x;
	long long	now;

	x = p->x;
	pick_up_fork(p, x);
	p->last_eat = ft_get_ms(x);
	ft_log(p, EATING);
	if (++(p->eaten) == x->number_goal_eat)
		ft_sem_post(x, x->aggregate);
	now = ft_get_ms(x);
	ft_usleep(x, now, x->time_eat);
	put_down_fork(x);
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
	p->last_eat = ft_get_ms(x);
	while (true)
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
	now = ft_get_ms(x);
	ft_usleep(x, now, x->time_die / 2);
	while (true)
	{
		now = ft_get_ms(x);
		if (now - p->last_eat > (long long)x->time_die)
		{
			ft_sem_wait(x, x->dead);
			ft_log(p, DYING);
			ft_sem_post(x, x->end_sem);
		}
		usleep(EPSILON);
	}
	return (NULL);
}
