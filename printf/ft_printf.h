/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:19:08 by rlane             #+#    #+#             */
/*   Updated: 2024/05/08 19:35:46 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>

//# include <stdio.h>
// # include <fcntl.h>
//# include <stddef.h>
void	ft_putchar_fd(char c, int fd);
int		ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_count_elements_base(long long n, long long base);
void	ft_putnbr_hex(unsigned int nb, char *charset);
void	ft_putnbr_pointer(uintptr_t nb, char *charset);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_print_char(int c);
size_t	ft_print_string(char *str);
size_t	ft_print_int(int n);
size_t	ft_print_unsigned_int(unsigned int n);
size_t	ft_print_hex_lower(uintptr_t n);
size_t	ft_print_hex_upper(uintptr_t n);
size_t	ft_print_address(void * address);
size_t	ft_print_percent(void);
size_t	ft_format_handler(char format, va_list args);


int		ft_printf(const char *str, ...);


#endif