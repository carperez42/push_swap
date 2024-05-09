/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:49:41 by carperez          #+#    #+#             */
/*   Updated: 2023/03/04 17:25:41 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *sOri, int nChar, size_t nCmp)
{
	char	*p_srch;
	char	*p_result;

	p_result = NULL;
	p_srch = (char *)sOri;
	while (nCmp-- && p_result == NULL)
	{
		if (*p_srch != (char)nChar)
			p_srch ++;
		else if (*p_srch == (char)nChar)
			p_result = p_srch;
	}
	return (p_result);
}
// Finds the first occurrence of 'nChar' (converted to an unsigned char) 
// in the initial 'nCmp' characters (each interpreted as unsigned char) of 
// the object pointed to by 'sOri'.

// Behavior is undefined if try to access beyond the end of the array searched.
// Behavior is undefined if 'sOri' is a null pointer.

// If the character does not occur in the object, then returns a null pointer.

// If 'sOri' is smaller than 'nCmp', but the match is found within, 
// the behavior is well-defined.

// ft_memchr vs ft_strchr:
//1.) ft_memchr takes three parameters.
//2.) pass the max length of bytes which to scan in ft_memchr.
//3.) ft_memchr does not expect null character for the first parameter.
//4.) ft_memchr does not stop when it hits a null character.