/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:13:50 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/24 08:04:48 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_data(t_philo *philo, t_info *info, int num)
{
	int	err;

	err = 0;
	sem_unlink("sem_dead");
	sem_unlink("sem_fork");
	sem_unlink("sem_full");
	sem_unlink("sem_print");
	sem_unlink("sem_time");
	err = init_sem(info, num);
	if (err == 1)
		return (6);
	if (init_philo(philo, num, info) == 1)
		return (7);
	return (0);
}

int	init_philo(t_philo *philo, int num, t_info *info)
{
	int	i;

	i = 0;
	while (i < num)
	{
		philo[i].time = sem_open("sem_time", O_CREAT, 0644, 1);
		if (philo[i].time == SEM_FAILED)
			return (1);
		philo[i].count = 0;
		philo[i].idx = (i + 1);
		philo[i].info = info;
		i++;
	}
	return (0);
}

int	init_sem(t_info *info, int num)
{
	info->dead = sem_open("sem_dead", O_CREAT | O_EXCL, 0644, 1);
	if (info->dead == SEM_FAILED)
		return (1);
	info->fork = sem_open("sem_fork", O_CREAT | O_EXCL, 0644, num);
	if (info->fork == SEM_FAILED)
	{
		sem_close(info->dead);
		return (1);
	}
	info->full = sem_open("sem_full", O_CREAT | O_EXCL, 0644, num);
	if (info->full == SEM_FAILED)
	{
		sem_close(info->dead);
		sem_close(info->fork);
		return (1);
	}
	info->sem_pr = sem_open("sem_print", O_CREAT | O_EXCL, 0644, 1);
	if (info->sem_pr == SEM_FAILED)
	{
		sem_close(info->dead);
		sem_close(info->fork);
		sem_close(info->full);
		return (1);
	}
	return (0);
}
