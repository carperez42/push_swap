/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:29:44 by carperez          #+#    #+#             */
/*   Updated: 2023/02/04 18:30:32 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char cPrint, int fDscp)
{
	write(fDscp, &cPrint, 1);
}
// Send the character 'cPrint' to the specified file descriptor.
// 'fDscp' 0 es la entrada stdin (estandar)
// 'fDscp' 1 es la salida stdout (estandar)
// 'fDscp' 2 es la salida stderr (errores estandar)
