/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <marvin@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 04:41:57 by mpierant          #+#    #+#             */
/*   Updated: 2025/10/26 19:22:38 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
    const Fixed     x;
    const Fixed     y;
    
    public:
    Point();
    Point(const float i, const float j);
    Point(const Point &obj);
    Point& operator=(const Point& other);
    ~Point();

    bool operator==(const Point& other) const;

    Fixed gx() const;
    Fixed gy() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif