/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:49:41 by carperez          #+#    #+#             */
/*   Updated: 2023/02/26 14:20:38 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *sOri, int nChar, size_t nChg)
{
	size_t	ia;

	ia = 0;
	while (ia != nChg)
	{
		*((char *)sOri + ia) = (char)nChar;
		ia ++;
	}
	return (sOri);
}
