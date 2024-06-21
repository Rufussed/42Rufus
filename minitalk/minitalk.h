/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:49:27 by rlane             #+#    #+#             */
/*   Updated: 2024/06/21 11:09:11 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H


// redefined SIGUSR1 12 and SIGUSR2 10
# define BIT0 10
# define BIT1 12


# include <signal.h>
# include "libft/src/libft.h"

int	server(void);

#endif