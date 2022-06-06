/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:05:35 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/06 22:29:56 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	pick_up_fork(t_philo *p, t_args *x)
{
	ft_sem_wait(x, x->waiting);
	ft_sem_wait(x, x->forks);
	ft_log(p, PICKING);
	ft_sem_wait(x, x->forks);
	ft_log(p, PICKING);
	ft_sem_post(x, x->waiting);
}

void	put_down_fork(t_args *x)
{
	ft_sem_post(x, x->forks);
	ft_sem_post(x, x->forks);
}
