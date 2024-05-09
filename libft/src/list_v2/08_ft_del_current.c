/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_ft_del_current.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:02:25 by carperez          #+#    #+#             */
/*   Updated: 2024/04/25 21:48:04 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del_current(t_catalog **pHeader, void (*del)(void*))
{
	if ((*pHeader)->p_current)
	{
		if (del && (*pHeader)->p_current->content)
			del((*pHeader)->p_current->content);
		if ((*pHeader)->p_current->p_prev)
			(*pHeader)->p_current->p_prev->p_next
				= (*pHeader)->p_current->p_next;
		else
			(*pHeader)->p_first = (*pHeader)->p_current->p_next;
		if ((*pHeader)->p_current->p_next)
			(*pHeader)->p_current->p_next->p_prev
				= (*pHeader)->p_current->p_prev;
		else
			(*pHeader)->p_last = (*pHeader)->p_current->p_prev;
		free((*pHeader)->p_current);
		(*pHeader)->p_current = NULL;
		(*pHeader)->n_nodes -= 1;
	}
}
//END