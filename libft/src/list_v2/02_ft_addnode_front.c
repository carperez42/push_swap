/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_ft_addnode_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:23:07 by carperez          #+#    #+#             */
/*   Updated: 2024/04/28 17:54:17 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addnode_front(t_catalog **pHeader, t_node *pNode)
{
	pNode->p_next = (*pHeader)->p_first;
	if ((*pHeader)->p_first != NULL)
		(*pHeader)->p_first->p_prev = pNode;
	(*pHeader)->p_first = pNode;
	if ((*pHeader)->p_last == NULL)
		(*pHeader)->p_last = pNode;
	(*pHeader)->p_first = pNode;
	(*pHeader)->p_first->p_prev = NULL;
	(*pHeader)->n_nodes += 1;
}
//END