/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 07:40:19 by junsyun           #+#    #+#             */
/*   Updated: 2022/12/18 08:20:22 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	s_t;

	gettimeofday(&s_t, NULL);
	return (s_t.tv_sec * 1000 + s_t.tv_usec / 1000);
}

int	mutex_print(t_philo *arr, char *s, long long c_t)
{
	pthread_mutex_lock(&arr->info->print_mx);
	if (!((arr->info->block)))
		printf("%lld [%3d] %s\n", c_t - arr->info->start, arr->idx, s);
	else
	{
		pthread_mutex_unlock(&arr->info->print_mx);
		return (1);
	}
	pthread_mutex_unlock(&arr->info->print_mx);
	return (0);
}

int	check_time(t_philo *arr, long long start)
{
	long long	c_t;

	c_t = get_time();
	if ((c_t - start) > arr->info->time_to_die)
	{
		pthread_mutex_lock(&arr->info->print_mx);
		if (!(arr->info->block))
		{
			arr->info->block = arr->idx;
			printf("%lld %3d died\n", c_t - arr->info->start, arr->idx);
		}
		pthread_mutex_unlock(&arr->info->print_mx);
		return (1);
	}
	return (0);
}
