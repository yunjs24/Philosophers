/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 08:20:27 by junsyun           #+#    #+#             */
/*   Updated: 2022/12/18 08:20:28 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mutex(pthread_mutex_t *fork_mx, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&fork_mx[i]);
		i++;
	}
}

void	free_pthread(t_philo *philo, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_detach(philo->id);
		i++;
	}
}

void	free_all(t_philo *philo, t_part *part, t_info *info)
{
	free_mutex(part->fork_mx, info->number_of_philosophers);
	pthread_mutex_destroy(&info->print_mx);
	free(part->fork_mx);
	free(part->bool_fork);
	part->bool_fork = 0;
	free(philo);
	philo = 0;
}
