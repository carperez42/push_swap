/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c 		                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:25:03 by carperez          #+#    #+#             */
/*   Updated: 2023/03/05 15:21:07 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **pStart, t_list *pNew)
{
	if (*pStart != NULL)
		pNew->next = *pStart;
	*pStart = pNew;
}
// 'pStart' is a pointer type t_list, always has to point to the first node.
// 'pNew' is a pointer type t_list, points to some node.
// 1) initialitation of next pointer in the node of 'pNew' with
// content of 'lst'.
// 2) initialitation of 'pStart' pointer with content of 'pNew'.