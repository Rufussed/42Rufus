/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_handlers_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:08:55 by rlane             #+#    #+#             */
/*   Updated: 2024/05/09 11:20:15 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_hex_upper(uintptr_t n)
{
	return (ft_putnbr_hex_count(n, "0123456789ABCDEF"));
}

size_t	ft_print_address(void *address)
{
	uintptr_t	n;

	if (address == NULL)
		return (ft_print_string("(nil)"));
	n = (uintptr_t)address;
	ft_putstr("0x");
	return (2 + ft_putnbr_pointer_count(n, "0123456789abcdef"));
}

size_t	ft_print_percent(void)
{
	return (ft_print_char('%'));
}
