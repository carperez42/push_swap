/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:25:03 by carperez          #+#    #+#             */
/*   Updated: 2023/03/05 15:21:07 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *pStart)
{
	if (pStart != NULL)
	{
		if ((pStart->next) != NULL)
			return (ft_lstsize(pStart->next) + 1);
		return (1);
	}
	return (0);
}
// check next pointer in current node if different to NULL increment by one and
// move to next node till next pointer is NULL,
// then Return the increment acumulation.