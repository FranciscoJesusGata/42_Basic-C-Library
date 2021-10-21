/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:24:48 by fgata-va          #+#    #+#             */
/*   Updated: 2021/10/21 12:43:03 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	total_len = ft_strlen(s);
	if (start >= total_len)
		return (ft_strdup(""));
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i] != '\0')
	{
		substr[j] = s[i];
		j++;
		i++;
	}
	substr[j] = '\0';
	return (substr);
}
