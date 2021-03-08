/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:52:37 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/05 11:26:02 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_getstart(char const *s1, char const *set)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (!(ft_strchr(set, s1[i])))
			return (i);
		i++;
	}
	return (i);
}

static size_t	ft_getlen(char const *s1, char const *set, unsigned int s)
{
	unsigned int	i;

	i = ft_strlen(s1) - 1;
	if (i == s)
		return (1);
	while (i >= s)
	{
		if (!(ft_strchr(set, s1[i])))
			return (i - s + 1);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	start;
	size_t			len;

	if (!s1 || ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = ft_getstart(s1, set);
	len = ft_getlen(s1, set, start);
	str = ft_substr(s1, start, len);
	if (str == NULL)
		return (NULL);
	return (str);
}
