/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:46:47 by carperez          #+#    #+#             */
/*   Updated: 2024/05/09 17:48:03 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/header/libft.h"

//********************************
//"s_element" is the structure that stores the properties of the values
// of each node in the stacks "a" and "b".
//
//n_valnum: Input digit value.
//n_index: Indicates the position of each node within its stack.
//n_opcost: Stores the cost in operations to place the node and its target node
//			 from the other stack at the beginning of their respective stacks.
//f_upper: Flag to indicate whether the current position of the node is above
//			 or below the stack's midpoint.
//f_cheapest: Flag to mark the node with the lowest cost in the entire stack.
typedef struct s_element
{
	int		n_valnum;
	int		n_index;
	int		n_opcost;
	bool	f_upper;
	bool	f_cheapest;
	t_node	*p_target;
}					t_element;

//********************************
//s_pushswap is the main control structure of the program from which
// the stacks "a" and "b" are managed, error detection is performed,
// and the count of operations performed is handled:
//
//f_error: Flag for error detection.
//	[0]--> Ok/Sorted secuence.
//	[1]--> Error processing input strings.
//	[2]--> Incorrect type of arguments.
//	[3]--> Repeated input arguments error.
//	[4]--> Error exceeding the established input limits.
//	[5]--> Error initializing stack 'a'.
//	[6]--> Unsorted secuence.
//n_inputs: Number of input arguments.
//**a_inputs: Array of inputs argument values.
//*p_diglist: String of registered digital values to detect repetitions.
//**a_temp: Array of substrings obtained from input arguments with
// 			strings containing one or more numerical values.
//l_stack_a: Is the stack "a". Header structure of catalog type
// 			for custom doubly linked list.
//l_stack_b: Is the stack "b". Header structure of catalog type
// 			for custom doubly linked list.
typedef struct s_pushswap
{
	int			f_error;
	int			n_inputs;
	int			n_ops;
	char		**a_inputs;
	char		*p_diglist;
	char		**a_temp;
	t_catalog	l_stack_a;
	t_catalog	l_stack_b;
}				t_pushswap;

//in 000-main.c file
void	*ft_node_creator(int nInt);
//in 001-input_verification.c file
int		ft_input_analizer(t_pushswap *dPushswap);
//in 002-sorting_verification.c file
void	ft_serie_analizer(t_pushswap *dPushswap);
//in 003-stacks_management.c file
void	ft_index_updater(t_catalog *pStack);
void	ft_mintargets_finder(t_catalog *pRef, t_catalog pTrg);
void	ft_maxtargets_finder(t_catalog *pRef, t_catalog pTrg);
void	ft_cost_updater(t_catalog *pRef, t_catalog pTrg);
//in 004-stacks_management.c file
void	ft_a2b_executions(t_pushswap *dPushswap);
void	ft_update_stack(t_pushswap *dPushswap, char cDestiny);
//in 005-push_operations.c file
void	ft_push_onestack(t_pushswap *dPushswap, char cStack);
void	ft_push_provision(t_pushswap *dPushswap, t_node *pGoal, char cMode);
//in 006-rotative_operations.c file
void	ft_rot_onestack(t_pushswap *dPushswap, char *sStack);
void	ft_rot_twostack(t_pushswap *dPushswap);
void	ft_rev_onestack(t_pushswap *dPushswap, char *sStack);
void	ft_rev_twostack(t_pushswap *dPushswap);
//in 007-swap_operations.c file
void	ft_swap_onestack(t_pushswap *dPushswap, char *sStack);
void	ft_swap_twostack(t_pushswap *dPushswap);
#endif
//END