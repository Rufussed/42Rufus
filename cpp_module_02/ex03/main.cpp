/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:19 by rlane             #+#    #+#             */
/*   Updated: 2025/01/06 15:00:29 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include "Point.hpp"

// we calculate he areas of the three triangles made between the point and the three points of the triangle
// if the point is inside the triangle, the sum of the areas of the three triangles is equal to the area of the triangle
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed area1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
    Fixed area2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
    Fixed area3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());
    if ((area1 > 0 && area2 > 0 && area3 > 0) || (area1 < 0 && area2 < 0 && area3 < 0))
        return true;
    return false;
}

int main(void)
{
    Point a = Point(0, 0);
    Point b = Point(3, 0);
    Point c = Point(0, 3);
    Point point = Point(0, 0);

    std::cout << "Our triangle has points " << std::endl;
    std::cout << "A: x="  << a.getX() << " y=" << a.getY() << std::endl;
    std::cout << "B: x="  << b.getX() << " y=" << b.getY() << std::endl;
    std::cout << "C: x="  << c.getX() << " y=" << c.getY() << std::endl;
    std::cout << "And our point is " << std::endl;
    std::cout << "Point: x="  << point.getX() << " y=" << point.getY() << std::endl;
    if (bsp(a, b, c, point))
        std::cout << "\nThe point is inside the triangle" << std::endl;
    else
        std::cout << "\nThe point is outside or on the edge of the triangle" << std::endl;
    return 0;
    
}