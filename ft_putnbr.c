/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:41:49 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/14 16:52:29 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		char_written;
	char	c;

	char_written = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		char_written += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		char_written += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	char_written += write(1, &c, 1);
	return (char_written);
}
