/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_04_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:24:28 by carperez          #+#    #+#             */
/*   Updated: 2023/05/13 12:24:28 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// "ft_buffer_filler_1" initializes the resulting string based on the previous
// analysis of the precision and the dimensions of the corresponding argument.
// Also, it Perform a conversion of a character string to uppercase only
// if the corresponding data type is 'X'.
static char	*ft_buffer_filler_1(char *sDest, char const *sOri, t_set sSet
			, int nCmp)
{
	if (!sSet.f_prefix[1] || (sSet.f_prefix[1] && !nCmp))
	{
		if (nCmp)
		{
			if (sSet.l_arg > (int)ft_strlen(sOri))
				ft_memcpy((sDest + sSet.l_arg - ft_strlen(sOri)),
					sOri, ft_strlen(sOri));
			else
				ft_memcpy(sDest, sOri, ft_strlen(sOri));
		}
	}
	else
	{
		sDest[0] = '0';
		sDest[1] = ft_toupper_char('x', sSet.c_type);
		if (sSet.l_arg > (int)ft_strlen(sOri))
			ft_memcpy((sDest + sSet.l_arg - ft_strlen(sOri)),
				sOri, ft_strlen(sOri));
		else
			ft_memcpy(sDest + 2, sOri, ft_strlen(sOri));
	}
	return (sDest);
}

// "ft_buffer_filler_2" initializes a string of a length equal to the configured
// width or equal to the length of the source string, and it tabs it according
// to whether the '-' flag is activated or not.
static char	*ft_buffer_filler_2(char *sDest, char const *sOri, t_set sSet
			, int nCmp)
{
	if (sSet.f_left[1] || sSet.l_arg == (int)ft_strlen(sOri))
		ft_memcpy(sDest, sOri, ft_strlen(sOri));
	else if (!sSet.f_left[1] && (!sSet.f_zero[1] || (sSet.f_zero[1]
				&& sSet.f_dot[1])))
		ft_memcpy(sDest + (sSet.l_arg - ft_strlen(sOri)), sOri,
			ft_strlen(sOri));
	else if (!sSet.f_left[1] && sSet.f_zero[1] && !sSet.f_prefix[1])
	{
		ft_memset(sDest, '0', sSet.l_arg);
		ft_memcpy(sDest + (sSet.l_arg - ft_strlen(sOri)), sOri,
			ft_strlen(sOri));
	}
	else
	{
		if (nCmp != 0)
		{
			ft_memset(sDest, '0', sSet.l_arg);
			ft_hexa_prefix(sDest, sSet);
			ft_memcpy(sDest + (sSet.l_arg + 2 - ft_strlen(sOri)), (sOri + 2),
				(ft_strlen(sOri) - 2));
		}
		else
			ft_memset(sDest, '0', sSet.l_arg);
	}
	return (sDest);
}

// "ft_str_processor" performs the first processing of the input string argument
// and stores the result in the first temporary memory allocation.
static char	*ft_str_processor(char const *sOri, t_set *pSet, int nCmp)
{
	char	*p_new;

	p_new = NULL;
	if (pSet->l_arg <= pSet->l_gap_2[1])
		pSet->l_arg = pSet->l_gap_2[1];
	if (pSet->f_prefix[1] && nCmp != 0)
		pSet->l_arg += 2;
	if (!nCmp && !pSet->l_gap_2[1] && pSet->f_dot[1])
		p_new = ft_buffer_creator(0, '\0');
	else
	{
		p_new = ft_buffer_creator(pSet->l_arg, '0');
		if (p_new != NULL)
			ft_buffer_filler_1(p_new, sOri, *pSet, nCmp);
	}
	return (p_new);
}

// "ft_buffer_sizer" determines the amount of memory allocation needed to store
// the processed input string argument.
static char	*ft_buffer_sizer(char const *sOri1, char const *sOri2, t_set *pSet
			, int nCmp)
{
	char	*p_new;

	p_new = NULL;
	if (sOri1 != NULL)
		p_new = ft_str_processor(sOri1, pSet, nCmp);
	else
	{
		pSet->l_arg = ft_strlen(sOri2);
		if (pSet->l_arg < pSet->l_gap_1[1])
			pSet->l_arg = pSet->l_gap_1[1];
		p_new = ft_buffer_creator(pSet->l_arg, ' ');
		if (p_new != NULL)
			ft_buffer_filler_2(p_new, sOri2, *pSet, nCmp);
	}
	return (p_new);
}

// "ft_print_hex" is the primary function used to process format specifier
// placeholders that correspond to hexadecimal argument.
char	*ft_print_hex(t_set *pSet, int *nPrinted)
{
	char	*p_buffer;
	char	*p_arg;
	char	*p_aux;
	int		arg_int;

	p_aux = NULL;
	p_buffer = NULL;
	arg_int = va_arg(pSet->lst_items, int);
	p_arg = ft_itoa_hex(pSet, arg_int);
	if (p_arg != NULL)
	{
		p_aux = ft_buffer_sizer(p_arg, NULL, pSet, arg_int);
		if (p_aux != NULL)
		{
			p_buffer = ft_buffer_sizer(NULL, p_aux, pSet, arg_int);
			if (p_buffer != NULL)
				*nPrinted += pSet->l_arg;
			free(p_aux);
		}
		free(p_arg);
	}
	return (p_buffer);
}

// END