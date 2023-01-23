/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:05:01 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/24 08:05:02 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_input(int argc, char **argv, t_info *info)
{
	if (argc < 5 || argc > 6)
		return (1);
	if (is_num(argc, argv) != 0)
		return (2);
	if (init_info(argc, argv, info) != 0)
		return (3);
	if (info->number_of_philosophers == 0)
		return (4);
	if (info->number_of_times_each_philosopher_must_eat == 0)
		return (5);
	return (0);
}

int	is_num(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (i < argc)
	{
		j = 0;
		len = (int)ft_strlen(argv[i]);
		while ((9 <= argv[i][j] && argv[i][j] <= 13) || argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '+')
			j++;
		while (j < len && ft_isdigit(argv[i][j]) == 1)
			j++;
		while ((9 <= argv[i][j] && argv[i][j] <= 13) || argv[i][j] == ' ')
			j++;
		if (len == 0 || j != len)
			return (2);
		i++;
	}
	return (0);
}

int	init_info(int argc, char **argv, t_info *info)
{
	info->number_of_philosophers = ft_atoi_pos(argv[1]);
	info->time_to_die = ft_atoi_pos(argv[2]);
	info->time_to_eat = ft_atoi_pos(argv[3]);
	info->time_to_sleep = ft_atoi_pos(argv[4]);
	info->number_of_times_each_philosopher_must_eat = -2;
	if (argc == 6)
		info->number_of_times_each_philosopher_must_eat = \
		ft_atoi_pos(argv[5]);
	if (info->number_of_philosophers == -1 || \
	info->number_of_times_each_philosopher_must_eat == -1 || \
	info->time_to_die == -1 || info->time_to_eat == -1 || \
	info->time_to_sleep == -1)
		return (3);
	return (0);
}
