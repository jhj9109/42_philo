/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:26:21 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/03 21:47:32 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void _parse_arguments(t_args *x, int ac, char **av)
{
	if (!ft_atoi(av[1], &(x->number_philo)) || \
		!ft_atoi(av[2], &(x->time_die)) || \
		!ft_atoi(av[3], &(x->time_eat)) || \
		!ft_atoi(av[4], &(x->time_sleep)) || \
		(ac == 6 && !ft_atoi(av[5], &(x->number_goal_eat))))
		exit_invalid(x, "Error\n", "Invalid argument!\n");
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
		if (!pthread_mutex_init(&(x->forks[i]), NULL))
			exit_invalid(x, "Error\n", "Fail to pthread_mutex_init at fork\n");
	if (!pthread_mutex_init($(x->print), NULL))
		exit_invalid(x, "Error\n", "Fail to pthread_mutex_init at set_fork\n");
}

static void	_set_philo(t_args *x)
{
	int		i;
	t_philo	philo;

	i = -1;
	while (++i < x->number_philo)
	{
		philo = x->philos[i];
		philo.id = i + 1;
		philo.l = i;
		philo.r = (i + 1) % (x->number_philo);
		philo.finish_ptr = &(x->finish);
		philo.x = x;
		if (!pthread_create(&philo.thread, NULL, philo_func, (void *)(&philo)))
			exit_invalid(x, "Error\n", "Fail to phtread_create at philo\n");
		if (!pthread_detach(philo.thread))
			exit_invalid(x, "Error\n", "Fail to pthread_detach at philo\n");
	}
}

void	parse(t_args *x, int ac, char **av)
{
	_parse_arguments(x, ac, av);
	_calloc_philos_forks(x);
	_set_mutex(x);
	_set_philo(x);
}
