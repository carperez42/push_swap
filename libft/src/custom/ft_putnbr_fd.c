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

void	ft_putnbr_fd(int nPrint, int fDscp)
{
	if (nPrint == -2147483648)
	{
		ft_putchar_fd('-', fDscp);
		ft_putchar_fd('2', fDscp);
		ft_putnbr_fd(147483648, fDscp);
	}
	else if (nPrint < 0)
	{
		ft_putchar_fd('-', fDscp);
		ft_putnbr_fd(nPrint * (-1), fDscp);
	}
	else if (nPrint > 9)
	{
		ft_putnbr_fd(nPrint / 10, fDscp);
		ft_putnbr_fd(nPrint % 10, fDscp);
	}
	else
	{
		ft_putchar_fd(nPrint + 48, fDscp);
	}
}
// Send the number 'nPrint' to the given file descriptor, followed by a newline.
// ft_putnbr_fd ft_putchar_fd.c are embedded functions.