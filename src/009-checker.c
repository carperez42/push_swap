/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   009-checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:55:28 by carperez          #+#    #+#             */
/*   Updated: 2024/05/13 20:27:57 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include "../get_next_line/header/get_next_line.h"

static void	ft_operation_checker(t_pushswap *dChecker, char *sOperation)
{
	if (!(ft_strncmp(sOperation, "sa\n", 3)))
		ft_swap_onestack(dChecker, "a", false);
	else if (!(ft_strncmp(sOperation, "sb\n", 3)))
		ft_swap_onestack(dChecker, "b", false);
	else if (!(ft_strncmp(sOperation, "ss\n", 3)))
		ft_swap_twostack(dChecker, false);
	else if (!(ft_strncmp(sOperation, "ra\n", 3)))
		ft_rot_onestack(dChecker, "a", false);
	else if (!(ft_strncmp(sOperation, "rb\n", 3)))
		ft_rot_onestack(dChecker, "b", false);
	else if (!(ft_strncmp(sOperation, "rr\n", 3)))
		ft_rot_twostack(dChecker, false);
	else if (!(ft_strncmp(sOperation, "rra\n", 4)))
		ft_rev_onestack(dChecker, "a", false);
	else if (!(ft_strncmp(sOperation, "rrb\n", 4)))
		ft_rev_onestack(dChecker, "b", false);
	else if (!(ft_strncmp(sOperation, "rrr\n", 4)))
		ft_rev_twostack(dChecker, false);
	else if (!(ft_strncmp(sOperation, "pa\n", 3)))
		ft_push_onestack(dChecker, 'a', false);
	else if (!(ft_strncmp(sOperation, "pb\n", 3)))
		ft_push_onestack(dChecker, 'b', false);
	else
		dChecker->f_error = 1;
}

static void	ft_line_capturer(t_pushswap *dChecker)
{
	char	*s_operation;

	s_operation = get_next_line(0);
	while (s_operation && !(dChecker->f_error))
	{
		ft_operation_checker(dChecker, s_operation);
		free(s_operation);
		s_operation = NULL;
		if (!(dChecker->f_error))
			s_operation = get_next_line(0);
	}
}

static void	ft_serie_checker(t_pushswap *dChecker)
{
	t_catalog	*p_aux;

	p_aux = &(dChecker->l_stack_b);
	ft_init_catalog(&p_aux);
	ft_line_capturer(dChecker);
	if (dChecker->f_error)
	{
		ft_printf("\033[1;5;31m");
		ft_putstr_fd("Error\n", 2);
		ft_printf("\033[1;0m");
	}
	else
	{
		if (ft_sorting_checker(dChecker))
			ft_printf("\033[1;5;31mKO\033[1;0m\n");
		else
			ft_printf("\033[1;32mOK\033[1;0m\n");
	}
	ft_clear_catalog(&(p_aux), &free);
}

int	main(int nInputs, char **vInputs)
{
	t_pushswap	d_checker;
	t_catalog	*p_aux;

	p_aux = &(d_checker.l_stack_a);
	ft_init_pushswap(&d_checker, nInputs, vInputs);
	if (nInputs > 1)
	{
		ft_input_analizer(&d_checker);
		ft_serie_checker(&d_checker);
		p_aux = &(d_checker.l_stack_a);
		ft_clear_catalog(&(p_aux), &free);
		free(d_checker.p_diglist);
	}
	else
		return (-1);
	return (0);
}
//END