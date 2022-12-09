/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:14:37 by junsyun           #+#    #+#             */
/*   Updated: 2022/04/01 15:24:43 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_alloc_size(char const *s, unsigned int start, size_t len)
{
	size_t	len_of_s;

	len_of_s = ft_strlen(s);
	if (start >= len_of_s)
		return (0);
	if (len_of_s - start > len)
		return (len);
	else
		return (len_of_s - start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ans;
	size_t	len_of_s;

	if (!s)
		return (NULL);
	len_of_s = ft_strlen(s);
	ans = (char *)malloc(sizeof(char) * (get_alloc_size(s, start, len) + 1));
	if (!ans)
		return (NULL);
	if (len_of_s <= start)
	{
		ans[0] = 0;
		return (ans);
	}
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		ans[j++] = s[i++];
	}
	ans[j] = 0;
	return (ans);
}
