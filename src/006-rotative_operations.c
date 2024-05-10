/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   006-rotative_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:02:10 by carperez          #+#    #+#             */
/*   Updated: 2024/05/10 09:30:04 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_rot_onestack(t_pushswap *dPushswap, char *sStack)
{
	t_catalog	*p_list;
	t_node		*p_aux;

	p_list = NULL;
	p_aux = NULL;
	if (!(ft_strncmp(sStack, "a", 2)) || !(ft_strncmp(sStack, "aa", 2)))
		p_list = &(dPushswap->l_stack_a);
	else if (!(ft_strncmp(sStack, "b", 2)) || !(ft_strncmp(sStack, "bb", 2)))
		p_list = &(dPushswap->l_stack_b);
	if (p_list->n_nodes > 1)
	{
		p_list->p_current = p_list->p_first;
		p_list->p_first = p_list->p_current->p_next;
		p_list->p_first->p_prev = NULL;
		p_list->n_nodes -= 1;
		p_aux = p_list->p_current;
		p_list->p_current = p_list->p_last;
		ft_add_aftercurrent(&p_list, p_aux);
		if (!(ft_strncmp(sStack, "a", 2)) || !(ft_strncmp(sStack, "b", 2)))
		{
			dPushswap->n_ops += 1;
			ft_printf("r%s\n", sStack);
		}
	}
}

void	ft_rot_twostack(t_pushswap *dPushswap)
{
	ft_rot_onestack(dPushswap, "aa");
	ft_rot_onestack(dPushswap, "bb");
	if (dPushswap->l_stack_a.n_nodes > 1 || dPushswap->l_stack_b.n_nodes > 1)
	{
		dPushswap->n_ops += 1;
		ft_printf("rr\n");
	}
}

void	ft_rev_onestack(t_pushswap *dPushswap, char *sStack)
{
	t_catalog	*p_list;

	p_list = NULL;
	if (!(ft_strncmp(sStack, "a", 2)) || !(ft_strncmp(sStack, "aa", 2)))
		p_list = &(dPushswap->l_stack_a);
	else if (!(ft_strncmp(sStack, "b", 2)) || !(ft_strncmp(sStack, "bb", 2)))
		p_list = &(dPushswap->l_stack_b);
	if (p_list->n_nodes > 1)
	{
		p_list->p_current = p_list->p_last;
		p_list->p_last->p_prev->p_next = NULL;
		p_list->p_last = p_list->p_last->p_prev;
		p_list->n_nodes -= 1;
		ft_addnode_front(&p_list, p_list->p_current);
		if (!(ft_strncmp(sStack, "a", 2)) || !(ft_strncmp(sStack, "b", 2)))
		{
			dPushswap->n_ops += 1;
			ft_printf("rr%s\n", sStack);
		}
	}
}

void	ft_rev_twostack(t_pushswap *dPushswap)
{
	ft_rev_onestack(dPushswap, "aa");
	ft_rev_onestack(dPushswap, "bb");
	if (dPushswap->l_stack_a.n_nodes > 1 || dPushswap->l_stack_b.n_nodes > 1)
	{
		dPushswap->n_ops += 1;
		ft_printf("rrr\n");
	}
}
//END