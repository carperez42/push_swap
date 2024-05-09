/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_01_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:23:49 by carperez          #+#    #+#             */
/*   Updated: 2023/05/13 11:23:49 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// "ft_set_starter" initializes the properties of the placeholders inside of
// a set struct.
void	ft_set_starter(t_set *pSet)
{
	pSet->f_zero[0] = 0;
	pSet->f_zero[1] = 0;
	pSet->f_sign[0] = 0;
	pSet->f_sign[1] = 0;
	pSet->f_left[0] = 0;
	pSet->f_left[1] = 0;
	pSet->f_prefix[0] = 0;
	pSet->f_prefix[1] = 0;
	pSet->f_space[0] = 0;
	pSet->f_space[1] = 0;
	pSet->f_dot[0] = 0;
	pSet->f_dot[1] = 0;
	pSet->l_gap_1[0] = 0;
	pSet->l_gap_1[1] = 0;
	pSet->l_gap_2[0] = 0;
	pSet->l_gap_2[1] = 0;
	pSet->f_error = 0;
	pSet->l_arg = 0;
	pSet->c_type = '\0';
}

// "ft_set_type" checks if the placeholder has one of the allowed format
// type (cspdiuxX%). And also, this format is kept into set struct.
int	ft_set_type(char const cCmp, t_set *pSet)
{
	if (cCmp == 'c' || cCmp == 's' || cCmp == 'p' || cCmp == 'd' || cCmp == 'i'
		|| cCmp == 'u' || cCmp == 'x' || cCmp == 'X' || cCmp == '%')
	{
		pSet->c_type = cCmp;
		return (0);
	}
	return (1);
}

// "ft_set_capturer_1" checks if the placeholder has '0', '+' or '-'and
// initializes its flags and possitions.
void	ft_set_capturer_1(char const *sToken, t_set *pSet)
{
	int	ia;

	ia = 1;
	while (*(sToken + ia) != '\0')
	{
		if (sToken[ia] == '.')
		{
			pSet->f_dot[0] = ia;
			pSet->f_dot[1] += 1;
		}
		if (sToken[ia] == '+')
		{
			pSet->f_sign[0] = ia;
			pSet->f_sign[1] += 1;
		}
		if (sToken[ia] == '-')
		{
			pSet->f_left[0] = ia;
			pSet->f_left[1] += 1;
		}
		ia ++;
	}
	if (pSet->f_dot[1] > 1)
		pSet->f_error = 2;
}

// "ft_set_capturer_2" checks if the placeholder has '#', ' ' or '.'and
// initializes its flags and possitions.
void	ft_set_capturer_2(char const *sToken, t_set *pSet)
{
	int	ia;

	ia = 1;
	while (*(sToken + ia) != '\0')
	{
		if (sToken[ia] == '#')
		{
			pSet->f_prefix[0] = ia;
			pSet->f_prefix[1] += 1;
		}
		if (sToken[ia] == ' ')
		{
			pSet->f_space[0] = ia;
			pSet->f_space[1] += 1;
		}
		if (sToken[ia] == '0' && !ft_isdigit(sToken[ia - 1])
			&& sToken[ia - 1] != '.')
		{
			pSet->f_zero[0] = ia;
			pSet->f_zero[1] += 1;
		}
		ia ++;
	}
	if (pSet->f_zero[1] > 1 || pSet->f_prefix[1] > 1)
		pSet->f_error = 3;
}

// "ft_set_gapfiller" obtains the minimum width and precision from
// the placeholder.
void	ft_set_gapfiller(char const *sToken, t_set *pSet)
{
	int		ia;

	ia = 0;
	while ((!ft_isdigit(*(sToken + ia)) || (ft_isdigit(*(sToken + ia))
				&& *(sToken + ia) == '0')) && *(sToken + ia) != '\0'
		&& *(sToken + ia) != '.')
		ia ++;
	if (ft_isdigit(*(sToken + ia)))
	{
		pSet->l_gap_1[0] = ia;
		pSet->l_gap_1[1] = ft_atoi(sToken + ia);
	}
	if (pSet->f_dot[1] == 1)
	{
		ia = pSet->f_dot[0] + 1;
		while (!ft_isdigit(*(sToken + ia)) && *(sToken + ia) != '0'
			&& *(sToken + ia) != '\0')
			ia ++;
		if (ft_isdigit(*(sToken + ia)))
		{
			pSet->l_gap_2[0] = ia;
			pSet->l_gap_2[1] = ft_atoi(sToken + ia);
		}
	}
}

// END
