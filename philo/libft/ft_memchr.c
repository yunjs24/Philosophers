/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:40:42 by junsyun           #+#    #+#             */
/*   Updated: 2022/02/08 03:31:26 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s_buf;
	size_t	i;

	s_buf = (char *)s;
	i = -1;
	while (++i < n)
		if ((unsigned char)s_buf[i] == (unsigned char)c)
			return ((void *)s_buf + i);
	return (NULL);
}
