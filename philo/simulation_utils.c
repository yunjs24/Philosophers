/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:52:42 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/24 08:08:06 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	s_t;
	long long		time;

	gettimeofday(&s_t, NULL);
	time = s_t.tv_sec * 1000 + s_t.tv_usec / 1000;
	return (time);
}

int	mutex_print(t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->info->print_mx);
	if (!((philo->info->block)))
	{
		printf("%lld %3d %s\n", \
		get_time() - philo->info->s_time, philo->idx, s);
	}
	else
	{
		pthread_mutex_unlock(&philo->info->print_mx);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->print_mx);
	return (0);
}

int	check_time(t_philo *philo, long long s_t)
{
	long long	c_t;

	c_t = get_time();
	if ((c_t) - (s_t) >= philo->info->time_to_die)
	{
		pthread_mutex_lock(&philo->info->print_mx);
		if (!(philo->info->block))
		{
			(philo->info->block) = philo->idx;
			printf("%lld %3d died\n", get_time() - \
			philo->info->s_time, philo->idx);
		}
		pthread_mutex_unlock(&philo->info->print_mx);
		return (1);
	}
	return (0);
}
