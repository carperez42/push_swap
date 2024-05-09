/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_09_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:39:00 by carperez          #+#    #+#             */
/*   Updated: 2023/05/18 15:39:00 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// "ft_buffer_creator" allocates memory dynamically to create a buffer capable
// of holding a string initialized with a specified character.
char	*ft_buffer_creator(size_t nDimension, char cFiller)
{
	char	*p_new;
	int		ia;

	ia = 0;
	p_new = (char *)malloc((nDimension + 1) * sizeof(char));
	if (p_new != NULL)
	{
		while (ia < (int)nDimension)
		{
			p_new[ia] = cFiller;
			ia ++;
		}
		p_new[ia] = '\0';
	}
	return (p_new);
}

// "ft_seterr_checker_1" Verify that the configuration is compatible with
// the following types of formats: s, c
static int	ft_seterr_checker(t_set sSet)
{
	if (sSet.c_type == 's')
	{
		if (sSet.f_prefix[1] || (sSet.f_zero[1]
				&& (sSet.f_zero[0] < sSet.f_dot[0])) || sSet.f_sign[1])
			return (5);
	}
	if (sSet.c_type == 'c')
	{
		if (sSet.f_prefix[1] || sSet.f_space[1]
			|| sSet.f_zero[1] || sSet.f_sign[1])
			return (6);
	}
	return (0);
}

// "ft_seterr_location" Verify if the configuration order is being
//	followed correctly.
static int	ft_seterr_location(t_set sSet)
{
	if (sSet.l_gap_1[1] == 1 && (sSet.l_gap_1[0] < sSet.f_sign[0]
			|| sSet.l_gap_1[0] < sSet.f_left[0] || sSet.l_gap_1[0]
			< sSet.f_prefix[0] || sSet.l_gap_1[0] < sSet.f_space[0]))
		return (11);
	if (sSet.l_gap_2[1] == 1 && (sSet.l_gap_2[0] < sSet.f_sign[0]
			|| sSet.l_gap_2[0] < sSet.f_left[0] || sSet.l_gap_2[0]
			< sSet.f_prefix[0] || sSet.l_gap_2[0] < sSet.f_space[0]
			|| sSet.l_gap_2[0] < sSet.f_zero[0]))
		return (12);
	return (0);
}

// "ft_set_validator" executes all necessary functions to capture
// the configuration that should be applied to the argument corresponding to
// the placeholder. Return 1 if any error is detected.
void	ft_set_validator(char const *sToken, t_set *pSet)
{
	ft_set_capturer_1(sToken, pSet);
	ft_set_capturer_2(sToken, pSet);
	ft_set_gapfiller(sToken, pSet);
	if (!pSet->f_error)
		pSet->f_error = ft_seterr_location(*pSet);
	if (!pSet->f_error)
		pSet->f_error = ft_seterr_checker(*pSet);
}

// END
// END
