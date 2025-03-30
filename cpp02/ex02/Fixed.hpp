/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:59:50 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/30 14:15:10 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <cmath>
# include <cstdint>
# include <cstdlib>
# include <iostream>
# include <string>

class Fixed
{
  private:
	int _fixePointNumber;
	static const int _val;

  public:
	Fixed();
	Fixed(const Fixed &value);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();

	Fixed &operator=(const Fixed &value);

	bool operator>(const Fixed &value) const;
	bool operator<(const Fixed &value) const;
	bool operator>=(const Fixed &value) const;
	bool operator<=(const Fixed &value) const;
	bool operator==(const Fixed &value) const;
	bool operator!=(const Fixed &value) const;

	Fixed operator+(const Fixed &value) const;
	Fixed operator-(const Fixed &value) const;
	Fixed operator*(const Fixed &value) const;
	Fixed operator/(const Fixed &value) const;

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	float toFloat(void) const;
	int toInt(void) const;

	int getRawBits(void) const;
	void setRawBits(int const raw);

	static const Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static const Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif