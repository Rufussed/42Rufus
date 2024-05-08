/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_printers_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 08:56:23 by rlane             #+#    #+#             */
/*   Updated: 2024/05/08 19:35:39 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// print single char as int to output and returns 1 to the char count
size_t	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

// print char string to output and returns strlen to char count
size_t	ft_print_string(char *str)
{
	if (str == NULL)
		{
			return ft_print_string("(null)");
		}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

size_t	ft_print_int(int n)
{
	if (n == -2147483648)
		return (ft_print_string("-2147483648"));
	ft_putnbr_fd(n, 1);
	return (ft_count_elements_base(n, 10));	
}

size_t	ft_print_unsigned_int(unsigned int n)
{
	ft_putnbr_fd((unsigned int)n, 1);
	return (ft_count_elements_base(n, 10));	
}

size_t	ft_print_hex_lower(uintptr_t n)
{
	ft_putnbr_hex(n, "0123456789abcdef");
	return (ft_count_elements_base(n, 16));	
}

size_t	ft_print_hex_upper(uintptr_t n)
{
	ft_putnbr_hex(n, "0123456789ABCDEF");
	return (ft_count_elements_base(n, 16));	
}

