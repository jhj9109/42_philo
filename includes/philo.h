/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:13:54 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/07 20:11:06 by hyeonjan         ###   ########.fr       */
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

typedef enum e_stat
{
	ERROR = -1,
	SUCCESS,
}	t_stat;

typedef enum e_msg_state
{
	PICKING,
	EATING,
	SLEEPING,
	THINKING,
	DYING,
	ACHIEVING,
}	t_msg_state;

typedef struct s_philo
{
	void		*x;
	int			id;
	int			l;
	int			r;
	int			eaten;
	long long	last_eat;
	pthread_t	philo_thread;
	pthread_t	monitor_thread;
}	t_philo;

typedef struct s_args
{
	int					number_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					number_goal_eat;
	long long			begin_time;
	long long			begin_time_sec;
	int					begin_time_usec;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	pthread_mutex_t		dead;
	pthread_mutex_t		end_mutex;
	int					remain;
	bool				finish;
}	t_args;

/* exit */
void		exit_invalid(t_args *x, char *s1, char *s2);
void		exit_valid(t_args *x);

/* free */
void		free_args(t_args *x);

/* handle_fork */
void		pick_up_fork(t_philo *p, t_args *x);
void		put_down_fork(t_philo *p, t_args *x);

/* parse */
void		parse(t_args *x, int ac, char **av);

/* thread_func */
void		*philo_func(void *ptr);
void		*monitoring_func(void *ptr);

/* utils */
void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);
char		*ft_itoa(char *p, int n);
bool		ft_atoi(char *s, int *dest);

/* utils2 */
void		set_begin_time(t_args *x);
long long	ft_get_ms(t_args *x);
void		ft_usleep(t_args *x, long long from_time, long long interval);
void		ft_log(t_philo *p, t_msg_state msg_state);
void		ft_thread_create_detached(t_args *x, t_philo *philo, \
				pthread_t *thread, void *(*fp)(void *));

/* mutex */
void		ft_mutex_init(t_args *x, pthread_mutex_t *m);
void		ft_mutex_lock(t_args *x, pthread_mutex_t *m);
void		ft_mutex_unlock(t_args *x, pthread_mutex_t *m);

#endif
