/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <marvin@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 22:55:40 by mpierant          #+#    #+#             */
/*   Updated: 2025/10/25 23:40:48 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

const int   Fixed::P = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    f = 0;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    f = obj.f;
}

Fixed& Fixed::operator=(Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    other.f = this->f;
    return(other);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (f);
}

void    Fixed::setRawBits( int const raw )
{
    f = raw;
}




//In Linux, il simbolo tilde (\(~\)) può essere digitato
// con la combinazione di tasti Alt Gr + ì
