/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:18:31 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/14 19:18:16 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_specifier(char specifier, va_list args)
{
	const char	*str_arg;

	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
	{
		str_arg = va_arg(args, char *);
		if (str_arg == NULL)
			str_arg = "(null)";
		return (ft_putstr(str_arg));
	}
	else if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *), 0));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int), 0));
	else if (specifier == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (specifier == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), 1));
	else if (specifier == '%')
		return (write(1, "%%", 2));
	return (-1);
}

static int	parse_format_specifier(const char **input, va_list args)
{
	int		char_written;
	char	specifier;

	specifier = *(*input + 1);
	char_written = handle_specifier(specifier, args);
	*input += 2;
	if (char_written == -1)
	{
		write(1, "%", 1);
		write(1, &specifier, 1);
		char_written = 2;
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
			char_written += parse_format_specifier(&input, args);
		else
			char_written += write(1, input++, 1);
	}
	va_end(args);
	return (char_written);
}
