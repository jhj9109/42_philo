/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:13:54 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/02 02:58:43 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

/**
 * enum
*/
typedef pthread_t t_thread;
typedef pthread_mutex_t t_mutex;

/**
 * id: 1 ~
*/
typedef struct s_philo
{
	int			id;
	int			l;
	int			r;
	t_thread	philo;
	t_thread	monitor;
}	t_philo;

/*
	time => ms;
*/
typedef struct s_args
{
	int		number_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		number_goal_eat;
	t_philo	*philos;
	t_mutex	*forks;
	t_mutex	*print;
	int		remain;
	bool	finish;
}	t_args;

/* exit */
void	exit_invalid(t_args *x, char *s1, char *s2);
void	exit_valid(t_args *x);

/* free */
void	j_free(void **x);
void	free_args(t_args *x);

/* parse */
void	parse(t_args *x, int ac, char **av);

/* t_args_init */
void	t_args_init(t_args **x);

/* utils */
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(char *p, int n);
bool	ft_atoi(char *s, int *dest);

#endif
