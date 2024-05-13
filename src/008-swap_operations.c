/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   008-swap_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:58:02 by carperez          #+#    #+#             */
/*   Updated: 2024/05/13 20:16:27 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_swap_onestack(t_pushswap *dPushswap, char *sStack, bool bPrint)
{
	t_catalog	*p_list;

	p_list = NULL;
	if (!(ft_strncmp(sStack, "a", 2)) || !(ft_strncmp(sStack, "aa", 2)))
		p_list = &(dPushswap->l_stack_a);
	else if (!(ft_strncmp(sStack, "b", 2)) || !(ft_strncmp(sStack, "bb", 2)))
		p_list = &(dPushswap->l_stack_b);
	if (p_list->n_nodes > 1)
	{
		p_list->p_current = p_list->p_first->p_next;
		p_list->p_current->p_prev = NULL;
		p_list->p_first->p_next = p_list->p_current->p_next;
		p_list->p_current->p_next = p_list->p_first;
		p_list->p_first->p_prev = p_list->p_current;
		if (p_list->p_first->p_next)
			p_list->p_first->p_next->p_prev = p_list->p_first;
		else
			p_list->p_last = p_list->p_first;
		p_list->p_first = p_list->p_current;
		if ((!(ft_strncmp(sStack, "a", 2)) || !(ft_strncmp(sStack, "b", 2)))
			&& bPrint)
			ft_printf("s%s\n", sStack);
	}
}

void	ft_swap_twostack(t_pushswap *dPushswap, bool bPrint)
{
	ft_swap_onestack(dPushswap, "aa", bPrint);
	ft_swap_onestack(dPushswap, "bb", bPrint);
	if ((dPushswap->l_stack_a.n_nodes > 1 || dPushswap->l_stack_b.n_nodes > 1)
		&& bPrint)
		ft_printf("ss\n");
}
//END