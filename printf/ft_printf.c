/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:58:41 by rlane             #+#    #+#             */
/*   Updated: 2024/05/08 19:35:47 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// take format character and choose output function
// return character count increase
size_t	ft_format_handler(char format, va_list args)
{
	if (format == 'c')
		return (ft_print_char((char)va_arg(args, int)));
	if (format == 's')
		return (ft_print_string(va_arg(args, char*)));
	if (format == 's')
		return (ft_print_string(va_arg(args, char*)));
	if (format == 'd')
		return (ft_print_int(va_arg(args, int)));
	if (format == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (format == 'u')
		return (ft_print_unsigned_int(va_arg(args, unsigned int)));
	if (format == 'x')
		return (ft_print_hex_lower(va_arg(args, uintptr_t)));
	if (format == 'X')
		return (ft_print_hex_upper(va_arg(args, uintptr_t)));
	if (format == 'p')
		return (ft_print_address(va_arg(args, void *)));
	if (format == '%')
		return (ft_print_percent());
		
	return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t	str_count;
	size_t	print_count;

	va_list	args;
	if (!str)
		return (0);
	va_start(args, str);
	str_count = 0;
	print_count = 0;
	while(str[str_count])
	{
		if(str[str_count] == '%' && str[str_count + 1])
		{
			str_count++;
			print_count += ft_format_handler(str[str_count], args);
			str_count++;			
		}
		else
		{
			ft_putchar_fd(str[str_count], 1);
			print_count++;
			str_count++;			
		}
	}
	return ((print_count));
}
