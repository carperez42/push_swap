/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c   		     	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:25:03 by carperez          #+#    #+#             */
/*   Updated: 2023/03/05 15:21:07 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *pNodo, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p_lstnew;
	t_list	*p_lstnext;

	p_lstnew = NULL;
	while (pNodo != NULL)
	{
		p_lstnext = (t_list *)malloc(sizeof(t_list));
		if (p_lstnext == NULL)
		{
			ft_lstclear(&p_lstnew, del);
			return (NULL);
		}
		p_lstnext->content = f(pNodo->content);
		p_lstnext->next = NULL;
		ft_lstadd_back(&p_lstnew, p_lstnext);
		pNodo = pNodo->next;
	}
	return (p_lstnew);
}
// This function returns the pointer 'p_lstnew', which is a second list with
// the contents of the nodes from the original list pointed by 'pNodo' modified
// by the function 'f'. If an error occurs during the process p_lstnext node
// creation, 'p_lstnew' list will be completely deleted.