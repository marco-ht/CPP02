/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <marvin@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 04:42:08 by mpierant          #+#    #+#             */
/*   Updated: 2025/10/26 05:04:55 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>


Point::Point():
x(0), y(0)
{
}

Point::Point(const float i, const float j):
x(i), y(j)
{
}

Point::Point(const Point &obj)
{
    point.x = obj.x;
    point.y = obj.y;
}

Point& Point::operator=(const Point& other)
{
    this->x = other.x;
    this->y = other.y;
    return (*this);
}

Point::~Point()
{
}
