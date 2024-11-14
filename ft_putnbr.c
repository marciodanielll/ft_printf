/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:41:49 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/14 17:19:22 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int is_unsigned)
{
	int				char_written;
	char			c;
	unsigned int	un;

	char_written = 0;
	if (!is_unsigned && n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (is_unsigned)
		un = (unsigned int)n;
	else
	{
		if (n < 0)
		{
			char_written += write(1, "-", 1);
			n = -n;
		}
		un = (unsigned int)n;
	}
	if (un >= 10)
		char_written += ft_putnbr(un / 10, 1);
	c = (un % 10) + '0';
	char_written += write(1, &c, 1);
	return (char_written);
}
