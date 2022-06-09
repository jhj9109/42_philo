/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:14:18 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/09 22:13:11 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_wait_for_end_thread(t_args *x)
{
	while (x->remain_thread)
		usleep(EPSILON);
}

int	main(int ac, char **av)
{
	t_args	x;

	memset(&x, 0, sizeof(x));
	parse(&x, ac, av);
	ft_mutex_lock(&x, &x.end_mutex);
	_wait_for_end_thread(&x);
	ft_mutex_unlock(&x, &x.end_mutex);
	exit_valid(&x);
}
