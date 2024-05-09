/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_newnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:07:29 by carperez          #+#    #+#             */
/*   Updated: 2024/04/25 20:56:22 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_newnode(void *content)
{
	t_node	*p_aux;

	p_aux = (t_node *)malloc(sizeof(t_node));
	if (p_aux)
	{
		p_aux -> content = content;
		p_aux -> p_prev = NULL;
		p_aux -> p_next = NULL;
	}
	return (p_aux);
}
//END