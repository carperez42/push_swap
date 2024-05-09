/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:29:44 by carperez          #+#    #+#             */
/*   Updated: 2023/02/04 18:30:32 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *sPrint, int fDscp)
{
	ft_putstr_fd(sPrint, fDscp);
	ft_putchar_fd('\n', fDscp);
}
// Send the string 'sPrint' to the given file descriptor, followed by a newline.
// ft_putchar_fd.c ft_putstr_fd.c are embedded functions.