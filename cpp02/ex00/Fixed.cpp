/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:59:12 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/26 18:45:36 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixePointNumberValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

const int Fixed::_mantissa = 8;

Fixed::Fixed(const Fixed& mantissa)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = mantissa;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& asign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &asign)
    {
        this->_fixePointNumberValue = asign.getRawBits();
    }
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixePointNumberValue);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixePointNumberValue = raw;
}


