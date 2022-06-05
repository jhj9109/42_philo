/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:39:54 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/05 22:16:16 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_thread_create_detached(
	t_args *x,
	t_philo *philo,
	t_thread *thread,
	void *(*fp)(void *))
{
	if (pthread_create(thread, NULL, fp, (void *)(philo)))
		exit_invalid(x, "Error\n", "Fail to phtread_create at philo_thread\n");
	if (pthread_detach(*thread))
		exit_invalid(x, "Error\n", "Fail to phtread_create at philo_thread\n");
}
// void	ft_thread_detach(t_args *x, t_thread thread)
// {
// 	if (pthread_detach(thread))
// 		exit_invalid(x, "Error\n", "Fail to phtread_create at philo_thread\n");
// }
