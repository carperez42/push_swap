/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   000-main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:47:03 by carperez          #+#    #+#             */
/*   Updated: 2024/05/13 20:16:54 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//Main function from which the input arguments are captured and proceed to
// 	their analysis and sorting.
int	main(int nInputs, char **vInputs)
{
	t_pushswap	d_pushswap;
	t_catalog	*p_aux;

	p_aux = &(d_pushswap.l_stack_a);
	ft_init_pushswap(&d_pushswap, nInputs, vInputs);
	if (nInputs > 1)
	{
		ft_input_analizer(&d_pushswap);
		if (!(d_pushswap.f_error))
			ft_serie_analizer(&d_pushswap);
		else
			ft_putstr_fd("Error\n", 2);
		p_aux = &(d_pushswap.l_stack_a);
		ft_clear_catalog(&(p_aux), &free);
		free(d_pushswap.p_diglist);
	}
	else
		return (-1);
	return (0);
}
//END