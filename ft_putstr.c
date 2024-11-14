/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:59:44 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/14 17:02:30 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putstr(const char *str)
{
	int	char_written;

	char_written = 0;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		char_written += write(1, str, 1);
		str++;
	}
	return (char_written);
}
