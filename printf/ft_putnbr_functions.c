/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:27:32 by rlane             #+#    #+#             */
/*   Updated: 2024/05/09 11:22:06 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Output and count various number formats

size_t	ft_putnbr_count(int n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		count++;
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_count(n / 10);
	ft_putchar(n % 10 + '0');
	count++;
	return (count);
}

size_t	ft_putnbr_unsigned_count(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned_count(n / 10);
	ft_putchar(n % 10 + '0');
	count++;
	return (count);
}

size_t	ft_putnbr_hex_count(unsigned int n, char *charset)
{
	unsigned int	base;
	size_t			count;

	base = 16;
	count = 0;
	if (n >= base)
		count += ft_putnbr_hex_count((n / base), charset);
	ft_putchar(charset[(n % base)]);
	count++;
	return (count);
}

size_t	ft_putnbr_pointer_count(uintptr_t n, char *charset)
{
	uintptr_t	base;
	size_t		count;

	base = 16;
	count = 0;
	if (n >= base)
		count += ft_putnbr_pointer_count((n / base), charset);
	ft_putchar(charset[(n % base)]);
	count++;
	return (count);
}
