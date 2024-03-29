/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdzamari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:10:10 by sdzamari          #+#    #+#             */
/*   Updated: 2021/09/21 11:24:15 by sdzamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Iterates the list ’lst’ and applies the function
 ’f’ to the content of each element.
Creates a new list resulting of the successive applications of the function ’f’.
The ’del’ function is used to delete the content of an element if needed. */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	new_lst = 0;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, temp);
		temp = temp->next;
		lst = lst->next;
	}
	return (new_lst);
}
