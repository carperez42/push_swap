/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:49:41 by carperez          #+#    #+#             */
/*   Updated: 2023/03/04 17:25:41 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *sDest, const char *sOri, size_t nCpy)
{
	size_t	ia;
	size_t	l_dest;
	size_t	l_ori;

	ia = 0;
	l_dest = ft_strlen(sDest);
	l_ori = ft_strlen(sOri);
	if (nCpy > l_dest)
	{
		while (*(sOri + ia) != '\0' && ia < (nCpy - l_dest - 1))
		{
			*(sDest + l_dest + ia) = *(sOri + ia);
			ia ++;
		}
		*(sDest + l_dest + ia) = '\0';
		return (l_dest + l_ori);
	}
	return (nCpy + l_ori);
}
