/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:11:53 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/06 20:51:01 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Fixed	triangleArea(Point const &p1, Point const &p2, Point const &p3)
{
	Fixed x1 = p1.getX();
	Fixed y1 = p1.getY();
	Fixed x2 = p2.getX();
	Fixed y2 = p2.getY();
	Fixed x3 = p3.getX();
	Fixed y3 = p3.getY();

	// matrix determinant formula: (1/2) * |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)|
	Fixed area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / Fixed(2);

	if (area < Fixed(0))
		return area * Fixed(-1);
	return area;
}

bool	isOnVertex(Point const &a, Point const &b, Point const &c, Point const &point) {
	return ((point.getX() == a.getX() && point.getY() == a.getY()) \
		|| (point.getX() == b.getX() && point.getY() == b.getY()) \
		|| (point.getX() == c.getX() && point.getY() == c.getY()));
}

bool	isOnEdge(Fixed &areaPAB, Fixed &areaPBC, Fixed &areaPCA)
{
	return (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (isOnVertex(a, b, c, point)){
		std::cout << "The point is " << MAGENTA << "on a vertex.";
		std::cout << std::endl;
		return (false);
	}

	// Calculates the area of original triangle
	Fixed areaABC = triangleArea(a, b, c);
	
	// Calculates the area of sub-triangles (triangles formed considering two vertexes from the original triangle plus the point we want to analyse)
	Fixed areaPAB = triangleArea(point, a, b);
	Fixed areaPBC = triangleArea(point, b, c);
	Fixed areaPCA = triangleArea(point, c, a);

	std::cout << "areaPAB: " << areaPAB << std::endl;
	std::cout << "areaPBC: " << areaPBC <<std::endl;
	std::cout << "areaPCA: " << areaPCA << std::endl;

	if (isOnEdge(areaPAB, areaPBC, areaPCA))
	{
		std::cout << "The point is " << MAGENTA << "on an edge.";
		std::cout << std::endl;
		return (false);
	}

	// Sums up all the sub-triangle areas. If the totalArea is equal to area ABC, it means the point is inside the triangle.
	Fixed totalArea = areaPAB + areaPBC + areaPCA;
	
	if (areaABC == totalArea)
	{
		std::cout << "The point is " << GREEN << "inside ";
		std::cout << RST << "the triangle." << std::endl;
		return (true);
	}
	else {
		std::cout << "The point is " << MAGENTA << "outside ";
		std::cout << RST << "the triangle." << std::endl;
		return (false);
	}
}