/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:43:23 by carperez          #+#    #+#             */
/*   Updated: 2023/02/26 14:18:48 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *sDest, const void *sOri, size_t nChg)
{
	size_t	ia;

	ia = 0;
	if (sDest != NULL || sOri != NULL)
	{
		if (sOri < sDest && sDest < sOri + nChg)
		{
			while (nChg --)
				*((char *)sDest + nChg) = *((char *)sOri + nChg);
		}
		else
		{
			while (ia < nChg)
			{
				*((char *)sDest + ia) = *((char *)sOri + ia);
				ia ++;
			}
		}
	}
	return (sDest);
}
// Before copying the characters from source to destination object first copied
// the n character from source to the temporary array, after that copy
// n character from the temporary array to the destination object.
// It prevents from the undefined behavior when the source and destination
// object overlaps.

// Is useful in case of overlapping scenarios.

// Not check the terminating null character, so carefully using with strings.

// Behavior can be undefined if you try to access the destination and
// source buffer beyond their length.

// Not check the validity of the destination buffer.

/*int main( void )
{
    char str1[9] = "aabbccdd";
    printf("The string: %s\n", str1);
    ft_memmove(str1 + 2, str1, 6);
    printf("New string ft_memmove: %s\n", str1);
}*/

// Result: "aaaabbcc" OVERLAP!!!.