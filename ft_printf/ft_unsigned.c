/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:27:06 by fgata-va          #+#    #+#             */
/*   Updated: 2021/02/11 10:01:07 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_putnbr_unsigned(unsigned int n, t_flags *data)
{
	char			c;

	if (data->precision != 1 ||
		(data->precision == 1 && data->precision_l != 0))
	{
		if (data->negative == 1 && data->zero == 0 && data->precision_l == 0)
		{
			data->printed += write(1, "-", 1);
			data->negative = 0;
		}
		if (n > 9)
		{
			ft_putnbr_modified(n / 10, data);
		}
		c = (n % 10) + '0';
		data->printed += write(1, &c, 1);
	}
}

void				ft_prnt_unsig(va_list ap, t_flags *data)
{
	unsigned int	prnt;
	int				dgts;
	char			*tmp;

	prnt = va_arg(ap, unsigned int);
	tmp = ft_itoa(prnt);
	dgts = ft_strlen(tmp);
	free(tmp);
	if (data->width > 0 && data->minus != 1)
		ft_width(data->width, ft_totaldgts(data, dgts), data);
	if (data->zero > 0 && data->precision == 1)
		ft_width(data->zero, ft_totaldgts(data, dgts), data);
	if (data->zero > 0 && data->minus != 1 && data->precision == 0)
		data->printed += ft_zero(dgts, data->zero);
	if (data->precision == 1 && data->precision_l > dgts)
		data->printed += ft_zero(dgts, data->precision_l);
	ft_putnbr_unsigned(prnt, data);
	if (data->precision == 1 && data->precision_l == 0 && data->width > 0)
		data->printed += write(1, " ", 1);
	if (data->width > 0 && data->minus == 1)
		ft_width(data->width, ft_totaldgts(data, dgts), data);
}
