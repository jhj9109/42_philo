/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:14:18 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/06 11:13:48 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args	x;

	memset(&x, 0, sizeof(x));
	parse(&x, ac, av);
	ft_mutex_lock(&x, &x.end_mutex);
	exit_valid(&x);
}
