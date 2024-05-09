/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:03:03 by carperez          #+#    #+#             */
/*   Updated: 2023/02/04 18:10:06 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *sOri, unsigned int start, size_t len)
{
	char	*p_sub;

	p_sub = NULL;
	if (start > ft_strlen(sOri))
		len = 0;
	else if (len > ft_strlen(sOri + start))
		len = ft_strlen(sOri + start);
	p_sub = (char *)malloc (sizeof(char) * (len + 1));
	if (p_sub != NULL)
	{
		if (start < ft_strlen(sOri))
			ft_strlcpy(p_sub, sOri + start, len + 1);
		else
			*p_sub = '\0';
	}
	return (p_sub);
}
// Allocate memory to copy a substring, specifying the source string,
// the starting point, and the length of the substring to be copied