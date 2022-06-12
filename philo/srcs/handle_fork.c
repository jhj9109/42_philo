/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:17:54 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/06 21:17:55 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up_fork(t_philo *p, t_args *x)
{
	ft_mutex_lock(x, &(x->forks[p->l]));
	ft_log(p, PICKING);
	ft_mutex_lock(x, &(x->forks[p->r]));
	ft_log(p, PICKING);
}

void	put_down_fork(t_philo *p, t_args *x)
{
	ft_mutex_unlock(x, &(x->forks[p->l]));
	ft_mutex_unlock(x, &(x->forks[p->r]));
}
