/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 20:36:46 by fgata-va          #+#    #+#             */
/*   Updated: 2019/12/09 11:52:34 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list *newlst;
	t_list *rlst;

	if (!l || !f)
		return (NULL);
	if (!(newlst = ft_lstnew((*f)(l->content))))
		return (NULL);
	rlst = newlst;
	l = l->next;
	while (l)
	{
		if (!(newlst->next = ft_lstnew((*f)(l->content))))
		{
			ft_lstclear(&rlst, d);
			return (NULL);
		}
		newlst = newlst->next;
		l = l->next;
	}
	newlst->next = NULL;
	return (rlst);
}
