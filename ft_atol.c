/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:23:02 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/09 11:11:50 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_save_long(int i, const char *str, int negative)
{
	long long	nbr;

	nbr = 0;
	while (ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if ((nbr > 9223372036854775807 || nbr < -9223372036854775807)
			&& negative > 0)
			return (9223372036854775807);
		i++;
	}
	return (nbr * negative);
}

long	ft_atol(const char *str)
{
	int	i;
	int	negative;

	i = 0;
	negative = 1;
	while (ft_strchr("\t\n\v\f\r ", str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i])
			negative *= -1;
		i++;
	}
	return (ft_save_long(i, str, negative));
}
