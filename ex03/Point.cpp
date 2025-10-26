/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <marvin@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 04:42:08 by mpierant          #+#    #+#             */
/*   Updated: 2025/10/26 19:47:05 by mpierant         ###   ########.fr       */
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

Point::Point(const Point &obj):
x(obj.x), y(obj.y)
{
}

Point& Point::operator=(const Point& other)
{
    //it doesn't modify Point because x and y are const
    std::cout << "x = " << other.x << ", y = " << other.y << " Not assigned. x and y are const (" << this->x << "," << this->y << ")!" << std::endl;
    return (*this);
}

Point::~Point()
{
}

bool Point::operator==(const Point& other) const{
    if(x == other.x && y == other.y)
        return(true);
    return (false);
}

Fixed Point::gx() const
{
    return (x);
}

Fixed Point::gy() const
{
    return (y);
}
