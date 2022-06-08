/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:44:02 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/06/08 22:52:38 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <string.h>
# include <sys/time.h>
# include <signal.h>

# define EPSILON	99
# define MILLI		1000
# define MODE		0644

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
	int			eaten;
	long long	last_eat;
	pthread_t	philo_thread;
	pthread_t	monitor_thread;
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
	long long	begin_time_sec;
	int			begin_time_usec;
	int			*pids;
	sem_t		*forks;
	sem_t		*end_sem;
	sem_t		*waiting;
	sem_t		*print;
	sem_t		*dead;
	sem_t		*aggregate;
	int			remain;
	bool		finish;
	t_philo		philo_obj;
	pthread_t	philo;
	pthread_t	monitor;
	pthread_t	achieve;
}	t_args;

/* child_proc */
void		child_proc(t_args *x, int philo_id);

/* handle_fork */
void		pick_up_fork(t_philo *p, t_args *x);
void		put_down_fork(t_args *x);

/* sem */
void		ft_sem_init(t_args *x, sem_t **s, const char *name, int value);
void		ft_sem_wait(t_args *x, sem_t *s);
void		ft_sem_post(t_args *x, sem_t *s);

/* exit */
void		exit_invalid(t_args *x, char *s1, char *s2);
void		exit_valid(t_args *x);

/* free */
void		free_args(t_args *x);

/* parse */
void		parse(t_args *x, int ac, char **av);

/* thread_func */
void		*philo_func(void *ptr);
void		*monitoring_func(void *ptr);
void		*achieve_func(void *ptr);

/* utils */
void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);
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