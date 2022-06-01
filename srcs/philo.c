/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:14:18 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/02 02:57:01 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args	*x;

	/**
	 *	1. t_args_init(&x)
	 *	- malloc
	 *	- philo struct
	*/
	t_args_init(&x);

	/**
	 * 2. parse(x, ac, **av)
	 * parsing => set_setting
	*/
	parse(x, ac, av);

	/**
	 *	3. thread_create
	*/

	/**
	 * 4. philo start
	*/
	// printf("ac: %d, programe_name:, %s", ac, av[0]);
	exit_valid(x);
}
