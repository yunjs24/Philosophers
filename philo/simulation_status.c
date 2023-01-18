/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:52:39 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/18 18:10:33 by junsyun          ###   ########.fr       */
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

int	pickup(t_philo *ph, long long s_t)
{
	while (1)
	{
		if (pickup_check(ph) == 1)
			return (1);
		if (check_time(ph, s_t))
			break ;
		usleep(300);
	}
	return (0);
}

int	pickup_check(t_philo *ph)
{
	pthread_mutex_lock(ph->fork_mx_l);
	if (*ph->fork_l != ph->idx)
	{
		pthread_mutex_unlock(ph->fork_mx_l);
		pthread_mutex_lock(ph->fork_mx_r);
		if (*ph->fork_r != ph->idx)
		{
			mutex_print(ph, "has taken a fork", 2);
			pthread_mutex_unlock(ph->fork_mx_r);
			return (1);
		}
		else
		{
			pthread_mutex_unlock(ph->fork_mx_r);
			pthread_mutex_lock(ph->fork_mx_l);
		}
	}
	pthread_mutex_unlock(ph->fork_mx_l);
	return (0);
}

int	eating(t_philo *ph, long long *s_t)
{
	*s_t = get_time();
	if (mutex_print(ph, "is eating", 1))
		return (0);
	if (++ph->count == ph->info->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(ph->fork_mx_l);
		pthread_mutex_lock(ph->fork_mx_r);
		*(ph->fork_l) = ph->idx;
		*(ph->fork_r) = ph->idx;
		pthread_mutex_unlock(ph->fork_mx_l);
		pthread_mutex_unlock(ph->fork_mx_r);
		return (0);
	}
	while (get_time() - *s_t <= ph->info->time_to_eat)
		usleep(100);
	pthread_mutex_lock(ph->fork_mx_l);
	pthread_mutex_lock(ph->fork_mx_r);
	*(ph->fork_l) = ph->idx;
	*(ph->fork_r) = ph->idx;
	pthread_mutex_unlock(ph->fork_mx_l);
	pthread_mutex_unlock(ph->fork_mx_r);
	return (1);
}

int	sleeping(t_philo *ph, long long s_t)
{
	long long	c_t;

	c_t = get_time();
	if (mutex_print(ph, "is sleeping", 1))
		return (0);
	while (get_time() - c_t < ph->info->time_to_sleep)
	{
		if (check_time(ph, s_t))
			return (0);
		usleep(300);
	}
	if (mutex_print(ph, "is thinking", 1))
		return (0);
	usleep(400);
	return (1);
}
