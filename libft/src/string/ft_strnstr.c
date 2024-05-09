/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:17:52 by carperez          #+#    #+#             */
/*   Updated: 2023/02/04 18:20:59 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *sMain, const char *sSub, size_t nCmp)
{
	int	ia;

	ia = 0;
	if (sSub != sMain && ft_strlen(sSub) != 0)
	{
		while (*((char *)sMain + ia) && nCmp)
		{
			if (ft_strncmp(((char *)sMain + ia), sSub, ft_strlen(sSub)) == 0
				&& nCmp >= ft_strlen(sSub))
				return ((char *)sMain + ia);
			ia ++;
			nCmp --;
		}
		return (NULL);
	}
	return ((char *)sMain);
}
