/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:49:41 by carperez          #+#    #+#             */
/*   Updated: 2023/03/04 17:25:41 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *sCpy)
{
	char	*p_new;

	p_new = malloc (ft_strlen(sCpy) + 1);
	if (p_new != NULL)
		ft_memcpy(p_new, sCpy, ft_strlen(sCpy) + 1);
	return (p_new);
}
