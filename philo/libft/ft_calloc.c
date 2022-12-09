/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:27:17 by junsyun           #+#    #+#             */
/*   Updated: 2022/03/17 18:26:13 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	int		i;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	i = (int)nmemb * size;
	while (i--)
		p[i] = 0;
	return ((void *)p);
}
