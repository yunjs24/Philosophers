/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:14:22 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/24 08:04:36 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	get_time(void)
{
	struct timeval	s_t;
	long long		time;

	gettimeofday(&s_t, NULL);
	time = s_t.tv_sec * 1000 + s_t.tv_usec / 1000;
	return (time);
}

void	sem_print(t_philo philo, char *s, int death_flag)
{
	sem_wait(philo.info->sem_pr);
	printf("%lld [%3d] %s\n", get_time() - philo.info->s_time, philo.idx, s);
	if (death_flag == 1)
	{
		sem_post(philo.info->dead);
		return ;
	}
	sem_post(philo.info->sem_pr);
}
