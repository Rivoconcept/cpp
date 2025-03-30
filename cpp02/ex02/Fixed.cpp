/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:59:12 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/30 14:13:12 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixePointNumber(0) {}

const int Fixed::_val = 8;

Fixed::Fixed(const Fixed &value)
{
	*this = value;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &value)
{
	if (this != &value)
	{
		this->_fixePointNumber = value._fixePointNumber;
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_fixePointNumber);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixePointNumber = raw;
}

Fixed::Fixed(const int value)
{
	this->_fixePointNumber = value << _val;
}

Fixed::Fixed(const float value)
{
	this->_fixePointNumber = std::roundf(value * (1 << _val));
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixePointNumber / (1 << _val));
}

int Fixed::toInt(void) const
{
	return (this->_fixePointNumber >> _val);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &value) const
{
	return (this->_fixePointNumber > value._fixePointNumber);
}

bool Fixed::operator<(const Fixed &value) const
{
	return (this->_fixePointNumber < value._fixePointNumber);
}

bool Fixed::operator>=(const Fixed &value) const
{
	return (this->_fixePointNumber >= value._fixePointNumber);
}

bool Fixed::operator<=(const Fixed &value) const
{
	return (this->_fixePointNumber <= value._fixePointNumber);
}

bool Fixed::operator==(const Fixed &value) const
{
	return (this->_fixePointNumber == value._fixePointNumber);
}

bool Fixed::operator!=(const Fixed &value) const
{
	return (this->_fixePointNumber != value._fixePointNumber);
}

Fixed Fixed::operator+(const Fixed &value) const
{
	return (Fixed(this->toFloat() + value.toFloat()));
}

Fixed Fixed::operator-(const Fixed &value) const
{
	return (Fixed(this->toFloat() - value.toFloat()));
}

Fixed Fixed::operator*(const Fixed &value) const
{
	return (Fixed(this->toFloat() * value.toFloat()));
}

Fixed Fixed::operator/(const Fixed &value) const
{
	if (value._fixePointNumber == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / value.toFloat()));
}

const Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return ((a < b) ? a : b);
}

const Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return ((a > b) ? a : b);
}

Fixed &Fixed::operator++()
{
	_fixePointNumber++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	_fixePointNumber++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	_fixePointNumber--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	_fixePointNumber--;
	return (temp);
}
