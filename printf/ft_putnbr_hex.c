/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:38:45 by rlane             #+#    #+#             */
/*   Updated: 2024/05/08 18:46:15 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned int nb, char *charset)

{
	unsigned int	base;

	base = 16;
	if (nb >= base)
	{
		ft_putnbr_hex((nb / base), charset);
		ft_putchar_fd(charset[(nb % base)], 1);
	}
	else
		ft_putchar_fd(charset[nb], 1);
}

void	ft_putnbr_pointer(uintptr_t nb, char *charset)

{
	uintptr_t	base;

	base = 16;
	if (nb >= base)
	{
		ft_putnbr_hex((nb / base), charset);
		ft_putchar_fd(charset[(nb % base)], 1);
	}
	else
		ft_putchar_fd(charset[nb], 1);
}