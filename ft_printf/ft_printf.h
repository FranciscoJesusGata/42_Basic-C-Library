/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:10:34 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/08 10:53:51 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define ALLSIMBOLS "cspdiuxX%-.*0123456789"
# define CONVERSIONS "cspdiuxX%"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

typedef struct	s_printf
{
	int		printed;
	int		minus;
	int		zero;
	int		precision;
	int		precision_l;
	int		width;
	int		negative;
}				t_flags;

int				ft_printf(const char *format, ...);
void			ft_strings(va_list ap, t_flags *data);
void			ft_chrs(va_list ap, t_flags *data);
int				ft_write_str(char *str, t_flags *data);
void			ft_reset_data(t_flags *data);
void			ft_getwidth(const char *f, int *i, t_flags *d, va_list ap);
void			ft_width(int width, int str_lenght, t_flags *data);
void			ft_prnt_int(va_list ap, t_flags *data);
void			ft_putnbr_modified(int n, t_flags *data);
int				ft_control_star(const char *f, int *i, va_list ap, t_flags *d);
int				ft_neg_star(int num, t_flags *data);
void			ft_percent(t_flags *data);
int				ft_zero(int l, int zeros);
void			ft_print_hex(va_list ap, t_flags *data, int mayus);
int				ft_totaldgts(t_flags *data, int dgts);
void			ft_prnt_unsig(va_list ap, t_flags *data);
void			ft_print_pointer(va_list ap, t_flags *data);
int				ft_check_segfault(const char *f);
int				ft_nbr_len(long int n, int base);

#endif
