/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:52:25 by junsyun           #+#    #+#             */
/*   Updated: 2022/12/19 18:22:54 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_fork(t_info *info, t_fork *fork, int num)
{
	if (create_fork(num, fork) == 1)
		return (8);
	if (init_print_mx(info) == 1)
	{
		free(fork->forks);
		fork->forks = 0;
		return (5);
	}
	if (init_fork_mx(num, fork) == 1)
	{
		pthread_mutex_destroy(&info->print_mx);
		free(fork->fork_mx);
		free(fork->forks);
		fork->forks = 0;
		return (6);
	}
	return (0);
}

int	create_fork(int num, t_fork *fork)
{
	int	i;

	i = 0;
	fork->forks = (int *)malloc(sizeof(int) * num);
	if (fork->forks == NULL)
		return (1);
	if (num == 1)
		fork->forks[0] = -1;
	else
	{
		while (i < num)
		{
			if (i % 2 == 0)
				fork->forks[i] = 0;
			else
				fork->forks[i] = i + 1;
			if (i == num - 1)
				fork->forks[i] = num;
			i++;
		}
	}	
	return (0);
}

int	init_fork_mx(int num, t_fork *fork)
{
	int	i;

	i = 0;
	fork->fork_mx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (fork->fork_mx == NULL)
		return (1);
	while (i < num)
	{
		if (pthread_mutex_init(&fork->fork_mx[i], NULL) != 0)
		{
			free_mutex(fork->fork_mx, i);
			free(fork->fork_mx);
			fork->fork_mx = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_print_mx(t_info *info)
{
	if (pthread_mutex_init(&info->print_mx, NULL) != 0)
		return (1);
	return (0);
}

int	init_philo(t_philo *philo, t_info *info, t_fork *fork, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		philo[i].count = 0;
		philo[i].idx = i + 1;
		philo[i].fork_l = &fork->forks[i];
		philo[i].fork_r = &fork->forks[(i + 1) % num];
		philo[i].fork_mx_l = &fork->fork_mx[i];
		philo[i].fork_mx_r = &fork->fork_mx[(i + 1) % num];
		philo[i].info = info;
		i++;
	}
	return (0);
}
