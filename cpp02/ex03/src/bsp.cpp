/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:11:53 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/05 21:55:06 by lsampiet         ###   ########.fr       */
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

bool	checkVertexes(Point const &a, Point const &b, Point const &c, Point const &point) {
	if ((point.getX() == a.getX() && point.getY() == a.getY()) \
		|| (point.getX() == b.getX() && point.getY() == b.getY()) \
		|| (point.getX() == c.getX() && point.getY() == c.getY()))
		return true;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (checkVertexes)
		return (false);
	// Calculates the area of original triangle
	Fixed areaABC = triangleArea(a, b, c);

	// Calculates the area of sub-triangles (triangles formed considering two vertexes from the original triangle plus the point we want to analyse)
	Fixed areaPAB = triangleArea(point, a, b);
	Fixed areaPBC = triangleArea(point, b, c);
	Fixed areaPCA = triangleArea(point, c, a);

	// Sums up all the sub-triangle areas. If the totalArea is equal to area ABC, it means the point is inside the triangle.
	Fixed totalArea = areaPAB + areaPBC + areaPCA;

	// Verifica se são iguais (considerando possível imprecisão)
	return (areaABC == totalArea);
}