/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_args_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:22:53 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/01 20:54:27 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	t_args_init(t_args **x)
{
	*x = ft_calloc(1, sizeof(t_args));
	if (*x == NULL)
		exit_invalid(x, "Error\n", "Fail to malloc for t_args!\n");
}
