/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_08_unsptr_aux.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:44:57 by carperez          #+#    #+#             */
/*   Updated: 2023/05/13 12:44:57 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// "ft_digit_counter" returns the number of digits of the unsigned integer
// in the input argument. 
static int	ft_digit_counter(unsigned int nTarget, int nCount)
{
	if (nTarget <= 0 && nCount == 0)
		nCount ++;
	if (nTarget)
		return (ft_digit_counter(nTarget / 10, nCount + 1));
	return (nCount);
}

// "ft_itoa_uns" reserves memory to create a string from an unsigned integer.
char	*ft_itoa_uns(unsigned int nStr)
{
	char			*p_str;
	int				l_str;
	unsigned int	n_figure;

	n_figure = nStr;
	l_str = ft_digit_counter(nStr, 0);
	p_str = ft_calloc(l_str + 1, sizeof(char));
	if (p_str != NULL)
	{
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

// "ft_ptr_sizer" retunrs the number of effective Hexadecimal simbols for
// unsigned long long.
static int	ft_ptr_sizer(unsigned long long nOri)
{
	char	s_hex[16];
	int		ia;

	if (nOri == 0)
		return (1);
	ia = 0;
	while (ia < 16)
	{
		s_hex[15 - ia] = "0123456789abcdef"[nOri & 0xF];
		nOri >>= 4;
		ia ++;
	}
	ia = 0;
	while (s_hex[ia] == '0')
		ia ++;
	return (16 - ia);
}

// "ft_ptr_converter" returns the number of effective hexadecimal symbols in
// the converted string representation of the input unsigned long long number.
static void	ft_ptr_converter(char *sDest, unsigned long long nOri)
{
	char	s_hex[17];
	int		ia;

	ia = 0;
	if (nOri != 0)
	{
		while (ia < 16)
		{
			s_hex[15 - ia] = "0123456789abcdef"[nOri & 0xF];
			nOri >>= 4;
			ia ++;
		}
		s_hex[16] = '\0';
		ia = 0;
		while (s_hex[ia] == '0')
			ia ++;
		while (ia <= 16)
		{
			*sDest = s_hex[ia];
			sDest ++;
			ia ++;
		}
	}
	else
		*sDest = '0';
}

// "ft_itoa_ptr" reserves memory to create a string from an unsigned long long
// value into hexadecimal.
char	*ft_itoa_ptr(t_set *pSet, unsigned long long nOri)
{
	char	*p_new;

	p_new = NULL;
	if (nOri)
	{
		pSet->l_arg = ft_ptr_sizer(nOri);
		p_new = (char *)malloc((pSet->l_arg + 1) * sizeof(nOri));
		if (p_new != NULL)
			ft_ptr_converter(p_new, nOri);
	}
	else
	{
		pSet->l_arg = 1;
		p_new = "0";
	}
	return (p_new);
}

// END
