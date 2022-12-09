/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:03:04 by junsyun           #+#    #+#             */
/*   Updated: 2022/03/30 12:42:23 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

long	handle_long_max(unsigned long *n, int sign)
{
	if (*n >= (unsigned long)LONG_MAX && sign == 1)
	{
		*n = (unsigned long)LONG_MAX;
		return (1);
	}
	if (*n >= (unsigned long)LONG_MAX + 1L && sign == -1)
	{
		*n = (unsigned long)LONG_MAX + 1L;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	ans;
	int				sign;
	int				i;

	i = 0;
	ans = 0;
	sign = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		ans = ans * 10 + (str[i++] - 48);
		if (handle_long_max(&ans, sign))
			break ;
	}
	return ((int)ans * sign);
}
