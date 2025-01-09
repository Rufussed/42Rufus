/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlane <rlane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:29:19 by rlane             #+#    #+#             */
/*   Updated: 2025/01/07 14:06:35 by rlane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.cpp"

#include <string.h>
#include <sstream>

// Function to convert string to float using stringstream
float stringToFloat(const std::string &str)
{
    std::stringstream ss(str);
    float result;
    ss >> result;
    return result;
}

int main(int argc, char **argv)
{
    if (argc != 9)
    {
        std::cout << "Usage enter 4 coord pairs, first a triangle then point to check: x1 y1 x2 y2 x3 y3 x4 y4" << std::endl;
        return 1;
    }

    float x1 = stringToFloat(argv[1]);
    float y1 = stringToFloat(argv[2]);
    float x2 = stringToFloat(argv[3]);
    float y2 = stringToFloat(argv[4]);
    float x3 = stringToFloat(argv[5]);
    float y3 = stringToFloat(argv[6]);
    float x4 = stringToFloat(argv[7]);
    float y4 = stringToFloat(argv[8]);

    Point a = Point(x1, y1);
    Point b = Point(x2, y2);
    Point c = Point(x3, y3);
    Point point = Point(x4, y4);

    std::cout << "Our triangle has points " << std::endl;
    std::cout << "A: x=" << a.getX() << " y=" << a.getY() << std::endl;
    std::cout << "B: x=" << b.getX() << " y=" << b.getY() << std::endl;
    std::cout << "C: x=" << c.getX() << " y=" << c.getY() << std::endl;
    std::cout << "And our point is " << std::endl;
    std::cout << "Point: x=" << point.getX() << " y=" << point.getY() << std::endl;
    if (bsp(a, b, c, point))
        std::cout << "\nThe point is inside the triangle\n"
                  << std::endl;
    else
        std::cout << "\nThe point is on or outside triangle\n"
                  << std::endl;
    return 0;
}