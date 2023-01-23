/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:13:39 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/18 17:56:19 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_all(t_philo *philo)
{
	int	i;

	i = 0;
	sem_close(philo->info->dead);
	sem_close(philo->info->fork);
	sem_close(philo->info->full);
	sem_close(philo->info->sem_pr);
	while (i < philo->info->number_of_philosophers)
	{
		sem_close(philo[i].time);
		i++;
	}
}
