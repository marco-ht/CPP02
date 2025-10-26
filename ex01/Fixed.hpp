/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <marvin@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 06:32:05 by mpierant          #+#    #+#             */
/*   Updated: 2025/10/26 02:20:29 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
    int fp;
    static const int P;
    
    public:
    Fixed();
    Fixed(const Fixed &obj);
    Fixed(const int i);
    Fixed(const float f);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    
    int getRawBits( void ) const;
    void    setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
