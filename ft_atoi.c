/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:43:44 by fgata-va          #+#    #+#             */
/*   Updated: 2019/11/20 16:17:56 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_clean_garbage(int i, const char *str)
{
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
		str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	return (i);
}

static int		ft_negative(int *n, const char c, int i)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
		{
			*n *= -1;
		}
		i++;
	}
	return (i);
}

static long		ft_store_nmb(int *x, const char *str, long resp, int n)
{
	int i;

	i = *x;
	while (str[i] >= 48 && str[i] <= 57)
	{
		resp = (resp * 10) + (str[i] - '0');
		if (resp > 2147483647 && n == 1)
			return (-1);
		else if (resp > 2147483648 && n == -1)
			return (0);
		i++;
	}
	*x = i;
	return (resp);
}

int				ft_atoi(const char *str)
{
	long			resp;
	int				i;
	int				n;

	i = 0;
	resp = 0;
	n = 1;
	i = ft_clean_garbage(i, str);
	i = ft_negative(&n, str[i], i);
	resp = ft_store_nmb(&i, str, resp, n);
	return ((int)(resp * n));
}
