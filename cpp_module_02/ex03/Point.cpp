/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:29:47 by rlane             #+#    #+#             */
/*   Updated: 2025/01/06 14:49:22 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}

//create point from floats
Point::Point(float x, float y) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &other)
{
	if (this == &other)
		return *this;
	_x = other._x;
	_y = other._y;
	return *this;
}

Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}

