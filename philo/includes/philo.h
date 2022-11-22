/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 05:22:35 by junsyun           #+#    #+#             */
/*   Updated: 2022/11/23 06:32:46 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>

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

/**
 * 
 * void	ft_init_mutex();
 * void	ft_init_philos();
 * void	ft_init_threads();
 * void	ft_end_threads();
 * ft_check_args(void);
 * free_all();
 
*/
#endif