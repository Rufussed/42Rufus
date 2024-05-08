/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_printers_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:08:55 by rlane             #+#    #+#             */
/*   Updated: 2024/05/08 18:48:39 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_address(void * address)
{
	uintptr_t	n;

	if(address == NULL)
		return (ft_print_string("(nil)"));
	n = (uintptr_t)address;

	//if (n < 0)
	//	return (ft_print_string("(null)"));
	ft_putstr_fd("0x", 1);
	ft_putnbr_pointer(n, "0123456789abcdef");
	return (2 + ft_count_elements_base(n, 16));	
}

size_t	ft_print_percent(void)
{
	return (ft_print_char('%'));
}
