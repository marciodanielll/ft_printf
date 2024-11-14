/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:06:01 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/14 16:15:11 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex(unsigned long addr, char *hex_digits)
{
	int	count;

	count = 0;
	if (addr >= 16)
		count += ft_print_hex(addr / 16, hex_digits);
	count += write(1, &hex_digits[addr % 16], 1);
	return (count);
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

int	ft_putptr(va_list args, int uppercase)
{
	unsigned long	addr;
	int				count;

	addr = (unsigned long)va_arg(args, void *);
	if (addr == 0)
		return (write(1, "(nil)", 5));
	count = 0;
	if (uppercase)
		count += write(1, "0X", 2);
	else
		count += write(1, "0x", 2);
	count += ft_print_hex_factory(addr, uppercase);
	return (count);
}
