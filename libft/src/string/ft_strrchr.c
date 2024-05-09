/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:53:46 by carperez          #+#    #+#             */
/*   Updated: 2023/03/04 19:44:55 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *sOri, int nChar)
{
	int			ia;

	ia = ft_strlen(sOri);
	if (sOri != NULL || *sOri == '\0')
	{
		while (*(sOri + ia) != (char) nChar && (sOri + ia) > sOri)
			ia --;
		if (*(sOri + ia) == (char) nChar)
			return ((char *) sOri + ia);
		else
			return (NULL);
	}
	else
		return (NULL);
}
