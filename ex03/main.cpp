/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <marvin@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 23:33:52 by mpierant          #+#    #+#             */
/*   Updated: 2025/10/26 20:28:16 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void )
{
    Point   a(0.0f, 0.0f);
    Point   b(0.0f, 10.0f);
    Point   c(10.0f, 0.0f);
    Point   p1(0.0f, 10.0f);
    Point   p2(10.0f, 0.0f);

    /*
    assigning like this not possible
    because x and y are const */
    a = Point(10.0f, 20.0f);

    std::cout << "p1(" << p1.gx() << ", " << p1.gy() << ") " << std::endl;
    std::cout << (bsp( a, b, c, p1) ? "inside" : "not inside (or error)") << std::endl;
    
    std::cout << "p2(" << p2.gx() << ", " << p2.gy() << ") " << std::endl;
    std::cout << (bsp( a, b, c, p2) ? "inside" : "not inside (or error)") << std::endl;

    std::cout << std::endl << std::endl;;
    
    Point   a1(1.0f, 1.0f);
    Point   b1(6.0f, 10.0f);
    Point   c1(11.0f, 1.0f);
    Point   p11(6.0f, 6.0f);
    Point   p21(11.0f, 6.0f);

    std::cout << "p1(" << p11.gx() << ", " << p11.gy() << ") " << std::endl;
    std::cout << (bsp( a1, b1, c1, p11) ? "inside" : "not inside (or error)") << std::endl;
    
    std::cout << "p2(" << p21.gx() << ", " << p21.gy() << ") " << std::endl;
    std::cout << (bsp( a1, b1, c1, p21) ? "inside" : "not inside (or error)") << std::endl;

    std::cout << std::endl << std::endl;;
    
    Point   a2(10.0f, 1.0f);
    Point   b2(5.0f, 10.0f);
    Point   c2(10.0f, 1.0f);
    Point   p12(5.0f, 5.0f);
    Point   p22(10.0f, 0.0f);

    std::cout << "p1(" << p12.gx() << ", " << p12.gy() << ") " << std::endl;
    std::cout << (bsp( a2, b2, c2, p12) ? "inside" : "not inside (or error)") << std::endl;
    
    std::cout << "p2(" << p22.gx() << ", " << p22.gy() << ") " << std::endl;
    std::cout << (bsp( a2, b2, c2, p22) ? "inside" : "not inside (or error)") << std::endl;
}
