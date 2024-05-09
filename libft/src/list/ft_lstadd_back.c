/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c  		                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:25:03 by carperez          #+#    #+#             */
/*   Updated: 2023/03/05 15:21:07 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **pStart, t_list *pNew)
{
	t_list	*p_lstlast;

	p_lstlast = *pStart;
	if (*pStart != NULL)
	{
		p_lstlast = ft_lstlast(p_lstlast);
		p_lstlast->next = pNew;
	}
	if (*pStart == NULL)
		*pStart = pNew;
}
// 'pStart' is the reference where is the first node address (if it exist).
// Then goes to the last node using 'p_lstlast' pointer through the list.