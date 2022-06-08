/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:30:52 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/08 21:45:48 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_args	x;

	memset(&x, 0, sizeof(x));
	parse(&x, ac, av);
	ft_sem_wait(&x, x.end_sem);
	exit_valid(&x);
}
