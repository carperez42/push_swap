/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:49:41 by carperez          #+#    #+#             */
/*   Updated: 2023/02/26 14:04:35 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_counter(int nTarget, int nCount)
{
	if (nTarget <= 0 && nCount == 0)
		nCount ++;
	if (nTarget)
		return (digit_counter(nTarget / 10, nCount + 1));
	return (nCount);
}

char	*ft_itoa(int nStr)
{
	char		*p_str;
	int			l_str;
	long int	n_figure;

	n_figure = nStr;
	l_str = digit_counter(nStr, 0);
	p_str = ft_calloc(l_str + 1, sizeof(char));
	if (p_str != NULL)
	{
		if (nStr < 0)
		{
			n_figure *= (-1);
			*p_str = '-';
		}
		if (!n_figure)
			*p_str = '0';
		l_str --;
		while (n_figure)
		{
			*(p_str + l_str) = ((n_figure % 10) + 48);
			n_figure /= 10;
			l_str --;
		}
	}
	return (p_str);
}
// Allow long int: -2147483648
// When 0 at the begining returns wrong string

// The user has to free the array of substrings calculating the dimension
// until pointer NULL.

//ft_calloc.c ft_bzero.c are embedded functions.