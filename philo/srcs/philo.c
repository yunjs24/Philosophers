/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 05:38:58 by junsyun           #+#    #+#             */
/*   Updated: 2022/11/23 05:39:04 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	ft_check_valid(int ac, char **av)
{
	size_t	i;

	if (ac < 5 || ac > 6)
	{
		ft_check_args();
		return (1);
	}
	i = 1;
	while (av[i])
	{
		if (!ft_is_digit(av[i]) || (!ft_atoi(av[i])))
		{
			printf("Invalid arguments!\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	
	if (ft_check_valid(ac, av))
		return (1);
	if (ft_init_args(ac, av))
		return (1);
	ft_init_mutex(&args);
	/***
	 * todo:
	 * 1.	init philoss
	 * 2.	init threads
	 * 3.	end threads
	 * 4.	unlock & destroy mutex
		free_all(&args);
	 * 
	*/
	system("leaks philo")
}
