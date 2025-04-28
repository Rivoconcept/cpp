/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:59:12 by rhanitra          #+#    #+#             */
/*   Updated: 2025/04/27 14:32:25 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixePointNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

const int Fixed::_val = 8;

Fixed::Fixed(const Fixed& value)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = value;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& value)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &value)
    {
        this->_fixePointNumber = value._fixePointNumber;
    }
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixePointNumber);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixePointNumber = raw;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixePointNumber = value << _val;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixePointNumber = std::roundf(value * (1 << _val));
}
float Fixed::toFloat( void ) const
{
    return ((float)this->_fixePointNumber / (1 << _val));
}

int Fixed::toInt( void ) const
{
    return ( this->_fixePointNumber >> _val);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}

