/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:30:23 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/08 23:20:11 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	child_proc(t_args *x, int philo_id)
{
	t_philo	philo_obj;

	memset(&philo_obj, 0, sizeof(philo_obj));
	philo_obj.id = philo_id;
	philo_obj.x = x;
	ft_thread_create_detached(x, &philo_obj, \
		&philo_obj.philo_thread, philo_func);
	ft_thread_create_detached(x, &philo_obj, \
		&philo_obj.monitor_thread, monitoring_func);
	while (true)
		;
}
