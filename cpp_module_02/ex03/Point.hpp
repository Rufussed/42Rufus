/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:29:47 by rlane             #+#    #+#             */
/*   Updated: 2025/01/07 14:07:03 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed _x;
	Fixed _y;

public:
	Point();
	Point(const Point &other);
	Point(const Fixed x, const Fixed y);
	~Point();
	Point &operator=(const Point &other);

	Point(float x, float y);

	Fixed getX() const;
	Fixed getY() const;
};

#endif // POINT_HPP
