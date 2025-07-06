/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:01:18 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/06 16:57:44 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Point.hpp"

int main(void) 
{
	Point a(0, 0);
	Point b(2, 4);
	Point c(4, 0);
	Point point1(2, 6);

	std::cout << "a is located at: " << a << std::endl;
	std::cout << "b is located at: " << b << std::endl;
	std::cout << "c is located at: " << c << std::endl;
	std::cout << "point1 is located at: " << point1 << std::endl;
	bsp(a, b, c, point1);
	return 0;
}