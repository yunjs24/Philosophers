/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:14:11 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/18 17:56:19 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_info
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	sem_t			*fork;
	sem_t			*sem_pr;
	sem_t			*dead;
	sem_t			*full;
	long long		s_time;
	long long		put_t;
}	t_info;

typedef struct s_philo
{
	pthread_t		id;
	pid_t			pid;
	int				idx;
	int				count;
	long long		*r_time;
	t_info			*info;
	sem_t			*time;
}	t_philo;

int			philo_bonus(int argc, char **argv);

int			error_handle(int death_flag);
void		error_write(char *str);

int			check_input(int argc, char **argv, t_info *info);
int			is_num(int argc, char **argv);
int			init_info(int argc, char **argv, t_info *info);

size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
int			ft_atoi_pos(const char *str);

int			init_data(t_philo *philo, t_info *info, int num);
int			init_philo(t_philo *philo, int num, t_info *info);
int			init_sem(t_info *info, int num);

int			simulation(t_philo *philo, t_info *info, int num);
void		wait_pid(t_info *info, int num);
void		*is_dead(void *atr);
int			fork_phlio(t_philo *philo, t_info *info, int num);

long long	get_time(void);
void		sem_print(t_philo philo, char *s, int death_flag);

int			live_or_die(t_philo philo);
void		pick_up(t_philo philo);
int			eating(t_philo philo);
void		sleeping(t_philo philo);

void		free_all(t_philo *philo);

void		*moniter(void *atr);

#endif
