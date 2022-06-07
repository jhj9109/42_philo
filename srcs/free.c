/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:14:12 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/07 19:36:15 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_unset_mutex(t_args *x)
{
	int	i;

	if (x->forks)
	{
		i = -1;
		while (++i < x->number_philo)
			pthread_mutex_destroy(&x->forks[i]);
	}
	pthread_mutex_destroy(&x->print);
	pthread_mutex_destroy(&x->dead);
	pthread_mutex_destroy(&x->end_mutex);
}

static void	_safe_free(void **x)
{
	if (*x)
	{
		free(*x);
		*x = 0;
	}
}

void	free_args(t_args *x)
{
	if (x)
	{
		_unset_mutex(x);
		_safe_free((void **)&x->philos);
		_safe_free((void **)&x->forks);
	}
}
