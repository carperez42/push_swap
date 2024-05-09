/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_ft_delnode_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:14:10 by carperez          #+#    #+#             */
/*   Updated: 2024/04/25 21:47:36 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delnode_front(t_catalog **pHeader, void (*del)(void*))
{
	t_node	*p_aux;

	if ((*pHeader)->p_first)
	{
		if (del && (*pHeader)->p_first->content)
			del((*pHeader)->p_first->content);
		p_aux = (*pHeader)->p_first;
		(*pHeader)->p_first = (*pHeader)->p_first->p_next;
		if ((*pHeader)->p_first)
			(*pHeader)->p_first->p_prev = NULL;
		else
			(*pHeader)->p_last = NULL;
		free(p_aux);
		(*pHeader)->n_nodes -= 1;
	}
}
//END