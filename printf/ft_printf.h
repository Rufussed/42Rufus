/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:19:08 by rlane             #+#    #+#             */
/*   Updated: 2024/05/16 12:43:34 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *s);
size_t	ft_putnbr_hex_count(unsigned int nb, char *charset);
size_t	ft_putnbr_pointer_count(uintptr_t nb, char *charset);
size_t	ft_putnbr_count(int n);
size_t	ft_putnbr_unsigned_count(unsigned int n);
size_t	ft_print_char(int c);
size_t	ft_print_string(char *str);
size_t	ft_print_address(void *address);
int		ft_printf(const char *str, ...);

#endif