/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:13:54 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/03 21:47:58 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>/*memset*/
/* int gettimeofday(struct timeval * __restrict, void * __restrict); */
# include <sys/time.h>

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
	void		*x;
	bool		*finish_ptr;
	int			id;
	int			l;
	int			r;
	long long	last_eat;
	t_thread	thread;
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
	t_mutex	print;
	int		remain;
	bool	finish;
	int		died;
}	t_args;

/* exit */
void	exit_invalid(t_args *x, char *s1, char *s2);
void	exit_valid(t_args *x);

/* free */
void	j_free(void **x);
void	free_args(t_args *x);

/* monitoring */
void	monitoring(t_args *x);

/* parse */
void	parse(t_args *x, int ac, char **av);

/* philo_func */
void	*philo_func(t_philo *p);

/* philo => main */

/* utils */
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(char *p, int n);
bool	ft_atoi(char *s, int *dest);

/* utils2 */
long long	get_ms(t_args *x);
void	j_sleep(t_args *x, long long ms);
bool	is_over(struct timeval unix1, struct timeval unix2, long long ms);

#endif
