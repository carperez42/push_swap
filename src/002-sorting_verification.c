/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   002-sorting_verification.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:04:13 by carperez          #+#    #+#             */
/*   Updated: 2024/05/09 16:23:16 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//"ft_sorting_checker": Function to determine if stack 'a' is sorted.
static int	ft_sorting_checker(t_pushswap *dPushswap)
{
	t_catalog	*p_aux;

	dPushswap->f_error = 0;
	p_aux = &(dPushswap->l_stack_a);
	if (p_aux->p_last)
	{
		p_aux->p_current = p_aux->p_first;
		while (p_aux->p_current && !dPushswap->f_error)
		{
			if (p_aux->p_current->p_next)
			{
				if (((t_element *)(p_aux->p_current->content))
						->n_valnum > ((t_element *)(p_aux->p_current
						->p_next->content))->n_valnum)
					dPushswap->f_error = 6;
			}
			p_aux->p_current = p_aux->p_current->p_next;
		}
	}
	return (dPushswap->f_error);
}

//"ft_arrange_three": Function to sort stacks of three nodes.
static void	ft_arrange_three(t_pushswap *dPushswap)
{
	t_catalog	*p_aux;

	p_aux = &(dPushswap->l_stack_a);
	p_aux->p_current = p_aux->p_first->p_next;
	if (((t_element *)(p_aux->p_last->content))->n_valnum
		> ((t_element *)(p_aux->p_first->content))->n_valnum)
	{
		if (((t_element *)(p_aux->p_first->content))->n_valnum
			< ((t_element *)(p_aux->p_current->content))->n_valnum)
			ft_rev_onestack(dPushswap, "a");
		ft_swap_onestack(dPushswap, "a");
	}
	else
	{
		if (((t_element *)(p_aux->p_first->content))->n_valnum
			< ((t_element *)(p_aux->p_current->content))->n_valnum)
			ft_rev_onestack(dPushswap, "a");
		else
		{
			ft_rot_onestack(dPushswap, "a");
			if (((t_element *)(p_aux->p_first->content))->n_valnum
				> ((t_element *)(p_aux->p_current->content))->n_valnum)
				ft_swap_onestack(dPushswap, "a");
		}
	}
}

//"ft_final_sort": Function to perform the final sorting once the nodes of
//	 stack 'b' have been returned to stack 'a'.
static void	ft_final_sort(t_pushswap *dPushswap)
{
	t_node	*p_aux;

	p_aux = NULL;
	if (dPushswap->l_stack_a.p_first)
	{
		dPushswap->l_stack_a.p_current = dPushswap->l_stack_a.p_first;
		p_aux = dPushswap->l_stack_a.p_current;
		while (dPushswap->l_stack_a.p_current->p_next)
		{
			if (((t_element *)(p_aux->content))->n_valnum > (((t_element *)
				(dPushswap->l_stack_a.p_current->p_next->content))->n_valnum))
				p_aux = dPushswap->l_stack_a.p_current->p_next;
			dPushswap->l_stack_a.p_current = dPushswap->l_stack_a.p_current
				->p_next;
		}
		while (dPushswap->l_stack_a.p_first != p_aux)
		{
			if (((t_element *)(p_aux->content))->f_upper)
				ft_rot_onestack(dPushswap, "a");
			else
				ft_rev_onestack(dPushswap, "a");
		}
	}
}

//"ft_arrange_stack": Function to manage each of the main phases of
//	 the sorting algorithm for sequences larger than 3 values.
static void	ft_arrange_stack(t_pushswap *dPushswap)
{
	int	n_counter;

	ft_push_onestack(dPushswap, 'b');
	if ((dPushswap->l_stack_a.n_nodes >= 4) && (ft_sorting_checker(dPushswap)))
		ft_push_onestack(dPushswap, 'b');
	n_counter = dPushswap->l_stack_a.n_nodes;
	while ((n_counter > 3) && (ft_sorting_checker(dPushswap)))
	{
		ft_update_stack(dPushswap, 'a');
		ft_a2b_executions(dPushswap);
		n_counter --;
	}
	if (ft_sorting_checker(dPushswap))
		ft_arrange_three(dPushswap);
	while (dPushswap->l_stack_b.p_first)
	{
		ft_update_stack(dPushswap, 'b');
		ft_push_provision(dPushswap, ((t_element *)(dPushswap
					->l_stack_b.p_first->content))->p_target, '1');
		ft_push_onestack(dPushswap, 'a');
	}
	ft_index_updater((t_catalog *)(&(dPushswap->l_stack_a)));
	ft_final_sort(dPushswap);
}

//"ft_serie_analizer": Function to determine the sorting algorithm based on
//	 the length of the series.
void	ft_serie_analizer(t_pushswap *dPushswap)
{
	t_catalog	*p_aux;

	p_aux = &(dPushswap->l_stack_b);
	ft_init_catalog(&p_aux);
	if (ft_sorting_checker(dPushswap))
	{
		if (((t_catalog)(dPushswap->l_stack_a)).n_nodes == 2)
			ft_swap_onestack(dPushswap, "a");
		else if (((t_catalog)(dPushswap->l_stack_a)).n_nodes == 3)
			ft_arrange_three(dPushswap);
		else
			ft_arrange_stack(dPushswap);
	}
	ft_clear_catalog(&(p_aux), &free);
}
//END