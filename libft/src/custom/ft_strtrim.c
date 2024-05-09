/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:03:03 by carperez          #+#    #+#             */
/*   Updated: 2023/02/04 18:10:06 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ruleout_front(char const *s1, char const *set)
{
	int		ia;
	int		ib;
	int		f_find;

	ia = 0;
	f_find = 0;
	while (!f_find && *(s1 + ia) != '\0')
	{
		ib = 0;
		f_find = 1;
		while (*(set + ib) != '\0')
		{
			if (*(set + ib) == *(s1 + ia))
				f_find = 0;
			ib ++;
		}
		if (!f_find)
			ia ++;
	}
	return (ia);
}

static int	ft_ruleout_back(char const *s1, char const *set)
{
	int		ia;
	int		ib;
	int		f_find;

	ia = ft_strlen(s1) - 1;
	f_find = 0;
	while (!f_find && ia > 0)
	{
		ib = 0;
		f_find = 1;
		while (*(set + ib) != '\0')
		{
			if (*(set + ib) == *(s1 + ia))
				f_find = 0;
			ib ++;
		}
		if (!f_find)
			ia --;
	}
	return (ia);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i_front;
	int	i_back;

	i_front = ft_ruleout_front(s1, set);
	i_back = ft_ruleout_back(s1, set);
	if (i_front < i_back)
		return (ft_substr(s1, i_front, (i_back - i_front) + 1));
	else if (i_front == i_back)
		return (ft_substr(s1, i_front, 1));
	else
		return (ft_strdup(""));
}
//Remove from the begining and The end chars included in set
//until the firt char not included.

//Be aware if s1 or set are empty, return and emtpy string
//which has to be free by the user too.

//ft_strlen.c ft_substr.c ft_strlcpy.c ft_strdup.c ft_memcpy.c
//are embedded functions.
