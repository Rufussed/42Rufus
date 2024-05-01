/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:44:36 by rlane             #+#    #+#             */
/*   Updated: 2024/04/19 16:05:48 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

// s in s-point is "struct", it is the full def which incudes the typeof struct
// t in t-point is typedef, its an alias that abstracts needing the full defn.

typedef struct s_point 
{
	int	x;
	int	y;
}	t_point;

#endif
