/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:49:41 by carperez          #+#    #+#             */
/*   Updated: 2023/03/04 17:25:41 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *sFront, char const *sBack)
{
	char	*p_new;
	int		l_front;
	int		l_back;

	p_new = NULL;
	if ((sFront != NULL) && (sBack != NULL))
	{
		l_front = ft_strlen(sFront);
		l_back = ft_strlen(sBack);
		p_new = malloc (sizeof(char) * (l_front + l_back + 1));
		if (p_new != NULL)
		{
			if (l_front == 0)
				ft_memcpy(p_new, sBack, l_back + 1);
			else if (l_back == 0)
				ft_memcpy(p_new, sFront, l_front + 1);
			else
			{
				ft_memcpy(p_new, sFront, l_front);
				ft_memcpy(&p_new[l_front], sBack, l_back + 1);
			}
		}
	}
	return (p_new);
}
// The user has to free the substrings.

//ft_strlen.c ft_memcpy.c are embedded functions.