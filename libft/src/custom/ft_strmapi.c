/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:53:46 by carperez          #+#    #+#             */
/*   Updated: 2023/04/05 17:17:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *sOri, char (*f)(unsigned int, char))
{
	char	*p_new;
	int		l_str;

	p_new = NULL;
	if (sOri != NULL && f != NULL)
	{
		l_str = ft_strlen(sOri);
		p_new = (char *)ft_calloc(l_str + 1, sizeof(char));
		if (p_new != NULL)
		{
			while (l_str --)
				*(p_new + l_str) = f(l_str, *(sOri + l_str));
		}
	}
	return (p_new);
}
// The user has to free the array of substrings calculating the dimension
// until pointer NULL.

//ft_strlen.c ft_substr.c ft_calloc.c ft_bzero.c
//are embedded functions.