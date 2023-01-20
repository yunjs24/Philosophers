/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:14:04 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/18 18:10:03 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor(void *atr)
{
	t_philo	philo;

	philo = *(t_philo *)atr;
	while (1)
	{
		sem_wait(philo.time);
		if (get_time() - *philo.r_time >= philo.info->time_to_die)
		{
			sem_print(philo, "is dead", 1);
			break ;
		}
		sem_post(philo.time);
		usleep(100);
	}
	exit(0);
}
