/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:30:59 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/06 22:04:41 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_sem_init(t_args *x, sem_t **s, const char *name, int value)
{
	sem_unlink(name);
	if (sem_open(name, O_EXCL) != SEM_FAILED)
		exit_invalid(x, "Error\n", "sem is already exist\n");
	*s = sem_open(name, O_CREAT, MODE, value);
	if (*s == SEM_FAILED)
		exit_invalid(x, "Error\n", "Fail to sem_open\n");
	sem_unlink(name);
}

void	ft_sem_wait(t_args *x, sem_t *s)
{
	if (sem_wait(s) == ERROR)
		exit_invalid(x, "Error\n", "Fail to sem_wait\n");
}

void	ft_sem_post(t_args *x, sem_t *s)
{
	if (sem_post(s) == ERROR)
		exit_invalid(x, "Error\n", "Fail to sem_post\n");
}
