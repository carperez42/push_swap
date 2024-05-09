/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:53:46 by carperez          #+#    #+#             */
/*   Updated: 2023/04/02 22:53:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *sChg, void (*f)(unsigned int, char*))
{
	int	l_str;

	if (sChg != NULL && f != NULL)
	{
		l_str = ft_strlen(sChg);
		while (l_str --)
			f(l_str, (sChg + l_str));
	}
}
//ft_strlen.c is embedded function.