/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:26:21 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/02 03:00:21 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse(t_args *x, int ac, char **av)
{
	if (!ft_atoi(av[1], &(x->number_philo)) || \
		!ft_atoi(av[2], &(x->time_die)) || \
		!ft_atoi(av[3], &(x->time_eat)) || \
		!ft_atoi(av[4], &(x->time_sleep)) || \
		(ac == 6 && !ft_atoi(av[5], &(x->number_goal_eat))))
	// x->philos = ft_calloc(x->number_philo, sizeof(t_philo));
	// x->forks = ft_calloc(x->number_philo, sizeof(t_mutex));
	// x->print = ft_calloc(1, sizeof(t_mutex));
}
