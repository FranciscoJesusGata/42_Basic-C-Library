/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:10:06 by fgata-va          #+#    #+#             */
/*   Updated: 2019/11/19 13:13:45 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *s, int c)
{
	int				i;

	i = (int)ft_strlen(s);
	while (i >= 0)
	{
		if (c == s[i])
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
