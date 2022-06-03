/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:14:18 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/03 21:48:29 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	somefunc(t_args *x)
{
	while (!x->finish)
		usleep(10);
	pthread_mutex_unlock(&(x->print));
	if (x->died)
		printf("Philosopher => %d => died\n", x->died);
	printf("Finished!\n");
}

int	main(int ac, char **av)
{
	t_args	x;

	memset(&x, 0, sizeof(x));
	parse(&x, ac, av);
	monitoring(&x);
}
