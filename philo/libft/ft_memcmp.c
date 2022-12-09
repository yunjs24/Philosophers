/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:42:46 by junsyun           #+#    #+#             */
/*   Updated: 2022/02/07 05:39:41 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_buf;
	unsigned char	*s2_buf;
	size_t			i;

	i = -1;
	s1_buf = (unsigned char *)s1;
	s2_buf = (unsigned char *)s2;
	while (++i < n && s1_buf[i] == s2_buf[i])
		;
	if (i == n)
		return (0);
	return (s1_buf[i] - s2_buf[i]);
}
