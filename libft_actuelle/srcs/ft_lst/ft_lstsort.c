/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:11:07 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/12 10:01:58 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static t_list	*deep(t_list *lst, int depth)
{
	while (depth > 0)
	{
		lst = lst->next;
		depth--;
	}
	return (lst);
}

static t_list	*memberswap(t_list *first, t_list *lst, int depth)
{
	t_list		*tail;
	t_list		*head;

	if (!depth)
	{
		tail = first->next->next;
		head = first;
		first = first->next;
		first->next = head;
		first->next->next = tail;
	}
	else
	{
		tail = lst->next->next;
		head = lst;
		lst = lst->next;
		lst->next = head;
		lst->next->next = tail;
		deep(first, depth - 1)->next = lst;
	}
	return (first);
}

t_list	*ft_lstsort(t_list *lst, int (*cmp)(void*, void*))
{
	int		done;
	int		depth;
	t_list	*first;

	if (!cmp || !lst)
		return (0);
	first = lst;
	done = 0;
	while (!done)
	{
		lst = first;
		done = 1;
		depth = 0;
		while (lst->next)
		{
			if (!(cmp(lst->content, lst->next->content)))
			{
				first = memberswap(first, lst, depth);
				done = 0;
			}
			depth++;
			lst = deep(first, depth);
		}
	}
	return (first);
}
