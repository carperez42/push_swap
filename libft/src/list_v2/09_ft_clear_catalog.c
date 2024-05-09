/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_ft_clear_catalog.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:37:03 by carperez          #+#    #+#             */
/*   Updated: 2024/04/25 09:12:22 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_catalog(t_catalog **pHeader, void (*del)(void*))
{
	while ((*pHeader)->p_first != NULL)
		ft_delnode_front(pHeader, del);
}
//END