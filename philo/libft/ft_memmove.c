/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:41:00 by junsyun           #+#    #+#             */
/*   Updated: 2022/03/31 19:55:37 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst_byte;
	unsigned char	*src_byte;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	i = -1;
	dst_byte = dest;
	src_byte = (unsigned char *)src;
	if (dst_byte <= src_byte)
		while (++i < n)
			dst_byte[i] = src_byte[i];
	else
		while ((int)(--n) >= 0)
			dst_byte[n] = src_byte[n];
	return (dest);
}
