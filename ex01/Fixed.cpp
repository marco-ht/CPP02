/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <marvin@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 22:55:40 by mpierant          #+#    #+#             */
/*   Updated: 2025/10/26 02:25:20 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int   Fixed::P = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    fp = 0;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    fp = obj.fp;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fp = other.fp;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fp);
}

void    Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    fp = raw;
}

Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
    fp = i * (1 << P);
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    fp = (int)roundf(f * (1 << P));
}

float Fixed::toFloat( void ) const
{
    return (((float)(fp)) / (1 << P));
}

int Fixed::toInt( void ) const
{
    return (fp / (1 << P));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat(); 
    return os;
}



/* std::cout << "f is " << f << std::endl;
std::cout << "(1 << P) is " << (1 << P) << std::endl;
std::cout << "(f * (1 << P)) is " << (f * (1 << P)) << std::endl;
std::cout << "roundf(f * (1 << P) is " << roundf(f * (1 << P)) << std::endl;
std::cout << "(int)roundf(f * (1 << P)) is " << (int)roundf(f * (1 << P)) << std::endl; */