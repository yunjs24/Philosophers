/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:52:42 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/18 17:49:23 by junsyun          ###   ########.fr       */
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

int	mutex_print(t_philo *ph, char *s, int n)
{
	int			i;

	i = 0;
	pthread_mutex_lock(&ph->info->print_mx);
	if (!((ph->info->block)))
	{
		while (i < n)
		{
			printf("%lld [%3d] %s\n", get_time() - ph->info->s_time, ph->idx, s);
			i++;
		}
	}
	else
	{
		pthread_mutex_unlock(&ph->info->print_mx);
		return (1);
	}
	pthread_mutex_unlock(&ph->info->print_mx);
	return (0);
}

int	check_time(t_philo *ph, long long s_t)
{
	long long	c_t;

	c_t = get_time();
	if ((c_t) - (s_t) >= ph->info->time_to_die)
	{
		pthread_mutex_lock(&ph->info->print_mx);
		if (!(ph->info->block))
		{
			(ph->info->block) = ph->idx;
			printf("%lld [%3d] died\n", get_time() - \
			ph->info->s_time, ph->idx);
		}
		pthread_mutex_unlock(&ph->info->print_mx);
		return (1);
	}
	return (0);
}
