/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:31:29 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/11 20:31:37 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}

int	handle_format(const char **input, va_list args)
{
	int	count;

	count = 0;
	if (**input == '%' && *(*input + 1) == 'c')
	{
		count += ft_putchar(args);
		*input += 2;
	}
	else if (**input == '%' && *(*input + 1) == 's')
	{
		count += ft_putstr(args);
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
			write(1, input, 1);
			count++;
			input++;
		}
	}
	va_end(args);
	return (count);
}
