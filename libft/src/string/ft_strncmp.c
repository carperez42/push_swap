/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:53:46 by carperez          #+#    #+#             */
/*   Updated: 2023/03/04 19:44:55 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t nCmp)
{
	size_t	ia;

	ia = 0;
	if (nCmp > 0)
	{
		while (ia < nCmp && ia <= ft_strlen(s1) && ia <= ft_strlen(s2))
		{
			if ((*(s1 + ia) != *(s2 + ia)) || *(s1 + ia) == '\0'
				|| *(s2 + ia) == '\0')
				return (*((unsigned char *)s1 + ia)
					- *((unsigned char *)s2 + ia));
			ia ++;
		}
	}
	else if ((int)nCmp < 0)
	{
		while (ia <= ft_strlen(s1) && ia <= ft_strlen(s2))
		{
			if (*(s1 + ia) != *(s2 + ia))
				return (*((unsigned char *)s1 + ia)
					- *((unsigned char *)s2 + ia));
			ia ++;
		}
	}
	return (0);
}
