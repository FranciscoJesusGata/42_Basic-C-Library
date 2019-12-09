/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:59:15 by fgata-va          #+#    #+#             */
/*   Updated: 2019/11/19 13:13:11 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		l;

	l = ft_strlen(s1);
	s2 = (char *)malloc(l + 1);
	if (s2)
	{
		ft_memcpy(s2, s1, l);
		s2[l] = '\0';
	}
	else
		return (0);
	return (s2);
}
