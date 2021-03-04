/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:17:05 by fgata-va          #+#    #+#             */
/*   Updated: 2020/02/17 14:12:41 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_data(t_flags *data)
{
	data->minus = 0;
	data->zero = 0;
	data->precision = 0;
	data->precision_l = 0;
	data->width = 0;
	data->negative = 0;
}

void	ft_getwidth(const char *f, int *i, t_flags *d, va_list ap)
{
	if (f[*i] == '*')
	{
		d->width = va_arg(ap, int);
		if (d->width < 0)
		{
			d->width *= -1;
			d->minus = 1;
		}
		i += 1;
	}
	else
	{
		d->width = ft_atoi(f + *i);
		while (ft_isdigit(f[*i]))
			*i += 1;
		*i -= 1;
	}
}

void	ft_width(int width, int str_length, t_flags *data)
{
	int	i;
	int	spaces;

	if (str_length < width)
	{
		i = 0;
		if (str_length == 0)
			spaces = width;
		else
			spaces = (width - str_length);
		while (i < spaces)
		{
			data->printed += write(1, " ", 1);
			i++;
		}
	}
}

int		ft_control_star(const char *f, int *i, va_list ap, t_flags *data)
{
	int	num;

	num = 0;
	*i += 1;
	if (ft_strchr("1234567890", f[*i]))
	{
		num = ft_atoi(f + *i);
		while (ft_isdigit(f[*i + 1]))
			*i += 1;
	}
	else if ('*' == f[*i])
	{
		num = va_arg(ap, int);
		if (num < 0)
			num = ft_neg_star(num, data);
	}
	else
		*i -= 1;
	return (num);
}
