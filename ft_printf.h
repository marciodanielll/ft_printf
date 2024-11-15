/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:00:49 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/15 11:27:52 by mhermini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *string, ...);
int	ft_putchar(int c);
int	ft_putstr(const char *str);
int	ft_putptr(void *ptr);
int	ft_putnbr(int n, int is_unsigned);
int	ft_puthex(unsigned int num, int uppercase);
int	ft_print_hex_with_case(unsigned long addr, int uppercase);

#endif /* FT_PRINTF_H */
