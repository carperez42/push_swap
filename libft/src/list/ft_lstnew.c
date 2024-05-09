/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c   		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:25:03 by carperez          #+#    #+#             */
/*   Updated: 2023/03/05 15:21:07 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p_lstnew;

	p_lstnew = (t_list *)malloc(sizeof(t_list));
	if (p_lstnew != NULL)
	{
		p_lstnew -> content = content;
		p_lstnew -> next = NULL;
	}
	return (p_lstnew);
}
// 1) creation new pointer t_list type.
// 2) initialitation memory reservation for the node of new pointer.
// 3) initialitation content in the node of new pointer.
// 3) initialitation to NULL of next pointer in the node of new pointer.