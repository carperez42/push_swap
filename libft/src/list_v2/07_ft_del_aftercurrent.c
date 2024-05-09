/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_ft_del_aftercurrent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:40:31 by carperez          #+#    #+#             */
/*   Updated: 2024/04/25 21:47:48 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del_aftercurrent(t_catalog **pHeader, void (*del)(void*))
{
	t_node	*p_aux;

	if ((*pHeader)->p_current && (*pHeader)->p_current->p_next)
	{
		p_aux = (*pHeader)->p_current->p_next;
		if (del && p_aux->content)
			del(p_aux->content);
		(*pHeader)->p_current->p_next = p_aux->p_next;
		if (p_aux->p_next)
			p_aux->p_next->p_prev = (*pHeader)->p_current;
		else
			(*pHeader)->p_last = (*pHeader)->p_current;
		free(p_aux);
		(*pHeader)->n_nodes -= 1;
	}
}
//END