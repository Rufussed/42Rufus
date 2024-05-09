/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_handlers_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 08:56:23 by rlane             #+#    #+#             */
/*   Updated: 2024/05/09 11:19:31 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// print single char as int to output and returns 1 to the char count
size_t	ft_print_char(int c)
{
	ft_putchar(c);
	return (1);
}

// print char string to output and returns strlen to char count
size_t	ft_print_string(char *str)
{
	if (str == NULL)
		return (ft_print_string("(null)"));
	ft_putstr(str);
	return (ft_strlen(str));
}

size_t	ft_print_int(int n)
{
	if (n == -2147483648)
		return (ft_print_string("-2147483648"));
	return (ft_putnbr_count(n));
}

size_t	ft_print_unsigned_int(unsigned int n)
{
	return (ft_putnbr_unsigned_count(n));
}

size_t	ft_print_hex_lower(uintptr_t n)
{
	return (ft_putnbr_hex_count(n, "0123456789abcdef"));
}
