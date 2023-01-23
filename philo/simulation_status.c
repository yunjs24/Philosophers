/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:52:39 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/24 08:18:40 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*live_or_die(void *atr)
{
	t_philo		*ph;
	long long	s_t;

	ph = (t_philo *)atr;
	pthread_mutex_lock(&ph->info->print_mx);
	pthread_mutex_unlock(&ph->info->print_mx);
	pickup(ph, ph->info->s_time);
	while (1)
	{
		if (!(eating(ph, &s_t) && sleeping(ph, s_t) && pickup(ph, s_t)))
			break ;
	}
	return (NULL);
}

int	pickup(t_philo *philo, long long s_t)
{
	while (1)
	{
		if (pickup_check(philo) == 1)
			return (1);
		if (check_time(philo, s_t))
			break ;
		usleep(300);
	}
	return (0);
}

int	pickup_check(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_mx_l);
	if (*philo->fork_l != philo->idx)
	{
		mutex_print(philo, "has taken a fork");
		if (*philo->fork_l == -1)
			*philo->fork_l = 1;
		pthread_mutex_unlock(philo->fork_mx_l);
		pthread_mutex_lock(philo->fork_mx_r);
		if (*philo->fork_r != philo->idx)
		{
			mutex_print(philo, "has taken a fork");
			pthread_mutex_unlock(philo->fork_mx_r);
			return (1);
		}
		else
		{
			pthread_mutex_unlock(philo->fork_mx_r);
			pthread_mutex_lock(philo->fork_mx_l);
		}
	}
	pthread_mutex_unlock(philo->fork_mx_l);
	return (0);
}

int	eating(t_philo *philo, long long *s_t)
{
	*s_t = get_time();
	if (mutex_print(philo, "is eating"))
		return (0);
	if (++philo->count == \
		philo->info->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(philo->fork_mx_l);
		pthread_mutex_lock(philo->fork_mx_r);
		*(philo->fork_l) = philo->idx;
		*(philo->fork_r) = philo->idx;
		pthread_mutex_unlock(philo->fork_mx_l);
		pthread_mutex_unlock(philo->fork_mx_r);
		return (0);
	}
	while (get_time() - *s_t < philo->info->time_to_eat)
		usleep(100);
	pthread_mutex_lock(philo->fork_mx_l);
	pthread_mutex_lock(philo->fork_mx_r);
	*(philo->fork_l) = philo->idx;
	*(philo->fork_r) = philo->idx;
	pthread_mutex_unlock(philo->fork_mx_l);
	pthread_mutex_unlock(philo->fork_mx_r);
	return (1);
}

int	sleeping(t_philo *philo, long long s_t)
{
	long long	c_t;

	c_t = get_time();
	if (mutex_print(philo, "is sleeping"))
		return (0);
	while (get_time() - c_t < philo->info->time_to_sleep)
	{
		if (check_time(philo, s_t))
			return (0);
		usleep(300);
	}
	if (mutex_print(philo, "is thinking"))
		return (0);
	usleep(400);
	return (1);
}
