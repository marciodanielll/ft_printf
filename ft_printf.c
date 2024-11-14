/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:18:31 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/14 16:16:24 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(const char **input, va_list args)
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
		count += ft_putptr(args, 0);
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
