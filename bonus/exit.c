/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:30:28 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/06 21:30:29 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	exit_invalid(t_args *x, char *s1, char *s2)
{
	if (s1)
		printf("%s", s1);
	if (s2)
		printf("%s", s2);
	free_args(x);
	exit(EXIT_FAILURE);
}

void	exit_valid(t_args *x)
{
	free_args(x);
	exit(EXIT_SUCCESS);
}
