/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:13:54 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/06 11:50:42 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

# define EPSILON	10
# define MILLI		1000

/**
 * enum
*/
typedef pthread_t t_thread;
typedef pthread_mutex_t t_mutex;

typedef enum e_stat
{
	ERROR = -1,
	SUCCESS,
}	t_stat;

typedef enum e_msg_state
{
	TAKING,
	EATING,
	SLEEPING,
	THINKING,
	DYING,
}	t_msg_state;
/**
 * id: 1 ~
*/
typedef struct s_philo
{
	void		*x;
	int			id;
	int			l;
	int			r;
	long long	last_eat;
	t_thread	philo_thread;
	t_thread	monitor_thread;
}	t_philo;

/*
	time => ms;
*/
typedef struct s_args
{
	int			number_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			number_goal_eat;
	long long	begin_time;
	t_philo		*philos;
	t_mutex		*forks;
	t_mutex		print;
	t_mutex		dead;
	t_mutex		end_mutex;
	int			remain;
	bool		finish;
}	t_args;

/* exit */
void	exit_invalid(t_args *x, char *s1, char *s2);
void	exit_valid(t_args *x);

/* free */
void	j_free(void **x);
void	free_args(t_args *x);

/* parse */
void	parse(t_args *x, int ac, char **av);

/* thread_func */
void	*philo_func(void *ptr);
void	*monitoring_func(void *ptr);

/* utils */
// size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(char *p, int n);
bool	ft_atoi(char *s, int *dest);

/* utils2 */
long long	ft_get_ms(t_args *x);
// void		ft_usleep(t_args *x, long long ms);
void		ft_usleep(t_args *x, long long from_time, long long interval);
void		ft_log(t_philo *p, t_msg_state msg_state);

/* mutex */
void	ft_mutex_init(t_args *x, t_mutex *m);
void	ft_mutex_lock(t_args *x, t_mutex *m);
void	ft_mutex_unlock(t_args *x, t_mutex *m);

/* thread */
void	ft_thread_create_detached(t_args *x, t_philo *philo, \
						t_thread *thread, void *(*fp)(void *));
// void	ft_thread_detach(t_args *x, t_thread thread);

#endif
