/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:59:50 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/30 13:14:16 by rhanitra         ###   ########.fr       */
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
        int     _fixePointNumber;
        static const int _val;  

    public:
        Fixed();
        Fixed(const Fixed& value);
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();

        Fixed& operator=(const Fixed& value);
        float toFloat( void ) const;
        int toInt( void ) const;
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif