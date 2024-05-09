/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_ft_add_beforecurrent.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:03:24 by carperez          #+#    #+#             */
/*   Updated: 2024/04/25 21:53:18 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_beforecurrent(t_catalog **pHeader, t_node *pNode)
{
	pNode->p_next = (*pHeader)->p_current;
	pNode->p_prev = (*pHeader)->p_current->p_prev;
	(*pHeader)->p_current->p_prev = pNode;
	if ((*pHeader)->p_first == (*pHeader)->p_current)
		(*pHeader)->p_first = pNode;
	(*pHeader)->n_nodes += 1;
}
//END