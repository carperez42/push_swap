/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:03:03 by carperez          #+#    #+#             */
/*   Updated: 2024/05/09 16:21:09 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *sNum)
{
	int	ia;
	int	n_result;
	int	v_sig;

	ia = 0;
	n_result = 0;
	v_sig = 1;
	while ((*(sNum + ia) >= 9 && *(sNum + ia) <= 13) || *(sNum + ia) == 32)
		ia ++;
	if (*(sNum + ia) == '-')
	{
		v_sig *= -1;
		ia ++;
	}
	else if (*(sNum + ia) == '+')
		ia ++;
	while (ft_isdigit(*(sNum + ia)))
	{
		n_result = n_result * 10 + *(sNum + ia) - 48;
		ia ++;
	}
	return (v_sig * n_result);
}

long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}
//END