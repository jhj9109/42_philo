/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   achieve_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 22:41:47 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/09 22:59:03 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*achieve_func(void *ptr)
{
	t_philo	*p;
	t_args	*x;
	int		cnt;

	p = (t_philo *)ptr;
	x = p->x;
	cnt = 0;
	while (!x->finish)
	{
		ft_sem_wait(x, x->aggregate);
		if (++cnt == x->number_philo)
			ft_log(p, ACHIEVING);
	}
	return (NULL);
}
