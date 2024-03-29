/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_status_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:14:17 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/24 09:27:14 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	live_or_die(t_philo philo)
{
	philo.r_time = &philo.info->put_t;
	pthread_create(&philo.id, NULL, moniter, &philo);
	while (1)
	{
		pick_up(philo);
		if (eating(philo) == 1)
			break ;
		philo.count++;
		sleeping(philo);
	}
	return (0);
}

void	pick_up(t_philo philo)
{
	sem_wait(philo.info->fork);
	sem_print(philo, "has taken a fork", 0);
	sem_wait(philo.info->fork);
	sem_print(philo, "has taken a fork", 0);
}

int	eating(t_philo philo)
{
	sem_wait(philo.time);
	*philo.r_time = get_time();
	sem_post(philo.time);
	sem_print(philo, "is eating", 0);
	if (++(philo.count) == \
	philo.info->number_of_times_each_philosopher_must_eat)
	{
		sem_post(philo.info->fork);
		sem_post(philo.info->fork);
		return (1);
	}
	while (1)
	{
		sem_wait(philo.time);
		if (get_time() - *philo.r_time > philo.info->time_to_eat)
		{
			sem_post(philo.time);
			break ;
		}
		sem_post(philo.time);
		usleep(300);
	}
	sem_post(philo.info->fork);
	sem_post(philo.info->fork);
	return (0);
}

void	sleeping(t_philo philo)
{
	long long	x;

	x = get_time();
	sem_print(philo, "is sleeping", 0);
	while (get_time() - x < philo.info->time_to_sleep)
		usleep(300);
	sem_print(philo, "is thinking", 0);
}
