/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:03:50 by fgata-va          #+#    #+#             */
/*   Updated: 2021/03/05 12:46:37 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = (void *)content;
	lst->next = NULL;
	return (lst);
}
