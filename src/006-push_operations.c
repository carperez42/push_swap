/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   006-push_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:59:08 by carperez          #+#    #+#             */
/*   Updated: 2024/05/13 18:30:33 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//"ft_pa_pb":
static void	ft_pa_pb(t_pushswap *dPushswap, t_catalog **pDestiny
		, t_catalog **pOrigin, char cDestiny)
{
	if (cDestiny == 'a')
	{
		(*pDestiny) = &(dPushswap->l_stack_a);
		(*pOrigin) = &(dPushswap->l_stack_b);
	}
	else if (cDestiny == 'b')
	{
		(*pDestiny) = &(dPushswap->l_stack_b);
		(*pOrigin) = &(dPushswap->l_stack_a);
	}
}

//"ft_push_onestack":
void	ft_push_onestack(t_pushswap *dPushswap, char cDestiny, bool bPrint)
{
	t_catalog	*p_destiny;
	t_catalog	*p_origin;

	ft_pa_pb(dPushswap, &p_destiny, &p_origin, cDestiny);
	if (p_origin->n_nodes > 0)
	{
		p_origin->p_current = p_origin->p_first;
		if (p_origin->p_current == p_origin->p_last)
			p_origin->p_last = NULL;
		else
			p_origin->p_current->p_next->p_prev = NULL;
		p_origin->p_first = p_origin->p_current->p_next;
		ft_addnode_front(&p_destiny, p_origin->p_current);
		p_origin->n_nodes -= 1;
		if (bPrint)
			ft_printf("p%c\n", cDestiny);
	}
}

//"ft_push_provision":
void	ft_push_provision(t_pushswap *dPushswap, t_node *pGoal, char cMode,
		bool bPrint)
{
	while (dPushswap->l_stack_a.p_first != pGoal)
	{
		if (((t_element *)(pGoal->content))->f_upper)
			ft_rot_onestack(dPushswap, "a", bPrint);
		else
			ft_rev_onestack(dPushswap, "a", bPrint);
	}
	while (dPushswap->l_stack_b.p_first != ((t_element *)(pGoal->content))
		->p_target && (cMode == '2'))
	{
		if (((t_element *)(((t_element *)(pGoal->content))
			->p_target->content))->f_upper)
			ft_rot_onestack(dPushswap, "b", bPrint);
		else
			ft_rev_onestack(dPushswap, "b", bPrint);
	}
}
//END