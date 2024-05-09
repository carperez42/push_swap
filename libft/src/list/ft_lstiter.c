/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c    	    	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:25:03 by carperez          #+#    #+#             */
/*   Updated: 2023/03/05 15:21:07 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *pStart, void (*f)(void *))
{
	if (pStart != NULL && f != NULL)
	{
		f(pStart->content);
		while (pStart->next != NULL)
		{
			pStart = pStart->next;
			f(pStart->content);
		}
	}
}
// Apply the function 'f' to the contents of each node in the list.