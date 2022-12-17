/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:34:24 by junsyun           #+#    #+#             */
/*   Updated: 2022/12/17 16:54:34 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi_pos(const char *str)
{
	size_t	num;

	num = 0;
	while ((0 <= *str && *str <= 13) || *str == ' ')
		str++;
	if ('+' == *str)
		str++;
	while ('0' <= *str && *str <= '9')
	{
		num = (num * 10) + (*str - 48);
		if (num > 2147483647)
			return (-1);
		str++;
	}
	return (num);
}
