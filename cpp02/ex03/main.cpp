/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/06 22:25:28 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Point.hpp"

int main(void) 
{
	Point a(0.0f, 0.0f);
	Point b(3.5f, 6.5f);
	Point c(6.5f, 0.5f);
	Point point1(0.0f, 0.0f); // On vertex a
	Point point2(7.0f, 6.5f); // Outside the triangle
	Point point3(3.5f, 3.0f); // Inside the triangle
	Point point4((3.5f + 6.5f) / 2, (6.5f + 0.5f) / 2);// On the edge between b and c (midpoint)

	std::cout << "a is located at: " << a << std::endl;
	std::cout << "b is located at: " << b << std::endl;
	std::cout << "c is located at: " << c << std::endl;

	std::cout << YELLOW << "\n=== Testing point1 ===" << std::endl;
	std::cout << RST << "point1 is located at: " << point1 << std::endl;
	bsp(a, b, c, point1);
	std::cout << YELLOW << "\n=== Testing point2 ===" << std::endl;
	std::cout << RST << "point2 is located at: " << point2 << std::endl;
	bsp(a, b, c, point2);
	std::cout << YELLOW << "\n=== Testing point3 ===" << std::endl;
	std::cout << RST << "point3 is located at: " << point3 << std::endl;
	bsp(a, b, c, point3);
	std::cout << YELLOW << "\n=== Testing point4 ===" << std::endl;
	std::cout << RST << "point3 is located at: " << point4 << std::endl;
	bsp(a, b, c, point4);
	return 0;
}