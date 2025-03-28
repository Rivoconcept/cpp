/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:59:12 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/28 18:15:44 by rhanitra         ###   ########.fr       */
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
        this->_fixePointNumberValue = asign._fixePointNumberValue;
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

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixePointNumberValue = value << _mantissa;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixePointNumberValue = std::roundf(value * (1 << _mantissa));
}
float Fixed::toFloat( void ) const
{
    return (static_cast<float>( this->_fixePointNumberValue) / (1 << _mantissa));
}

int Fixed::toInt( void ) const
{
    return ( this->_fixePointNumberValue >> _mantissa);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}

