/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:30:35 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/06 22:29:14 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	_close_sem(t_args *x)
{
	sem_close(x->forks);
	sem_close(x->waiting);
	sem_close(x->print);
	sem_close(x->dead);
	sem_close(x->end_sem);
}

void	j_free(void **x)
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
		_close_sem(x);
}
