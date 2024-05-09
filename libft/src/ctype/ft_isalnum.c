/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:17:52 by carperez          #+#    #+#             */
/*   Updated: 2023/02/04 18:20:59 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int nChar)
{
	if (ft_isalpha(nChar) == 1)
		return (1);
	else if (ft_isalpha(nChar) == 2)
		return (2);
	else
	{
		if (ft_isdigit(nChar) == 1)
			return (4);
		else
			return (0);
	}
}
