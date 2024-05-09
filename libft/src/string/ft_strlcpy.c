/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:49:41 by carperez          #+#    #+#             */
/*   Updated: 2023/02/26 14:31:21 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *sDest, const char *sOri, size_t nCpy)
{
	size_t	ia;
	size_t	l_aux;

	ia = 0;
	l_aux = ft_strlen(sOri);
	if (nCpy == 0)
		return (l_aux);
	while (*(sOri + ia) != '\0' && ia < (nCpy - 1))
	{
		*(sDest + ia) = *(sOri + ia);
		ia ++;
	}
	*(sDest + ia) = '\0';
	if (l_aux > (nCpy - 1))
		return (l_aux);
	return (ia);
}
