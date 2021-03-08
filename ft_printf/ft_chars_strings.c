/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:12:55 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/05 13:38:30 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strings(va_list ap, t_flags *data)
{
	const char	*str;

	str = (const char *)va_arg(ap, const char *);
	if (str && ft_strlen(str) > 0)
		data->printed += ft_write_str((char *)str, data);
	else if (str == NULL)
		data->printed += ft_write_str("(null)", data);
	else
		data->printed += ft_write_str("", data);
}

void	ft_chrs(va_list ap, t_flags *data)
{
	char	c;

	c = va_arg(ap, int);
	if (data->width > 0 && data->minus != 1)
		ft_width(data->width, 1, data);
	data->printed += write(1, &c, 1);
	if (data->width > 0 && data->minus == 1)
		ft_width(data->width, 1, data);
}

void	ft_percent(t_flags *data)
{
	if (data->width > 0 && data->minus != 1)
		ft_width(data->width, 1, data);
	if (data->zero > 0 && data->minus != 1)
		data->printed += ft_zero(1, data->zero);
	data->printed += write(1, "%", 1);
	if (data->width > 0 && data->minus == 1)
		ft_width(data->width, 1, data);
	if (data->zero > 0 && data->minus == 1)
		ft_width(data->zero, 1, data);
}
