/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:18:31 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/14 16:49:28 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *), 0));
	else if (specifier == 'd')
		return (ft_putnbr(va_arg(args, int)));
	return (0);
}

static int	parse_format_specifier(const char **input, va_list args)
{
	int		char_written;
	char	specifier;

	specifier = *(*input + 1);
	char_written = handle_specifier(specifier, args);
	if (char_written)
		*input += 2;
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
