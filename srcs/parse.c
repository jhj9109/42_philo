/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:26:21 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/05 22:14:15 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void _parse_arguments(t_args *x, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		exit_invalid(x, "Error\n", "Invalid argument!\n");
	if (!ft_atoi(av[1], &(x->number_philo)) || \
		!ft_atoi(av[2], &(x->time_die)) || \
		!ft_atoi(av[3], &(x->time_eat)) || \
		!ft_atoi(av[4], &(x->time_sleep)))
		exit_invalid(x, "Error\n", "Invalid argument!\n");
	if (ac == 6)
	{
		if (!ft_atoi(av[5], &(x->number_goal_eat)))
			exit_invalid(x, "Error\n", "Invalid argument!\n");
		x->remain = x->number_philo;
	}
	else
		x->remain = -1;
}

static void	_calloc_philos_forks(t_args *x)
{
	x->philos = ft_calloc(x->number_philo, sizeof(t_philo));
	x->forks = ft_calloc(x->number_philo, sizeof(t_mutex));
	if (!x->philos || !x->forks)
		exit_invalid(x, "Error\n", "Fail to malloc at prepare\n");
}

static void	_set_mutex(t_args *x)
{
	int		i;

	i = -1;
	while (++i < x->number_philo)
		ft_mutex_init(x, &x->forks[i]);
	ft_mutex_init(x, &x->print);
	ft_mutex_init(x, &x->dead);
	ft_mutex_init(x, &x->finish_mutex);
}

static void	_set_philo(t_args *x)
{
	int			i;
	long long	begin_time;

	ft_mutex_lock(x, &x->finish_mutex);
	begin_time = ft_get_ms(x);
	x->begin_time = begin_time;
	i = -1;
	while (++i < x->number_philo)
	{
		x->philos[i].id = i;
		x->philos[i].l = i;
		x->philos[i].r = (i + 1) % (x->number_philo);
		x->philos[i].x = x;
		ft_thread_create_detached(x, &x->philos[i], &x->philos[i].philo_thread, philo_func);
		ft_thread_create_detached(x, &x->philos[i], &x->philos[i].monitor_thread, monitoring_func);
		// if (pthread_create(&x->philos[i].philo_thread, NULL, philo_func, (void *)(&x->philos[i])))
		// 	exit_invalid(x, "Error\n", "Fail to phtread_create at philo_thread\n");
		// if (pthread_detach(x->philos[i].philo_thread))
		// 	exit_invalid(x, "Error\n", "Fail to pthread_detach at philo_thread\n");
		// if (pthread_create(&x->philos[i].monitor_thread, NULL, monitoring_func, (void *)(&x->philos[i])))
		// 	exit_invalid(x, "x->philos[i]\n", "Fail to phtread_create at monitor_thread\n");
		// if (pthread_detach(x->philos[i].monitor_thread))
		// 	exit_invalid(x, "Error\n", "Fail to pthread_detach at monitor_thread\n");
	}
}

void	parse(t_args *x, int ac, char **av)
{
	_parse_arguments(x, ac, av);
	_calloc_philos_forks(x);
	_set_mutex(x);
	_set_philo(x);
}
