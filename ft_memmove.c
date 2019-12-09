/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:02:50 by fgata-va          #+#    #+#             */
/*   Updated: 2019/11/19 13:12:56 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int		i;
	unsigned char		*str1;
	unsigned const char	*str2;

	if (dst == NULL && src == NULL)
		return (NULL);
	str1 = dst;
	str2 = src;
	i = 0;
	if (str2 < str1 && str1 < str2 + len)
	{
		str1 += len;
		str2 += len;
		while (len-- != 0)
			*--str1 = *--str2;
	}
	else
	{
		while (i < len)
		{
			str1[i] = str2[i];
			i++;
		}
	}
	return (dst);
}
