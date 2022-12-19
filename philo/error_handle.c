/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:52:17 by junsyun           #+#    #+#             */
/*   Updated: 2022/12/19 14:54:45 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_handle(int i)
{
	if (i == 1)
		error_write("Error\nparam count wrong\n");
	if (i == 2)
		error_write("Error\nparam value wrong\n");
	if (i == 3)
		error_write("Error\nPush number in 0 ~ 2147483647\n");
	if (i == 4)
		error_write("Error\nbool_fork malloc fail\n");
	if (i == 5)
		error_write("Error\ninfo_mutex is wrong\n");
	if (i == 6)
		error_write("Error\nfork_mx is wrong\n");
	if (i == 7)
		error_write("Error\npthread creat fail\n");
	if (i == 8)
		error_write("Error\nphilo is a zero\n");
	if (i == 9)
		error_write("Error\nwhat does it mean to eat 0 times?\n");
	return (1);
}

void	error_write(char *str)
{
	write(1, str, ft_strlen(str));
}
