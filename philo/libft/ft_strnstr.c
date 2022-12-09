/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:06:38 by junsyun           #+#    #+#             */
/*   Updated: 2022/02/07 05:27:19 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		flag;

	i = -1;
	flag = 1;
	if (!ft_strlen(little))
		return ((char *)big);
	while (big[++i] && i < len)
	{
		j = 0;
		if (big[i] == little[0])
		{
			k = i;
			flag = 1;
			while (big[k] && little[j] && j < len && k < len)
				if (big[k++] != little[j++])
					flag = 0;
			if (flag && !little[j])
				return ((char *)big + i);
		}
	}
	return (NULL);
}
