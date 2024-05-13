/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   001-stack_initialitation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:12:44 by carperez          #+#    #+#             */
/*   Updated: 2024/05/13 20:17:37 by carperez         ###   ########.fr       */
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
void	ft_init_pushswap(t_pushswap *dPushswap, int nInputs, char **vInputs)
{
	t_catalog	*p_aux;

	p_aux = &(dPushswap->l_stack_a);
	dPushswap->f_error = 0;
	dPushswap->n_inputs = nInputs;
	dPushswap->a_inputs = vInputs;
	ft_init_catalog(&p_aux);
}
