/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 07:29:32 by junsyun           #+#    #+#             */
/*   Updated: 2022/12/18 07:35:28 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->info->print_mx);
	philo->info->block = 1;
	while (i < philo->info->number_of_philosophers)
	{
		if (pthread_create(&philo[i].id, NULL, \
		live_or_die, (void *)&philo[i]) != 0)
		{
			free_pthread(philo, i);
			return (7);
		}
		i++;
	}
	philo->info->start = get_time();
	philo->info->block = 0;
	pthread_mutex_unlock(&philo->info->print_mx);
	i = 0;
	while (i < philo->info->number_of_philosophers)
	{
		pthread_join(philo[i].id, NULL);
		i++;
	}
	return (0);
}
