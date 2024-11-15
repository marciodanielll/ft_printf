/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:41:49 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/15 13:35:54 by mhermini         ###   ########.fr       */
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
		return (ft_putstr("-2147483648"));
	if (is_unsigned)
		un = (unsigned int)n;
	else
	{
		if (n < 0)
		{
			char_written += ft_putchar('-');
			n = -n;
		}
		un = (unsigned int)n;
	}
	if (un >= 10)
		char_written += ft_putnbr(un / 10, 1);
	c = (un % 10) + '0';
	char_written += ft_putchar(c);
	return (char_written);
}
