/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:01:49 by junsyun           #+#    #+#             */
/*   Updated: 2022/12/09 10:07:42 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_info	info;
	
	if (ft_check_valid(ac, av))
		return (1);
	if (ft_init_args(&info, ac, av))
		return (1);
	ft_init_mutex(&info);
	/***
	 * todo:
	 * 1.	init philoss
	 * 2.	init threads
	 * 3.	end threads
	 * 4.	unlock & destroy mutex
		free_all(&info);
	 * 
	*/
	system("leaks philo");
}
