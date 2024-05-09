/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:43:23 by carperez          #+#    #+#             */
/*   Updated: 2023/02/26 14:13:27 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *sDest, const void *sOri, size_t nChg)
{
	size_t	ia;

	ia = 0;
	if (sDest != NULL || sOri != NULL)
	{
		while (ia < nChg)
		{
			*((char *)sDest + ia) = *((char *)sOri + ia);
			ia ++;
		}
	}
	return (sDest);
}
// Reads one byte at a time and writes that byte before reading the next.

// The memcpy copy function shows undefined behavior if the memory regions
// pointed to by the source and destination pointers overlap.

// Is useful in forwarding copy.

// Not check the terminating null character, so carefully using with strings.

// Behavior can be undefined if you try to access the destination and
// source buffer beyond their length.

// Not check the validity of the destination buffer.

/*int main( void )
{
    char str1[9] = "aabbccdd";
    printf("The string: %s\n", str1);
    ft_memcpy(str1 + 2, str1, 6);
    printf("New string ft_memcpy: %s\n", str1);
}*/

// Result: "aaaaaaaa" OVERLAP!!!.
