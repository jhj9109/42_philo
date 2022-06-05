/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:40:13 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/05 22:43:46 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_ms(t_args *x)
{
	struct timeval	unix;
	long long res;

	if (gettimeofday(&unix, NULL) == -1)
		exit_invalid(x, "Error\n", "Fail to func gettimeofdat!\n");
	res = (long long)(unix.tv_sec * MILLI + unix.tv_usec / MILLI);
	return (res);
}

void	ft_usleep(t_args *x, long long from_time, long long interval)
{
	long long	now;

	while (true)
	{
		now = ft_get_ms(x);
		if (now - from_time >= interval)
			return ;
		if (usleep(EPSILON) == ERROR)
			exit_invalid(x, "Error\n", "Fail to sleep_little\n");
	}
}

void	ft_log(t_philo *p, t_msg_state msg_state)
{
	static char	*msg[5] = {
		"has taken a fork",
		"is eating",
		"is sleeping",
		"is thinking",
		"died=============",
	};
	t_args	*x;

	x = p->x;
	// ft_mutex_lock(x, &x->print);
	// if (msg_state == DYING || !x->finish)
	printf("%lld %d %s\n", ft_get_ms(x) - x->begin_time, p->id + 1, msg[msg_state]);
	// if (msg_state != DYING)
	// 	ft_mutex_unlock(x, &x->print);
	// else
	// 	ft_mutex_unlock(x, &x->finish_mutex);
}
