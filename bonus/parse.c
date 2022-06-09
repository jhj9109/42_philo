/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:30:42 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/09 22:12:46 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	_parse_arguments(t_args *x, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		exit_invalid(x, "Error\n", "Invalid argument! It must be 5 or 6 args.\n");
	if (!ft_atoi(av[1], &(x->number_philo)) || \
		!ft_atoi(av[2], &(x->time_die)) || \
		!ft_atoi(av[3], &(x->time_eat)) || \
		!ft_atoi(av[4], &(x->time_sleep)))
		exit_invalid(x, "Error\n", "Invalid argument!\n");
	x->pids = ft_calloc(x->number_philo, sizeof(int));
	if (!x->pids)
		exit_invalid(x, "Error\n", "Fail to calloc at x->pids\n");
	if (ac == 6)
	{
		if (!ft_atoi(av[5], &(x->number_eat)))
			exit_invalid(x, "Error\n", "Invalid argument!\n");
		x->remain = x->number_philo;
	}
	else
		x->remain = -1;
}

void	_sem_init(t_args *x)
{
	ft_sem_init(x, &x->forks, "forks", x->number_philo);
	ft_sem_init(x, &x->end_sem, "end_sem", 0);
	ft_sem_init(x, &x->waiting, "waiting", 1);
	ft_sem_init(x, &x->print, "print", 1);
	ft_sem_init(x, &x->dead, "dead", 1);
	ft_sem_init(x, &x->aggregate, "aggregate", 1);
}

void	_fork_init(t_args *x)
{
	pid_t	pid;
	int		i;

	x->philo_obj.x = x;
	if (x->remain != -1 && pthread_create(&x->achieve, \
		NULL, achieve_func, (void *)(&x->philo_obj)))
		exit_invalid(x, "Error\n", "Fail to phtread_create at x->achieve\n");
	set_begin_time(x);
	i = -1;
	while (++i < x->number_philo)
	{
		pid = fork();
		if (pid == ERROR)
			exit(EXIT_FAILURE);
		if (pid == 0)
			child_proc(x, i);
		else
			x->pids[i] = pid;
	}
}

void	parse(t_args *x, int ac, char **av)
{
	_parse_arguments(x, ac, av);
	_sem_init(x);
	_fork_init(x);
}
