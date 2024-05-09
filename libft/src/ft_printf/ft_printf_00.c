/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:23:02 by carperez          #+#    #+#             */
/*   Updated: 2023/05/13 11:23:02 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// "ft_print_rowstr" displays the character pointed to by pPlace on stdout and
// shifts it. It returns 1 every time it is executed.
static int	ft_print_rowstr(char **pPlace)
{
	ft_putchar_fd(**pPlace, 1);
	*pPlace += 1;
	return (1);
}

// "ft_print_arg" displays on stdout the processed argument converted to
// a string. It accumulates the number of characters printed so far.
static void	ft_print_arg(t_set *pSet, int *nPrinted)
{
	char	*p_argstring;

	p_argstring = NULL;
	if (pSet->c_type == 'c' || pSet->c_type == '%')
		ft_print_chr(pSet, nPrinted);
	else if (pSet->c_type == 's')
		p_argstring = ft_print_str(pSet, nPrinted);
	else if (pSet->c_type == 'p')
		p_argstring = ft_print_ptr(pSet, nPrinted);
	else if (pSet->c_type == 'd' || pSet->c_type == 'i')
		p_argstring = ft_print_int(pSet, nPrinted);
	else if (pSet->c_type == 'u')
		p_argstring = ft_print_uns(pSet, nPrinted);
	else if (pSet->c_type == 'x' || pSet->c_type == 'X')
		p_argstring = ft_print_hex(pSet, nPrinted);
	if (p_argstring != NULL && pSet->c_type != 'c' && pSet->c_type != '%')
	{
		ft_putstr_fd(p_argstring, 1);
		free(p_argstring);
	}
	else if (pSet->c_type != 'c' && pSet->c_type != '%')
		pSet->f_error = 13;
}

// "ft_pholder_capturer" confirms that the placeholder exists, analyzes its
// configuration, and validates that it is legal. If the conditions are
// fulfilled, it displays it on stdout.
static int	ft_pholder_capturer(char const *sToken, t_set *pSet, int *nPrinted)
{
	int		ia;
	char	*p_newpholder;

	ia = 1;
	p_newpholder = NULL;
	while (*(sToken + ia) != '\0' && !ft_isalpha(*(sToken + ia))
		&& *(sToken + ia) != '%')
		ia ++;
	if (!ft_set_type(*(sToken + ia), pSet))
	{
		ia ++;
		p_newpholder = (char *) malloc ((ia + 1) * sizeof(char *));
		if (p_newpholder != NULL)
		{
			ft_strlcpy(p_newpholder, sToken, ia + 1);
			ft_set_validator(p_newpholder, pSet);
			free(p_newpholder);
			if (!pSet->f_error)
				ft_print_arg(pSet, nPrinted);
		}
	}
	if (p_newpholder == NULL)
		pSet->f_error = 1;
	return (ia);
}

// "ft_print_core" displays character by character on stdout and accumulates
// the number of each interaction, as long as it does not detect a possible
// placeholder. If it detects a placeholder, it starts processing it.
static void	ft_print_core(char **pPlace, t_set *pSet, int *nPrinted)
{
	int	ia;

	ia = 0;
	if (**pPlace != '%')
		*nPrinted += ft_print_rowstr(pPlace);
	else
	{
		ia = ft_pholder_capturer(*pPlace, pSet, nPrinted);
		if (!pSet->f_error)
		{
			ft_set_starter(pSet);
			*pPlace += ia;
		}
	}
}

// "ft_printf" is the main variadic function where the argument list is
// initialized and freed. It also invokes the functions that will display on
// stdout and shows the error message, just in case.
int	ft_printf(char const *sPrint, ...)
{
	t_set	s_set;
	int		n_printed;

	n_printed = 0;
	if (sPrint != NULL)
	{
		va_start(s_set.lst_items, sPrint);
		ft_set_starter(&s_set);
		while (*sPrint != '\0' && !s_set.f_error)
			ft_print_core((char **)&sPrint, &s_set, &n_printed);
		va_end(s_set.lst_items);
	}
	return (n_printed);
}

// END