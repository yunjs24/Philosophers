/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:14:26 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/24 08:04:39 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	simulation(t_philo *philo, t_info *info, int num)
{
	pthread_t	dead;

	sem_wait(info->dead);
	wait_pid(info, num);
	if (fork_phlio(philo, info, num) == 1)
	{
		free_all(philo);
		free(philo);
		exit(0);
	}
	pthread_create(&dead, NULL, is_dead, philo);
	wait_pid(info, num);
	exit(0);
}

void	wait_pid(t_info *info, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		sem_wait(info->full);
		i++;
	}
}

void	*is_dead(void *atr)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)atr;
	sem_wait(philo->info->dead);
	while (i < philo->info->number_of_philosophers)
	{
		kill(philo[i].pid, SIGINT);
		i++;
	}
	exit(0);
}

int	fork_phlio(t_philo *philo, t_info *info, int num)
{
	int	i;

	i = 0;
	info->s_time = get_time();
	info->put_t = info->s_time;
	while (i < num)
	{
		philo[i].pid = fork();
		if (philo[i].pid == -1)
			return (1);
		else if (philo[i].pid == 0)
		{
			if (live_or_die(philo[i]) == 0)
			{
				sem_post(info->full);
				exit(0);
			}
		}
		else
			i++;
	}
	return (0);
}
