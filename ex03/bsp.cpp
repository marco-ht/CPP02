/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <marvin@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 04:42:23 by mpierant          #+#    #+#             */
/*   Updated: 2025/10/26 20:30:34 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed w1;
    Fixed w2;

    Fixed D = (b.gx() - a.gx()) * (c.gy() - a.gy())
                - (c.gx() - a.gx()) * (b.gy() - a.gy());
    if (D == Fixed(0))
    {
        std::cout << "Error: triangle vertices overlaped" << std::endl;
        return (0);
    }
    w1 = ((point.gx() - a.gx()) * (c.gy() - a.gy())
                - (point.gy() - a.gy()) * (c.gx() - a.gx())) / D;
    w2 = ((b.gx() - a.gx()) * (point.gy() - a.gy())
                - (b.gy() - a.gy()) * (point.gx() - a.gx())) / D;
    /* std::cout << "w1 = " << w1 << std::endl;
    std::cout << "w2 = " << w2 << std::endl; */
    if (w1 > Fixed(0) && w2 > Fixed(0) && w1 + w2 < Fixed(1))
        return (true);
    return (false);
}
