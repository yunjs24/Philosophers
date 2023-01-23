/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:13:44 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/18 16:08:01 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	error_handle(int i)
{
	if (i == 1)
		error_write("Error\nparam count wrong\n");
	if (i == 2)
		error_write("Error\nparam value wrong\n");
	if (i == 3)
		error_write("Error\nPush number in 0 ~ 2147483647\n");
	if (i == 4)
		error_write("Error\nThere are no Philosophers\n");
	if (i == 5)
		error_write("Error\nInput meal count bigger than 0\n");
	if (i == 6)
		error_write("Error\nsem_t init fail\n");
	if (i == 7)
		error_write("Error\nblock init fail\n");
	if (i == 8)
		error_write("Error\nfork malloc failed!\n");
	return (1);
}

void	error_write(char *str)
{
	write(1, str, ft_strlen(str));
}
