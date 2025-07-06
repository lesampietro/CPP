/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:44:38 by lsampiet          #+#    #+#             */
/*   Updated: 2025/07/06 15:58:02 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;
public:
	Point();
	Point(const float first, const float scnd);
	Point(const Point &copy);
	Point &operator=(const Point &other);
	~Point();

	Fixed	getX() const;
	Fixed	getY() const;
};

std::ostream &operator<<(std::ostream &out, const Point &point);
bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
