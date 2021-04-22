/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:59:25 by fgata-va          #+#    #+#             */
/*   Updated: 2021/04/22 13:17:38 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_str(char *str, t_flags *data)
{
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(str);
	i = 0;
	if ((data->precision == 1) && data->precision_l < (int)len)
		len = data->precision_l;
	if (data->width > 0 && data->minus != 1)
		ft_width(data->width, len, data);
	if (data->zero > 0 && data->minus != 1)
		data->printed += ft_zero(len, data->zero);
	while (i < len && len != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	if (data->zero > 0 && data->minus == 1)
		ft_width(data->zero, len, data);
	if (data->width > 0 && data->minus == 1)
		ft_width(data->width, len, data);
	return (i);
}

int	ft_check_segfault(const char *f)
{
	int				i;
	int				ok;

	ok = 0;
	i = 0;
	while (f[i])
	{
		if (ft_strchr(CONVERSIONS, f[i]))
		{
			ok = 1;
		}
		i++;
	}
	return (ok);
}

int	ft_neg_star(int num, t_flags *data)
{
	if (data->precision == 1)
	{
		data->precision = 0;
		return (0);
	}
	data->minus = 1;
	return (num * -1);
}

int	ft_nbr_len(long int n, int base)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (n < base)
		return (1 + i);
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}
