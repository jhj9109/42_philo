/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   achieve_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 22:41:47 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/08 22:41:49 by hyeonjan         ###   ########.fr       */
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
	while (true)
	{
		ft_sem_wait(x, x->aggregate);
		if (++cnt == x->number_philo)
		{
			ft_log(p, ACHIEVING);
			ft_sem_post(x, x->end_sem);
			break ;
		}
	}
	return (NULL);
}
