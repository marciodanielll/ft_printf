/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:18:31 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/14 16:25:43 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_format_specifier(const char **input, va_list args)
{
	int		char_written;
	char	specifier;

	char_written = 0;
	specifier = *(*input + 1);
	if (specifier == 'c')
	{
		char_written += ft_putchar(va_arg(args, int));
		*input += 2;
	}
	else if (specifier == 's')
	{
		char_written += ft_putstr(va_arg(args, char *));
		*input += 2;
	}
	else if (specifier == 'p')
	{
		char_written += ft_putptr(va_arg(args, void *), 0);
		*input += 2;
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
