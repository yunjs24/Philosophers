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
	int		i;
	t_philo	philo;

	i = 0;
	philo = *(t_philo *)atr;
	while (1)
	{
		sem_wait(philo.time);
		if (get_time() - *philo.r_time >= philo.info->time_to_die)
		{
			sem_print(philo, "died", 1);
			break ;
		}
		sem_post(philo.time);
		usleep(100);
	}
	// while (i < philo.info->number_of_philosophers)
	// {
	// 	kill(&philo[i].pid, SIGINT);
	// 	i++;
	// }
	exit(0);
}
