/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:59:12 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/30 12:55:19 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixePointNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

const int Fixed::val = 8;

Fixed::Fixed(const Fixed& val)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = val;
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
        this->_fixePointNumber = value.getRawBits();
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


