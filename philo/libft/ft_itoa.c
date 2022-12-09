/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:16:34 by junsyun           #+#    #+#             */
/*   Updated: 2022/04/01 14:10:18 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	while (s && s[i] && i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_strrev(char *str)
{
	char	tmp;
	size_t	i;
	size_t	length;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	str[12];
	int		sign;
	size_t	length;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 1;
	if (n < 0)
		sign = -1;
	if (n == 0)
		return (ft_strdup("0"));
	length = 0;
	n *= sign;
	while (n > 0)
	{
		str[length++] = '0' + n % 10;
		n = n / 10;
	}
	if (sign == -1)
		str[length++] = '-';
	str[length] = 0;
	ft_strrev(str);
	return (ft_strndup(str, length));
}
