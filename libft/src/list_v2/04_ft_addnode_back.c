/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_ft_addnode_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:45:52 by carperez          #+#    #+#             */
/*   Updated: 2024/04/25 21:46:38 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addnode_back(t_catalog **pHeader, t_node *pNode)
{
	if (!((*pHeader)->p_first))
		ft_addnode_front(pHeader, pNode);
	else
	{
		(*pHeader)->p_current = (*pHeader)->p_last;
		ft_add_aftercurrent(pHeader, pNode);
	}
}
//END