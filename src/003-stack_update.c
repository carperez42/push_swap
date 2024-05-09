/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   003-stack_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:25:57 by carperez          #+#    #+#             */
/*   Updated: 2024/05/09 16:23:33 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//"ft_index_updater": Function to index each node of the stack and to indicate
//	 if it is above or below the stack's equator
void	ft_index_updater(t_catalog *pStack)
{
	int	ia;
	int	n_midpoint;

	ia = 0;
	if (pStack)
	{
		n_midpoint = (pStack->n_nodes) / 2 ;
		pStack->p_current = pStack->p_first;
		while (pStack->p_current)
		{
			((t_element *)(pStack->p_current->content))->n_index = ia;
			if (ia <= n_midpoint)
				((t_element *)(pStack->p_current->content))->f_upper = true;
			else
				((t_element *)(pStack->p_current->content))->f_upper = false;
			pStack->p_current = pStack->p_current->p_next;
			ia ++;
		}
	}
}

//"ft_extreme_finder": Function to assign and link the maximum or minimum
//	 target of the stack corresponding to the evaluated node.
static void	ft_extreme_finder(t_catalog *pRef, t_catalog pTrg, char *sExt)
{
	pTrg.p_current = pTrg.p_first;
	((t_element *)pRef->p_current->content)->p_target = pTrg.p_current;
	while (pTrg.p_current)
	{
		if (((((t_element *)(pTrg.p_current->content))->n_valnum
				> ((t_element *)(((t_element *)pRef->p_current->content)
					->p_target->content))->n_valnum)
			&& !(ft_strncmp(sExt, "MAX", 3)))
				|| ((((t_element *)(pTrg.p_current->content))->n_valnum
			< ((t_element *)(((t_element *)pRef->p_current->content)
					->p_target->content))->n_valnum)
				&& !(ft_strncmp(sExt, "MIN", 3))))
			((t_element *)pRef->p_current->content)->p_target
				= pTrg.p_current;
		pTrg.p_current = pTrg.p_current->p_next;
	}
}

//"ft_mintargets_finder": Function to assign the target corresponding
//	 to each node of stack 'a'.
void	ft_mintargets_finder(t_catalog *pRef, t_catalog pTrg)
{
	long	n_limit;

	pRef->p_current = pRef->p_first;
	while (pRef->p_current)
	{
		n_limit = LONG_MIN;
		pTrg.p_current = pTrg.p_first;
		while (pTrg.p_current)
		{
			if ((((t_element *)(pTrg.p_current->content))->n_valnum
				< ((t_element *)pRef->p_current->content)->n_valnum)
				&& (((t_element *)(pTrg.p_current->content))->n_valnum
				> n_limit))
			{
				n_limit = ((t_element *)(pTrg.p_current->content))
					->n_valnum;
				((t_element *)pRef->p_current->content)->p_target
					= pTrg.p_current;
			}
			pTrg.p_current = pTrg.p_current->p_next;
		}
		if (n_limit == LONG_MIN)
			ft_extreme_finder(pRef, pTrg, "MAX");
		pRef->p_current = pRef->p_current->p_next;
	}
}

//"ft_maxtargets_finder": Function to assign the target to the first node
//	 of stack 'b'.
void	ft_maxtargets_finder(t_catalog *pRef, t_catalog pTrg)
{
	long	n_limit;

	pRef->p_current = pRef->p_first;
	n_limit = LONG_MAX;
	pTrg.p_current = pTrg.p_first;
	while (pTrg.p_current)
	{
		if ((((t_element *)(pTrg.p_current->content))->n_valnum
			> ((t_element *)pRef->p_current->content)->n_valnum)
			&& (((t_element *)(pTrg.p_current->content))->n_valnum
			< n_limit))
		{
			n_limit = ((t_element *)(pTrg.p_current->content))
				->n_valnum;
			((t_element *)pRef->p_current->content)->p_target
				= pTrg.p_current;
		}
		pTrg.p_current = pTrg.p_current->p_next;
	}
	if (n_limit == LONG_MAX)
		ft_extreme_finder(pRef, pTrg, "MIN");
}

//"ft_cost_updater": Function to recalculate the number of operations needed to
//	 move each node from stack 'a' to stack 'b'.
void	ft_cost_updater(t_catalog *pRef, t_catalog pTrg)
{
	t_node	*p_aux;

	pRef->p_current = pRef->p_first;
	while (pRef->p_current)
	{
		((t_element *)pRef->p_current->content)->n_opcost
			= ((t_element *)pRef->p_current->content)->n_index;
		if (!(((t_element *)pRef->p_current->content)->f_upper))
			((t_element *)pRef->p_current->content)->n_opcost
				= pRef->n_nodes - ((t_element *)pRef
					->p_current->content)->n_index;
		p_aux = (((t_element *)pRef->p_current->content)->p_target);
		if (((t_element *)pRef->p_current->content)->f_upper)
			((t_element *)pRef->p_current->content)->n_opcost
				+= ((t_element *)(p_aux->content))->n_index;
		else
			((t_element *)pRef->p_current->content)->n_opcost
				+= pTrg.n_nodes - ((t_element *)(p_aux->content))->n_index;
		pRef->p_current = pRef->p_current->p_next;
	}
}
//END