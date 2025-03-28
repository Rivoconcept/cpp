/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:59:50 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/28 19:03:57 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <cstdint>
# include <cstdlib>
# include <cmath>
# include <iostream>
# include <string>

class Fixed
{
    private:
        int     _fixePointNumberValue;
        static const int _mantissa;
 

    public:
        Fixed();
        Fixed(const Fixed& mantissa);
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();

        Fixed& operator=(const Fixed& asign);
        
        bool operator>(const Fixed& asign) const;
        bool operator<(const Fixed& asign) const;
        bool operator>=(const Fixed& asign) const;
        bool operator<=(const Fixed& asign) const;
        bool operator==(const Fixed& asign) const;
        bool operator!=(const Fixed& asign) const;

        Fixed operator+(const Fixed& asign) const;
        Fixed operator-(const Fixed& asign) const;
        Fixed operator*(const Fixed& asign) const;
        Fixed operator/(const Fixed& asign) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);


        float toFloat( void ) const;
        int toInt( void ) const;
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);

        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif