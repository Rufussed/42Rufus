/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-area.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:19 by rlane             #+#    #+#             */
/*   Updated: 2025/01/07 14:06:29 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include "Point.hpp"

#include "Point.hpp" // Include your Point header file

// determinate method for area of triangle , half of determinate of 3 by 3 matrix with coords and 1
Fixed triangleArea(Point const &a, Point const &b, Point const &c)
{
    Fixed area = (a.getX() * (b.getY() - c.getY()) +
                  b.getX() * (c.getY() - a.getY()) +
                  c.getX() * (a.getY() - b.getY())) /
                 2;

    return (area < 0 ? area * (-1) : area); // Return absolute value
}

bool bsp(Point const &a, Point const &b, Point const &c, Point const &p)
{
    // Compute the area of the large triangle ABC
    Fixed areaABC = triangleArea(a, b, c);

    // Compute the areas of the triangles ABP, BCP, and CAP
    Fixed areaABP = triangleArea(a, b, p);
    Fixed areaBCP = triangleArea(b, c, p);
    Fixed areaCAP = triangleArea(c, a, p);

    // Check if the sum of the smaller triangle areas equals the larger triangle area
    if (areaABC == (areaABP + areaBCP + areaCAP) && !(areaABC == 0 || areaABP == 0 || areaBCP == 0 || areaCAP == 0))
        return true; // Point is inside or on the triangle
    return false;    // Point is outside the triangle
}

int main(void)
{
    Point a = Point(0, 0);
    Point b = Point(3, 0);
    Point c = Point(0, 3);
    Point point = Point(1, 1);

    std::cout << "Our triangle has points " << std::endl;
    std::cout << "A: x=" << a.getX() << " y=" << a.getY() << std::endl;
    std::cout << "B: x=" << b.getX() << " y=" << b.getY() << std::endl;
    std::cout << "C: x=" << c.getX() << " y=" << c.getY() << std::endl;
    std::cout << "And our point is " << std::endl;
    std::cout << "Point: x=" << point.getX() << " y=" << point.getY() << std::endl;
    if (bsp(a, b, c, point))
        std::cout << "\nThe point is inside the triangle" << std::endl;
    else
        std::cout << "\nThe point is outside or on the edge of the triangle" << std::endl;
    return 0;
}