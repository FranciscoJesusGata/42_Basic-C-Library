/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:38:29 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/04 19:12:03 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *n, size_t len)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if ((int)ft_strlen(n) == 0)
		return ((char *)str);
	while (i < ((int)len) && str[i] != '\0')
	{
		if (n[0] == str[i])
		{
			while (n[j] != '\0' && n[j] == str[i + j] && (i + j) < (int)len)
			{
				if (n[j + 1] == '\0')
					return ((char *)&str[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
