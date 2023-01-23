/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:52:35 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/24 08:07:55 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

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
	long long		s_time;
}	t_info;

typedef struct s_philo
{
	pthread_t		id;
	int				idx;
	int				count;
	int				*fork_r;
	int				*fork_l;
	pthread_mutex_t	*fork_mx_r;
	pthread_mutex_t	*fork_mx_l;
	t_info			*info;
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t	*fork_mx;
	int				*forks;
}	t_fork;

// check_input_utils
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
int			ft_atoi_pos(const char *str);

// check_input
int			check_input(int argc, char **argv, t_info *info);
int			is_num(int argc, char **argv);
int			is_pos_num(int argc, char **argv);
int			init_info(int argc, char **argv, t_info *info);

// error_handle
int			error_handle(int i);
void		error_write(char *str);

// philo
int			philo(int argc, char **argv);
int			check_init(t_info *info, t_fork *fork, t_philo *philo, int num);
//init_philo
int			init_fork(t_info *info, t_fork *fork, int num);
int			create_fork(int num, t_fork *fork);
int			init_fork_mx(int num, t_fork *fork);
int			init_print_mx(t_info *info);
int			init_philo(t_philo *philo, t_info *info, t_fork *fork, int num);

//free_mutex
void		free_mutex(pthread_mutex_t *fork_mx, int num);
void		free_pthread(t_philo *philo, int num);
void		free_all(t_philo *philo, t_fork *fork, t_info *info);

//simulation
int			simulation(t_philo *philo);

//simulation_status
void		*live_or_die(void *atr);
int			pickup(t_philo *philo, long long s_t);
int			pickup_check(t_philo *philo);
int			eating(t_philo *philo, long long *s_t);
int			sleeping(t_philo *philo, long long s_t);

//simulation_utils
long long	get_time(void);
int			mutex_print(t_philo *philo, char *s_philo);
int			check_time(t_philo *philo, long long s_t);

#endif
