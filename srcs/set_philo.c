/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 02:06:02 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/02 03:02:32 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*f1(void *param)
{
	return (NULL);
}

void	*f2(void *param)
{
	return (NULL);
}

void	set_philo(t_args *x)
{
	int		i;

	i = -1;
	while (++i < x->number_philo)
	{
		x->philos[i].id = i + 1;
		x->philos[i].l = i;
		x->philos[i].r = (i + 1) % (x->number_philo);
		if (!pthread_create(&(x->philos[i].philo), NULL, f1, NULL))
			exit_invalid(x, "Error\n", "Fail to phtread_create at philo\n");
		if (!pthread_detach(x->philos[i].philo))
			exit_invalid(x, "Error\n", "Fail to pthread_detach at philo\n");
		if (!pthread_create(&(x->philos[i].monitor), NULL, f2, NULL))
			exit_invalid(x, "Error\n", "Fail to phtread_create at monitor\n");
		if (!pthread_detach(x->philos[i].monitor))
			exit_invalid(x, "Error\n", "Fail to pthread_detach at monitor\n");
	}
}

void	set_fork(t_args *x)
{
	int		i;

	i = -1;
	while (++i < x->number_philo)
		if (!pthread_mutex_init(&(x->forks[i]), NULL))
			exit_invalid(x, "Error\n", "Fail to pthread_mutex_init at set_fork\n");
}

void	prepare(t_args *x)
{
	x->philos = ft_calloc(x->number_philo, sizeof(t_philo));
	x->forks = ft_calloc(x->number_philo, sizeof(t_mutex));
	x->print = ft_calloc(1, sizeof(t_mutex));
	if (!x->philos || !x->forks || !x->print)
		exit_invalid(x, "Error\n", "Fail to malloc at prepare\n");
	set_fork(x);
	set_philo(x);
}