/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:18:31 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/15 11:28:05 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dispatch_format_handler(char specifier, va_list args)
{
	const char	*str_arg;

	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (specifier == 's')
	{
		str_arg = va_arg(args, char *);
		return (ft_putstr(str_arg));
	}
	if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int), 0));
	if (specifier == 'x' || specifier == 'X')
		return (ft_puthex(va_arg(args, unsigned int), (specifier == 'X')));
	if (specifier == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), 1));
	return (-1);
}

static int	process_format_token(const char **input, va_list args)
{
	int	char_written;

	char_written = 0;
	if (*(*input + 1) == '%')
	{
		char_written += ft_putchar('%');
		*input += 2;
		return (char_written);
	}
	char_written = dispatch_format_handler(*(*input + 1), args);
	*input += 2;
	if (char_written == -1)
	{
		char_written += ft_putchar('%');
		char_written += ft_putchar(*(*input - 1));
	}
	return (char_written);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		char_written;

	char_written = 0;
	va_start(args, input);
	while (*input)
	{
		if (*input == '%')
			char_written += process_format_token(&input, args);
		else
			char_written += ft_putchar(*input++);
	}
	va_end(args);
	return (char_written);
}
