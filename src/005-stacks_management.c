/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   005-stacks_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:51:04 by carperez          #+#    #+#             */
/*   Updated: 2024/05/13 18:36:43 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//"ft_set_cheapest": Function to determine the node whose movement from
//	 stack 'a' to 'b' involves the fewest operations.
static void	ft_set_cheapest(t_catalog *sStack)
{
	t_node	*p_aux;

	sStack->p_current = sStack->p_first;
	p_aux = sStack->p_current;
	((t_element *)(p_aux->content))->f_cheapest = true;
	if (sStack->p_current)
	{
		while (sStack->p_current->p_next)
		{
			if (((t_element *)(p_aux->content))->n_opcost > (((t_element *)
				(sStack->p_current->p_next->content))->n_opcost))
			{
				((t_element *)(p_aux->content))->f_cheapest = false;
				p_aux = sStack->p_current->p_next;
				((t_element *)(p_aux->content))->f_cheapest = true;
			}
			sStack->p_current = sStack->p_current->p_next;
		}
	}
}

//"ft_get_cheapest": Function to obtain the memory address of the node with
//	 the lowest cost in operations from stack 'a'.
static t_node	*ft_get_cheapest(t_catalog *sStack)
{
	sStack->p_current = sStack->p_first;
	if (sStack->p_current)
	{
		while (sStack->p_current)
		{
			if (((t_element *)(sStack->p_current->content))->f_cheapest)
				return (sStack->p_current);
			sStack->p_current = sStack->p_current->p_next;
		}
	}
	return (NULL);
}

//"ft_a2b_executions": Function to execute the operations required to move
//	 the cheapest node from stack 'a' to 'b'.
void	ft_a2b_executions(t_pushswap *dPushswap)
{
	t_node	*p_cheapest;

	p_cheapest = ft_get_cheapest(&(dPushswap->l_stack_a));
	if ((((t_element *)(((t_element *)(p_cheapest->content))
			->p_target->content))->f_upper)
			&& (((t_element *)(p_cheapest->content))->f_upper))
	{
		while (dPushswap->l_stack_a.p_first != p_cheapest
			&& dPushswap->l_stack_b.p_first != p_cheapest)
			ft_rot_twostack(dPushswap, true);
		ft_index_updater((t_catalog *)(&(dPushswap->l_stack_a)));
		ft_index_updater((t_catalog *)(&(dPushswap->l_stack_b)));
	}
	else if (!(((t_element *)(((t_element *)(p_cheapest->content))
			->p_target->content))->f_upper)
			&& !(((t_element *)(p_cheapest->content))->f_upper))
	{
		while (dPushswap->l_stack_a.p_first != p_cheapest
			&& dPushswap->l_stack_b.p_first != p_cheapest)
			ft_rev_twostack(dPushswap, true);
		ft_index_updater((t_catalog *)(&(dPushswap->l_stack_a)));
		ft_index_updater((t_catalog *)(&(dPushswap->l_stack_b)));
	}
	ft_push_provision(dPushswap, p_cheapest, '2', true);
	ft_push_onestack(dPushswap, 'b', true);
}

//"ft_update_stack": Function to update the information contained in each node
//	 of the stacks.
void	ft_update_stack(t_pushswap *dPushswap, char cDestiny)
{
	ft_index_updater((t_catalog *)(&(dPushswap->l_stack_a)));
	ft_index_updater((t_catalog *)(&(dPushswap->l_stack_b)));
	if (cDestiny == 'a')
	{
		ft_mintargets_finder((t_catalog *)(&(dPushswap->l_stack_a)),
			dPushswap->l_stack_b);
		ft_cost_updater((t_catalog *)(&(dPushswap->l_stack_a)),
			dPushswap->l_stack_b);
		ft_set_cheapest((t_catalog *)(&(dPushswap->l_stack_a)));
	}
	else
		ft_maxtargets_finder((t_catalog *)(&(dPushswap->l_stack_b)),
			dPushswap->l_stack_a);
}
//END