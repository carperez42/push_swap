/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:49:41 by carperez          #+#    #+#             */
/*   Updated: 2023/02/26 14:04:35 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t nCmp)
{
	size_t	ia;

	ia = 0;
	while (ia < nCmp)
	{
		if (*((unsigned char *)s1 + ia) != *((unsigned char *)s2 + ia))
			return (*((unsigned char *)s1 + ia) - *((unsigned char *)s2 + ia));
		ia ++;
	}
	return (0);
}
