/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:10:38 by fgata-va          #+#    #+#             */
/*   Updated: 2020/02/17 14:05:11 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void		ft_conversions(va_list ap, char c, t_flags *data)
{
	if (c == 'c')
		ft_chrs(ap, data);
	else if (c == 's')
		ft_strings(ap, data);
	else if (c == 'd' || c == 'i')
		ft_prnt_int(ap, data);
	else if (c == '%')
		ft_percent(data);
	else if (c == 'x')
		ft_print_hex(ap, data, 0);
	else if (c == 'X')
		ft_print_hex(ap, data, 1);
	else if (c == 'u')
		ft_prnt_unsig(ap, data);
	else if (c == 'p')
		ft_print_pointer(ap, data);
}

void		ft_modifiers(const char *f, int *i, t_flags *data, va_list ap)
{
	char	c;

	c = f[*i];
	if (c == '-' && data->width == 0)
		data->minus = 1;
	else if (ft_strchr("123456789*", c))
		ft_getwidth(f, i, data, ap);
	else if (c == '0')
		data->zero = ft_control_star(f, i, ap, data);
	else if (c == '.')
	{
		data->precision = 1;
		data->precision_l = ft_control_star(f, i, ap, data);
	}
}

void		ft_parse_str(t_flags *data, const char *format, va_list ap, int *i)
{
	if (ft_strchr(CONVERSIONS, format[*i]))
	{
		ft_conversions(ap, format[*i], data);
		ft_reset_data(data);
	}
	else
		ft_modifiers(format, i, data, ap);
}

int			ft_manageformat(t_flags *data, const char *format, va_list ap)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			data->printed += write(1, &format[i], 1);
		else if (format[i] == '%' && ft_check_segfault((format + i + 1)) == 1)
		{
			while (ft_strchr(ALLSIMBOLS, format[i]))
			{
				i++;
				ft_parse_str(data, format, ap, &i);
				if (ft_strchr(CONVERSIONS, format[i]))
				{
					i++;
					break ;
				}
			}
			continue;
		}
		i++;
	}
	return (data->printed);
}

int			ft_printf(const char *format, ...)
{
	t_flags	*data;
	va_list ap;
	int		printed;

	va_start(ap, format);
	data = malloc(sizeof(t_flags));
	data->printed = 0;
	ft_reset_data(data);
	ft_manageformat(data, format, ap);
	printed = data->printed;
	free(data);
	return (printed);
}
