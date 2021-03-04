/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:36:39 by fgata-va          #+#    #+#             */
/*   Updated: 2020/02/12 19:11:51 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_hex_len(unsigned int num)
{
	int				i;
	unsigned int	n;

	i = 0;
	n = num;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void				ft_dec_to_hex(unsigned int num, t_flags *data, int mayus)
{
	char			c;
	unsigned int	h;

	c = 0;
	h = 0;
	if (num > 0)
	{
		ft_dec_to_hex(num / 16, data, mayus);
		h = num % 16;
		if (h > 9)
		{
			if (mayus == 0)
				c = (h - 10) + 'a';
			else
				c = (h - 10) + 'A';
		}
		else if (h <= 9)
			c = h + '0';
		data->printed += write(1, &c, 1);
	}
}

void				ft_print_hex(va_list ap, t_flags *data, int mayus)
{
	unsigned int	dec;
	int				l;

	dec = va_arg(ap, unsigned int);
	l = ft_hex_len(dec);
	if (data->width > 0 && data->minus != 1)
		ft_width(data->width, ft_totaldgts(data, l), data);
	if (data->zero > 0 && data->precision == 1)
		ft_width(data->zero, ft_totaldgts(data, l), data);
	if (data->zero > 0 && data->minus != 1 && data->precision == 0)
		data->printed += ft_zero(l, data->zero);
	if (data->precision == 1 && data->precision_l > l)
		data->printed += ft_zero(l, data->precision_l);
	if (dec == 0 && (data->precision == 0 ||
	(data->precision == 1 && data->precision_l > 0)))
		data->printed += write(1, "0", 1);
	else if (data->precision == 0 ||
	(data->precision == 1 && data->precision_l > 0))
		ft_dec_to_hex(dec, data, mayus);
	else if (data->precision_l > 0 || data->width > 0)
		data->printed += write(1, " ", 1);
	if (data->width > 0 && data->minus == 1)
		ft_width(data->width, ft_totaldgts(data, l), data);
}
