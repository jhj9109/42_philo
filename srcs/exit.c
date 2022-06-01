/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:14:04 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/01 19:15:43 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_invalid(t_args **x, char *s1, char *s2)
{
	if (s1)
		printf(s1);
	if (s2)
		printf(s2);
	if (x)
		free_args(x);
	exit(EXIT_FAILURE);
}

void	exit_valid(t_args **x)
{
	free_args(x);
	exit(EXIT_SUCCESS);
}
