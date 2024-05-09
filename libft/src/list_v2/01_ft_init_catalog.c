/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ft_init_catalog.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:07:44 by carperez          #+#    #+#             */
/*   Updated: 2024/04/25 21:55:14 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_catalog(t_catalog **pHeader)
{
	(*pHeader)->n_nodes = 0;
	(*pHeader)->p_first = NULL;
	(*pHeader)->p_last = NULL;
	(*pHeader)->p_current = NULL;
}
//END