/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhermini <mhermini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:00:49 by mhermini          #+#    #+#             */
/*   Updated: 2024/11/14 16:31:18 by mhermini         ###   ########.fr       */
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
int	ft_putptr(void *ptr, int uppercase);

#endif /* FT_PRINTF_H */
