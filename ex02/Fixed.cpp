/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <marvin@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 22:55:40 by mpierant          #+#    #+#             */
/*   Updated: 2025/10/26 04:36:33 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int   Fixed::P = 8;

Fixed::Fixed()
{
    //std::cout << "Default constructor called" << std::endl;
    fp = 0;
}

Fixed::Fixed(const Fixed &obj)
{
    //std::cout << "Copy constructor called" << std::endl;
    fp = obj.fp;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    this->fp = other.fp;
    return (*this);
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (fp);
}

void    Fixed::setRawBits( int const raw )
{
    //std::cout << "setRawBits member function called" << std::endl;
    fp = raw;
}

Fixed::Fixed(const int i)
{
    //std::cout << "Int constructor called" << std::endl;
    fp = i * (1 << P);
}

Fixed::Fixed(const float f)
{
    //std::cout << "Float constructor called" << std::endl;
    fp = (int)roundf(f * (1 << P));
    /* std::cout << "f is " << f << std::endl;
std::cout << "(1 << P) is " << (1 << P) << std::endl;
std::cout << "(f * (1 << P)) is " << (f * (1 << P)) << std::endl;
std::cout << "roundf(f * (1 << P) is " << roundf(f * (1 << P)) << std::endl;
std::cout << "(int)roundf(f * (1 << P)) is " << (int)roundf(f * (1 << P)) << std::endl; */
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

// comparison operators

bool Fixed::operator>(const Fixed& other) {
  return fp > other.fp;
}

bool Fixed::operator<(const Fixed& other) {
  return fp < other.fp;
}

bool Fixed::operator>=(const Fixed& other) {
  return fp >= other.fp;
}

bool Fixed::operator<=(const Fixed& other) {
  return fp <= other.fp;
}

bool Fixed::operator==(const Fixed& other) {
  return fp == other.fp;
}

bool Fixed::operator!=(const Fixed& other) {
  return !(*this == other);
}

// arithmetic operators

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed res;
    
    res.fp = this->fp + other.fp;
    return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed res;
    
    res.fp = this->fp - other.fp;
    return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed res;
    
    res.fp = (this->fp * other.fp) / (1 << P);
    return (res);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed   res;
    
    res.fp = ((this->fp * (1 << P)) / other.fp);
    return (res);
}

// increment and decrement operator

//preincrement (returned value should be a reference to *this)
Fixed& Fixed::operator++()
{
    ++fp;
    return (*this);
}

//postincrement (returned value should be a copy of the object before increment)
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++fp;
    return temp;
}

//predecrement (returned value should be a reference to *this)
Fixed& Fixed::operator--()
{
    --fp;
    return (*this);
}

//postdecrement (returned value should be a copy of the object before decrement)
Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --fp;
    return temp;
}

//min e max function
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a.fp < b.fp)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.fp < b.fp)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a.fp > b.fp)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.fp > b.fp)
        return (a);
    return (b);
}
