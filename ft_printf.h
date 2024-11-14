/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:00:49 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/14 16:12:58 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *string, ...);
int	ft_putchar(va_list args);
int	ft_putstr(va_list args);
int	ft_putptr(va_list args, int uppercase);

#endif /* FT_PRINTF_H */
