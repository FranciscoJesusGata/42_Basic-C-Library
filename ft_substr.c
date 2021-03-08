/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:24:48 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/04 19:13:08 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subst;
	size_t	maxl;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	maxl = ft_strlen(s);
	if (start >= maxl)
		return (ft_strdup(""));
	subst = (char *)malloc(sizeof(char) * len + 1);
	if (!subst)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i] != '\0')
	{
		subst[j] = s[i];
		j++;
		i++;
	}
	subst[j] = '\0';
	return (subst);
}
