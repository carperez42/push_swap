/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:53:46 by carperez          #+#    #+#             */
/*   Updated: 2023/03/05 19:42:08 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *sOri, int nChar)
{
	int	ia;

	ia = 0;
	while (*(sOri + ia) != '\0' && *(sOri + ia) != (char) nChar)
		ia ++;
	if (*(sOri + ia) == (char) nChar)
		return ((char *) sOri + ia);
	else
		return (NULL);
}
// Finds the first occurrence of 'nChar' (converted to a char) in the string
// pointed to by 'sOri'. The terminating null character is also considered
// to be part of the string and it can be found if searching for ‘\0’.

//sOri = NULL--> undefined behaveour

// ft_memchr vs ft_strchr:
//1.) ft_strchr takes two parameters.
//2.) pass the max length of bytes which to scan in ft_memchr.
//3.) ft_strchr expects null character and it works only on the string.
//4.) ft_strchr stops when it hits a null character.