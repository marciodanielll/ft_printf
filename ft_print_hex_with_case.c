/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_with_case.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:17:49 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/15 13:34:50 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex_recursive(unsigned long addr, const char *hex_digits)
{
	int	char_written;

	char_written = 0;
	if (addr >= 16)
		char_written += ft_print_hex_recursive(addr / 16, hex_digits);
	char_written += ft_putchar(hex_digits[addr % 16]);
	return (char_written);
}

int	ft_print_hex_with_case(unsigned long addr, int uppercase)
{
	const char	*hex_digits;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	return (ft_print_hex_recursive(addr, hex_digits));
}
