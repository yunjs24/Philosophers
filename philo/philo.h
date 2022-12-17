/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 05:22:35 by junsyun           #+#    #+#             */
/*   Updated: 2022/12/18 08:13:02 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_info
{
	int				block;
	int				mode;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				check_print;
	pthread_mutex_t	print_mx;
	long long		start;
}					t_info;

typedef struct s_philo
{
	pthread_t		id;
	int				idx;
	int				count;
	int				*fork_r;
	int				*fork_l;
	pthread_mutex_t	*fork_mx_r;
	pthread_mutex_t	*fork_mx_l;
	struct s_arg	*arg;
	t_info			*info;
}					t_philo;

typedef struct s_part
{
	pthread_mutex_t	*fork_mx;
	int				*bool_fork;
}	t_part;

// simulation_utils
long long	get_time(void);
int			mutex_print(t_philo *arr, char *s, long long c_t);
int			check_time(t_philo *arr, long long s_t);

// check_utils
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
int			ft_atoi_pos(const char *str);

// check input
int			check_input(int argc, char **argv, t_info *info);
int			is_pos_num(int argc, char **argv);
int			set_info(int argc, char **argv, t_info *info);

// error_handle
int			error_handle(int i);
void		error_write(char *str);

// philo
int			philo(int argc, char **argv);
int			check_init(t_info *info, t_part *part, t_philo *philo, int num);

//init_philo

int			init_part(t_info *info, t_part *part, int num);
int			pull_bool_fork(int num, t_part *part);
int			pull_mutex(int num, t_part *part);
int			init_mutex(t_info *info);
int			init_philo(t_philo *philo, t_info *info, t_part *part, int num);

//free_mutex
void		free_mutex(pthread_mutex_t *fork_mx, int num);
void		free_pthread(t_philo *philo, int num);
void		free_all(t_philo *philo, t_part *_part, t_info *info);

//simulation
int			simulation(t_philo *philo);
void		*live_or_die(void *atr);

//action

int			pickup(t_philo *arr, long long s_t);
int			pickup_check(t_philo *arr);
int			eating(t_philo *arr, long long *s_t);
int			sleeping(t_philo *arr, long long s_t);

#endif
