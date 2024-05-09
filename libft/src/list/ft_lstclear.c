/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c   	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:25:03 by carperez          #+#    #+#             */
/*   Updated: 2023/03/05 15:21:07 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **pNodo, void (*del)(void*))
{
	t_list	*p_lstnext;

	if (pNodo != NULL)
	{
		while (ft_lstsize(*pNodo))
		{
			p_lstnext = (*pNodo)->next;
			ft_lstdelone(*pNodo, del);
			*pNodo = p_lstnext;
		}
	}
}
// 'pNodo' is the reference where is the address of the current starting node.
// it will jump to the next node address once its node is free. Teherefore,
// 'p_lstnext' is the pointer which keeps the next node address. This function
// ends when the size of the list is 0.