/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:13:54 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/01 20:12:59 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_args
{

}	t_args;

/* exit */
void	exit_invalid(t_args **x, char *s1, char *s2);
void	exit_valid(t_args **x);

/* free */
void	j_free(void **x);
void	free_args(t_args **x);

#endif
