/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_07_hex_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:49:05 by carperez          #+#    #+#             */
/*   Updated: 2023/05/13 12:49:05 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// "ft_hexa_prefix" adds 0x or 0X prefix when it is activated by the placeholder
// in hexadecimal format type.
char	*ft_hexa_prefix(char *sDest, t_set sSet)
{
	sDest[0] = '0';
	sDest[1] = ft_toupper_char('x', sSet.c_type);
	return (sDest);
}

// "ft_toupper_char" converts lowercase characters in a character string
// if the format type is 'X'
char	ft_toupper_char(char chng, char cFlag)
{
	if (cFlag == 'X')
		return (ft_toupper(chng));
	else
		return (chng);
}

// "ft_hexa_size" retunrs the number of effective Hexadecimal simbols.
static int	ft_hexa_sizer(int nOri)
{
	char	s_hex[8];
	int		ia;

	if (nOri == 0)
		return (1);
	ia = 0;
	while (ia < 8)
	{
		s_hex[7 - ia] = "0123456789abcdef"[nOri & 0xF];
		nOri >>= 4;
		ia ++;
	}
	ia = 0;
	while (s_hex[ia] == '0')
		ia ++;
	return (8 - ia);
}

// "ft_hexa_converter" returns the number of effective hexadecimal symbols in
// the converted string representation of the input number.
static void	ft_hexa_converter(char *sDest, int nOri, t_set sSet)
{
	char	s_hex[9];
	int		ia;

	ia = 0;
	if (nOri != 0)
	{
		while (ia < 8)
		{
			s_hex[7 - ia] = "0123456789abcdef"[nOri & 0xF];
			nOri >>= 4;
			ia ++;
		}
		s_hex[8] = '\0';
		ia = 0;
		while (s_hex[ia] == '0')
			ia ++;
		while (ia <= 8)
		{
			*sDest = ft_toupper_char(s_hex[ia], sSet.c_type);
			sDest ++;
			ia ++;
		}
	}
	else
		*sDest = '0';
}

// "ft_itoa_hex" reserves memory to create a string from an integer value
// in hexadecimal.
char	*ft_itoa_hex(t_set *pSet, int nOri)
{
	char	*p_new;

	p_new = NULL;
	pSet->l_arg = ft_hexa_sizer(nOri);
	p_new = (char *)malloc((pSet->l_arg + 1) * sizeof(char));
	if (p_new != NULL)
		ft_hexa_converter(p_new, nOri, *pSet);
	return (p_new);
}

// END