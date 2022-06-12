/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:30:35 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/12 16:28:17 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	_close_sem(t_args *x)
{
	sem_close(x->forks);
	sem_close(x->end_sem);
	sem_close(x->waiting);
	sem_close(x->print);
	sem_close(x->dead);
	x->finish = true;
	ft_sem_post(x, x->aggregate);
	sem_close(x->aggregate);
}

static void	_exit_processes(t_args *x)
{
	int	i;

	i = -1;
	while (++i < x->number_philo)
	{
		kill(x->pids[i], SIGKILL);
		waitpid(x->pids[i], NULL, WNOHANG);
	}
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
		_exit_processes(x);
		_close_sem(x);
		_safe_free((void **)&x->pids);
	}
}
