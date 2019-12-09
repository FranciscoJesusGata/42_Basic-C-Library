/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:52:37 by fgata-va          #+#    #+#             */
/*   Updated: 2019/11/19 13:13:50 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_getstart(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	encountered;

	i = 0;
	j = 0;
	encountered = 0;
	while (s1[i] != '\0')
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				encountered = 1;
			j++;
		}
		if (encountered == 0)
			return (i);
		j = 0;
		encountered = 0;
		i++;
	}
	return (i);
}

static size_t		ft_getlen(char const *s1, char const *set, unsigned int s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	encountered;

	i = ft_strlen(s1) - 1;
	j = 0;
	encountered = 0;
	while (i > s)
	{
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				encountered = 1;
			j++;
		}
		if (encountered == 0)
			return (i - s + 1);
		j = 0;
		encountered = 0;
		i--;
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
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
	str[ft_strlen(str)] = '\0';
	return (str);
}
