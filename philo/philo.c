/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:52:31 by junsyun           #+#    #+#             */
/*   Updated: 2022/12/19 14:52:32 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(int argc, char **argv)
{
	int			err;
	t_info		info;
	t_philo		*philo;
	t_part		part;

	err = check_input(argc, argv, &info);
	if (err != 0)
		return (error_handle(err));
	philo = (t_philo *)malloc(sizeof(t_philo) * info.number_of_philosophers);
	if (philo == NULL)
		return (error_handle(6));
	err = check_init(&info, &part, philo, info.number_of_philosophers);
	if (err != 0)
		return (error_handle(err));
	err = simulation(philo);
	free_all(philo, &part, &info);
	if (err != 0)
		return (error_handle(err));
	return (0);
}

int	check_init(t_info *info, t_part *part, t_philo *philo, int num)
{
	int	err;

	err = 0;
	err = init_part(info, part, num);
	if (err != 0)
		return (err);
	err = init_philo(philo, info, part, num);
	if (err != 0)
	{
		free_mutex(part->fork_mx, num);
		pthread_mutex_destroy(&info->print_mx);
		free(part->fork_mx);
		free(part->bool_fork);
		part->bool_fork = 0;
		return (err);
	}
	return (0);
}
