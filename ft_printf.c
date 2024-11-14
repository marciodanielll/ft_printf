/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:18:31 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/12 08:13:45 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(va_list args)
{
	char	temp;

	temp = (char)va_arg(args, int);
	write(1, &temp, 1);
	return (1);
}

int	ft_putstr(va_list args)
{
	char	*str;
	int		count;

	str = va_arg(args, char *);
	count = 0;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}

int	ft_print_hex(unsigned long addr)
{
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789abcdef";
	count = 0;
	if (addr >= 16)
		count += ft_print_hex(addr / 16);
	count += write(1, &hex_digits[addr % 16], 1);
	return (count);
}

int	ft_putptr(va_list args)
{
	unsigned long	addr;
	int				count;

	addr = (unsigned long)va_arg(args, void *);
	if (addr == 0)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	count += ft_print_hex(addr);
	return (count);
}

int	handle_format(const char **input, va_list args)
{
	int	count;

	count = 0;
	if (*(*input + 1) == 'c')
	{
		count += ft_putchar(args);
		*input += 2;
	}
	else if (*(*input + 1) == 's')
	{
		count += ft_putstr(args);
		*input += 2;
	}
	else if (*(*input + 1) == 'p')
	{
		count += ft_putptr(args);
		*input += 2;
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, input);
	while (*input)
	{
		if (*input == '%')
		{
			count += handle_format(&input, args);
		}
		else
		{
			count += write(1, input, 1);
			input++;
		}
	}
	va_end(args);
	return (count);
}
