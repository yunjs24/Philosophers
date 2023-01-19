/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:14:08 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/18 17:46:57 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_bonus(int argc, char **argv)
{
	int			err;
	t_info		info;
	t_philo		*philo;

	err = check_input(argc, argv, &info);
	if (err != 0)
		return (error_handle(err));
	philo = (t_philo *)malloc(sizeof(t_philo) * info.number_of_philosophers);
	if (philo == NULL)
		return (error_handle(6));
	err = init_data(philo, &info, info.number_of_philosophers);
	if (err != 0)
		return (error_handle(err));
	err = simulation(philo, &info, info.number_of_philosophers);
	return (0);
}
