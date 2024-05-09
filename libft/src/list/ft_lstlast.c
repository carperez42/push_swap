/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c      		                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:25:03 by carperez          #+#    #+#             */
/*   Updated: 2023/03/05 15:21:07 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *pStart)
{
	if (pStart != NULL)
	{
		while (pStart->next != NULL)
			pStart = pStart->next;
	}
	return (pStart);
}
// move the 'pStart' pointer till find a next pointer node NULL
// and return this addres node.