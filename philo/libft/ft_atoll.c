/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:52:54 by junsyun           #+#    #+#             */
/*   Updated: 2022/12/09 10:52:56 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static long long	atoi_range(const char *str, long long long_max,
	long long long_min, int flag)
{
	unsigned long long	return_value;
	int					cnt;

	return_value = 0;
	cnt = 0;
	while (*str >= '0' && *str <= '9')
	{
		cnt++;
		if (cnt < 20)
			return_value = return_value * 10 + *str - 48;
		if (flag == 1 && (cnt > 19
				|| return_value >= (unsigned long long)long_max))
			return (long_max);
		else if (flag == -1 && (cnt > 20
				|| return_value >= (unsigned long long)long_max + 1))
			return (long_min);
		str++;
	}
	return (return_value * flag);
}

long long	ft_atoll(const char *str)
{
	long long	long_mx;
	long long	long_mn;
	long long	return_value;
	int			flag;

	long_mx = 9223372036854775807L;
	long_mn = -long_mx -1L;
	flag = 1;
	while (ft_isspace(*str))
		str++;
	if ((*str == '-' || *str == '+'))
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	return_value = atoi_range(str, long_mx, long_mn, flag);
	return (return_value);
}
