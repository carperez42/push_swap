/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_ft_add_aftercurrent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:59:11 by carperez          #+#    #+#             */
/*   Updated: 2024/04/25 21:53:05 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_aftercurrent(t_catalog **pHeader, t_node *pNode)
{
	pNode->p_next = (*pHeader)->p_current->p_next;
	pNode->p_prev = (*pHeader)->p_current;
	(*pHeader)->p_current->p_next = pNode;
	if ((*pHeader)->p_last == (*pHeader)->p_current)
		(*pHeader)->p_last = pNode;
	(*pHeader)->n_nodes += 1;
}
//END