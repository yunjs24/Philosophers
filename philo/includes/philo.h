/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 05:22:35 by junsyun           #+#    #+#             */
/*   Updated: 2022/12/09 10:47:03 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_philo
{
	int		philo_id;
	int		total_meals;
	size_t	time_of_last_meal;
	int		time_to_eat;
	int		time_to_die;
	int		time_to_sleep;
	time_t	limit_of_life;
	int		stop;
	time_t	start_time;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}					t_philo;

typedef struct s_info
{
	int				nbr_philo;
	int				philo_id;
	time_t			start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				dead;
	int				nbr_of_meals;
	pthread_mutex_t	*forks;
	pthread_t		*tids;
	pthread_mutex_t	lock_print;
	t_philo			*all_philos;
}					t_info;

int		ft_check_valid(int ac, char **av);
int		ft_init_args(t_info *info, int ac, char **av);
void	ft_init_mutex(t_info *info);
void	ft_init_philos(t_info *info);
void	ft_init_threads(t_info *info);
void	ft_end_threads(t_info *info);
void	ft_check_args(void);
void	free_all(int ac, char **av);
 
#endif