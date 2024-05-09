/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_05_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:30:39 by carperez          #+#    #+#             */
/*   Updated: 2023/05/13 12:30:39 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// "ft_buffer_filler_1" ensures the right position of the obligatory hex prefix
// , and the + simbol or space, just in case.
static char	*ft_buffer_filler_1(char *sDest, t_set sSet, int nCmp, int nMode)
{
	char	*p_aux;

	p_aux = NULL;
	if ((sSet.f_sign[1] || sSet.f_space[1]) && nCmp)
	{
		if (sSet.f_sign[1])
			sDest[0] = '+';
		if (sSet.f_space[1] && !sSet.f_sign[1])
			sDest[0] = ' ';
		sDest[2] = 'x';
	}
	else
		sDest[1] = 'x';
	if (nMode)
	{
		p_aux = ft_strrchr(sDest, '+');
		if (p_aux)
			sDest[(unsigned int)(p_aux - sDest)] = '0';
		p_aux = ft_strrchr(sDest, ' ');
		if (p_aux)
			sDest[(unsigned int)(p_aux - sDest)] = '0';
	}
	return (sDest);
}

// "ft_buffer_filler_2" initializes a string of a length equal to the configured
// width or equal to the length of the source string, and it tabs it according
// to whether the '-' flag is activated or not.
static char	*ft_buffer_filler_2(char *sDest, char const *sOri, t_set sSet
			, int nCmp)
{
	char	*p_aux;

	p_aux = NULL;
	if (sSet.f_left[1] || sSet.l_arg == (int)ft_strlen(sOri))
		ft_memcpy(sDest, sOri, ft_strlen(sOri));
	else if ((!sSet.f_left[1] && (!sSet.f_zero[1] || (sSet.f_zero[1]
					&& sSet.f_dot[1]))) || !nCmp)
		ft_memcpy(sDest + (sSet.l_arg - ft_strlen(sOri)), sOri,
			ft_strlen(sOri));
	else if (!sSet.f_left[1] && sSet.f_zero[1] && !sSet.f_dot[1] && nCmp)
	{
		ft_memcpy(sDest + (sSet.l_arg - ft_strlen(sOri)), sOri,
			ft_strlen(sOri));
		p_aux = ft_strrchr(sDest, 'x');
		sDest[(unsigned int)(p_aux - sDest)] = '0';
		ft_buffer_filler_1(sDest, sSet, nCmp, 1);
	}
	return (sDest);
}

// "ft_ptr_processor" performs the first processing of the input string argument
// and stores the result in the first temporary memory allocation.
static char	*ft_ptr_processor(char const *sOri, t_set *pSet, int nCmp)
{
	char	*p_new;

	p_new = NULL;
	if (pSet->l_arg < pSet->l_gap_2[1] && nCmp)
		pSet->l_arg = pSet->l_gap_2[1];
	pSet->l_arg += 2;
	if ((pSet->f_sign[1] || pSet->f_space[1]) && nCmp)
		pSet->l_arg += 1;
	p_new = ft_buffer_creator(pSet->l_arg, '0');
	if (p_new != NULL)
	{
		ft_memcpy((p_new + pSet->l_arg - ft_strlen(sOri)), sOri,
			ft_strlen(sOri));
		ft_buffer_filler_1(p_new, *pSet, nCmp, 0);
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
		p_new = ft_ptr_processor(sOri1, pSet, nCmp);
	else
	{
		pSet->l_arg = ft_strlen(sOri2);
		if (pSet->l_arg < pSet->l_gap_1[1])
			pSet->l_arg = pSet->l_gap_1[1];
		if (pSet->f_zero[1] && !pSet->f_dot[1] && nCmp && !pSet->f_left[1])
			p_new = ft_buffer_creator(pSet->l_arg, '0');
		else
			p_new = ft_buffer_creator(pSet->l_arg, ' ');
		if (p_new != NULL)
			ft_buffer_filler_2(p_new, sOri2, *pSet, nCmp);
	}
	return (p_new);
}

// "ft_print_ptr" is the primary function used to process format specifier
// placeholders that correspond to unsigned long long argument.
char	*ft_print_ptr(t_set *pSet, int *nPrinted)
{
	char			*p_buffer;
	char			*p_arg;
	char			*p_aux;
	unsigned long	arg_int;

	p_aux = NULL;
	p_buffer = NULL;
	arg_int = va_arg(pSet->lst_items, unsigned long long);
	p_arg = ft_itoa_ptr(pSet, arg_int);
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
		if (arg_int)
			free(p_arg);
	}
	return (p_buffer);
}

// END