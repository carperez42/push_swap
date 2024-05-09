/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   000-main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:47:03 by carperez          #+#    #+#             */
/*   Updated: 2024/05/09 16:36:25 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//"ft_node_creator": Function that allocates memory and initializes
//	 the content of the node.
void	*ft_node_creator(int nInt)
{
	t_node	*p_node;

	p_node = ft_newnode(NULL);
	if (p_node)
	{
		p_node->content = (void *)malloc(sizeof(t_element));
		if (p_node->content)
		{
			((t_element *)(p_node->content))->n_valnum = nInt;
			((t_element *)(p_node->content))->n_index = 0;
			((t_element *)(p_node->content))->n_opcost = 0;
			((t_element *)(p_node->content))->f_upper = false;
			((t_element *)(p_node->content))->f_cheapest = false;
			((t_element *)(p_node->content))->p_target = NULL;
		}
	}
	return (p_node);
}

//"ft_init_pushswap": Function to initialize the master structure pushswap.
static void	ft_init_pushswap(t_pushswap *dPushswap, int nInputs, char **vInputs)
{
	t_catalog	*p_aux;

	p_aux = &(dPushswap->l_stack_a);
	dPushswap->f_error = 0;
	dPushswap->n_inputs = nInputs;
	dPushswap->a_inputs = vInputs;
	dPushswap->n_ops = 0;
	ft_init_catalog(&p_aux);
}

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
		{
			ft_printf("\033[1;5;31m");
			ft_putstr_fd("Error\n", 2);
			ft_printf("\033[1;0m");
		}
		p_aux = &(d_pushswap.l_stack_a);
		ft_clear_catalog(&(p_aux), &free);
		free(d_pushswap.p_diglist);
	}
	else
		return (-1);
	return (0);
}
//END