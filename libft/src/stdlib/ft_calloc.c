/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:49:41 by carperez          #+#    #+#             */
/*   Updated: 2023/03/18 18:53:50 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nDimension, size_t tData)
{
	void	*p_new;

	p_new = malloc (nDimension * tData);
	if (p_new != NULL)
		ft_bzero(p_new, nDimension * tData);
	return (p_new);
}
