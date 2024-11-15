/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:06:01 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/15 11:27:32 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				char_written;

	addr = (unsigned long)ptr;
	if (addr == 0)
		return (write(1, "(nil)", 5));
	char_written = 0;
	char_written += write(1, "0x", 2);
	char_written += ft_print_hex_with_case(addr, 0);
	return (char_written);
}
