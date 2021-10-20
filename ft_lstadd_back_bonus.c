/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:21:14 by fgata-va          #+#    #+#             */
/*   Updated: 2021/10/20 18:15:52 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*iterable;

	if (!lst || !new)
		return ;
	else if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		iterable = *lst;
		while (iterable->next != NULL)
			iterable = iterable->next;
		iterable->next = new;
	}
}
