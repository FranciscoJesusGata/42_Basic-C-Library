/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:58:10 by fgata-va          #+#    #+#             */
/*   Updated: 2020/11/20 13:33:28 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_totaldgts(t_flags *data, int dgts)
{
	int		diff;

	diff = 0;
	if (data->precision == 1 && data->precision_l > dgts)
		diff = data->precision_l - dgts;
	else if (data->zero > dgts && data->precision == 0 && data->minus != 1)
		diff = data->zero - dgts;
	if (data->negative == 1 &&
	(diff > 0 || (data->minus == 1 && data->zero == 0)))
		diff += 1;
	return (dgts + diff);
}

void		ft_putnbr_modified(int n, t_flags *data)
{
	char	c;

	if (n <= 2147483647 && n > -2147483648 &&
	(data->precision != 1 || (data->precision == 1 && data->precision_l != 0)))
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

int			ft_zero(int l, int zeros)
{
	int		i;
	int		prnt;

	i = 0;
	prnt = 0;
	while (i < (zeros - l))
	{
		prnt += write(1, "0", 1);
		i++;
	}
	return (prnt);
}

void		ft_int_flags(t_flags *data, int *dgts)
{
	if (data->width > 0 && data->minus != 1)
		ft_width(data->width, ft_totaldgts(data, *dgts), data);
	if (data->zero > 0 && data->precision == 1)
		ft_width(data->zero, ft_totaldgts(data, *dgts), data);
	if ((data->zero > 0 || data->precision_l > 0) && data->negative == 1)
	{
		data->printed += write(1, "-", 1);
		if (data->precision_l > 0)
			*dgts -= 1;
	}
	if (data->zero > 0 && data->minus != 1 && data->precision == 0)
		data->printed += ft_zero(*dgts, data->zero);
	if (data->precision == 1 && data->precision_l > *dgts)
		data->printed += ft_zero(*dgts, data->precision_l);
}

void		ft_prnt_int(va_list ap, t_flags *data)
{
	long long int	prnt;
	int				dgts;
	char			*tmp;

	prnt = va_arg(ap, int);
	tmp = ft_itoa(prnt);
	dgts = ft_strlen(tmp);
	free(tmp);
	if (prnt < 0 && prnt > -2147483648)
	{
		data->negative = 1;
		prnt *= -1;
	}
	ft_int_flags(data, &dgts);
	if (prnt <= -2147483648)
		data->printed += write(1, "-2147483648", 11);
	else
		ft_putnbr_modified(prnt, data);
	if (data->precision == 1 && data->precision_l == 0 && data->width > 0)
		data->printed += write(1, " ", 1);
	if (data->zero > 0 && data->minus == 1)
		data->width = data->zero;
	if (data->width > 0 && data->minus == 1)
		ft_width(data->width, ft_totaldgts(data, dgts), data);
}
