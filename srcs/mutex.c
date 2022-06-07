/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:39:26 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/07 19:41:13 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex_init(t_args *x, pthread_mutex_t *m)
{
	if (pthread_mutex_init(m, NULL))
		exit_invalid(x, "Error\n", "Fail to ft_mutex_init\n");
}

void	ft_mutex_lock(t_args *x, pthread_mutex_t *m)
{
	if (pthread_mutex_lock(m))
		exit_invalid(x, "Error\n", "Fail to ft_mutex_lock\n");
}

void	ft_mutex_unlock(t_args *x, pthread_mutex_t *m)
{
	if (pthread_mutex_unlock(m))
		exit_invalid(x, "Error\n", "Fail to ft_mutex_unlock\n");
}
