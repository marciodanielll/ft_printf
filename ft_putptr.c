/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:06:01 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/14 16:31:58 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex(unsigned long addr, char *hex_digits)
{
	int	char_written;

	char_written = 0;
	if (addr >= 16)
		char_written += ft_print_hex(addr / 16, hex_digits);
	char_written += write(1, &hex_digits[addr % 16], 1);
	return (char_written);
}

static int	ft_print_hex_factory(unsigned long addr, int uppercase)
{
	char	*hex_digits;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	return (ft_print_hex(addr, hex_digits));
}

int	ft_putptr(void *ptr, int uppercase)
{
	unsigned long	addr;
	int				char_written;

	addr = (unsigned long)ptr;
	if (addr == 0)
		return (write(1, "(nil)", 5));
	char_written = 0;
	if (uppercase)
		char_written += write(1, "0X", 2);
	else
		char_written += write(1, "0x", 2);
	char_written += ft_print_hex_factory(addr, uppercase);
	return (char_written);
}
