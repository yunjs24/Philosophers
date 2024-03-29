/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:13:29 by junsyun           #+#    #+#             */
/*   Updated: 2023/01/24 08:04:52 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	while ((9 <= *str && *str <= 13) || *str == ' ')
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
