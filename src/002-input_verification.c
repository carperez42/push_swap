/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   002-input_verification.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:17:45 by carperez          #+#    #+#             */
/*   Updated: 2024/05/13 16:12:28 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//"ft_strjoin_v2": Function to concatenate strings consecutively.
static char	*ft_strjoin_v2(char *sResult, char const *sAdd)
{
	char	*p_newbuff;
	int		l_front;
	int		l_back;

	p_newbuff = NULL;
	if (sResult)
		l_front = ft_strlen(sResult);
	else
		l_front = 0;
	l_back = ft_strlen(sAdd);
	p_newbuff = malloc (sizeof(char) * (l_front + l_back + 1));
	if (p_newbuff != NULL)
	{
		if (l_front == 0)
			ft_memcpy(p_newbuff, sAdd, l_back + 1);
		else
		{
			ft_memcpy(p_newbuff, sResult, l_front);
			ft_memcpy(&p_newbuff[l_front], sAdd, l_back + 1);
		}
	}
	return (p_newbuff);
}

//"ft_digit_checker": Function to detect whether all input arguments
//	 are digits or disallowed entries.
static int	ft_digit_checker(t_pushswap *dPushswap)
{
	int		ia;
	int		ib;
	int		n_size;

	ia = 0;
	ib = 0;
	while (dPushswap->a_temp[ia] && (!dPushswap->f_error))
	{
		n_size = ft_strlen(dPushswap->a_temp[ia]);
		if ((dPushswap->a_temp[ia][ib] == '-'
			|| dPushswap->a_temp[ia][ib] == '+') && (n_size > 1))
			ib ++;
		else if (!(ft_isdigit(dPushswap->a_temp[ia][ib])))
			dPushswap->f_error = 2;
		while (ib < n_size && !dPushswap->f_error)
		{
			if (ft_isdigit(dPushswap->a_temp[ia][ib]))
				ib ++;
			else
				dPushswap->f_error = 2;
		}
		ib = 0;
		ia ++;
	}
	return (dPushswap->f_error);
}

//"ft_rep_checker": Function to detect if any input argument is repeated.
static int	ft_rep_checker(t_pushswap *dPushswap)
{
	char	*p_aux;
	int		ia;

	ia = 0;
	while (dPushswap->a_temp[ia] && (!dPushswap->f_error))
	{
		p_aux = ft_strjoin_v2(dPushswap->a_temp[ia], " ");
		p_aux = ft_strjoin_v2(" ", p_aux);
		if (!(ft_strnstr(dPushswap->p_diglist, p_aux,
					ft_strlen(dPushswap->p_diglist))))
		{
			dPushswap->p_diglist = ft_strjoin_v2(dPushswap->p_diglist, p_aux);
			free(p_aux);
			p_aux = NULL;
			ia ++;
		}
		else
			dPushswap->f_error = 3;
	}
	return (dPushswap->f_error);
}

//"ft_int_converter": Function to convert character strings to their respective
//	 integer digit values and store them in nodes of stack 'a'.
static void	ft_int_converter(t_pushswap *dPushswap)
{
	long		n_int;
	int			ia;
	t_node		*p_aux;
	t_catalog	*p_list;

	p_list = &(dPushswap->l_stack_a);
	ia = 0;
	while (dPushswap->a_temp[ia] && (!dPushswap->f_error))
	{
		n_int = ft_atol((const char *)dPushswap->a_temp[ia]);
		if (n_int <= INT_MAX && n_int >= INT_MIN)
		{
			p_aux = ft_node_creator(n_int);
			if (p_aux)
			{
				ft_addnode_back(&(p_list), p_aux);
				if (!(dPushswap->l_stack_a.p_first))
					dPushswap->f_error = 5;
				else
					ia ++;
			}
		}
		else
			dPushswap->f_error = 4;
	}
}

//"ft_input_analizer": Function to determine if all input arguments meet
//	 the requirements to be stored in stack 'a'.
int	ft_input_analizer(t_pushswap *dPushswap)
{
	int	ia;
	int	n_dim;

	n_dim = 0;
	ia = 1;
	dPushswap->p_diglist = malloc(sizeof(char));
	*(dPushswap->p_diglist) = '\0';
	while (ia < dPushswap->n_inputs && (!dPushswap->f_error))
	{
		dPushswap->a_temp = ft_split(dPushswap->a_inputs[ia], ' ');
		if (dPushswap->a_temp)
		{
			while (dPushswap->a_temp[n_dim])
				n_dim ++;
			if (!(ft_digit_checker(dPushswap)))
				if (!ft_rep_checker(dPushswap))
					ft_int_converter(dPushswap);
			ft_array_free(dPushswap->a_temp, n_dim);
			n_dim = 0;
			ia ++;
		}
		else
			dPushswap->f_error = 1;
	}
	return (dPushswap->f_error);
}
//END
