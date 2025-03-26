/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:59:50 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/26 18:24:01 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <cstdint>
# include <cstdlib>
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
        ~Fixed();

        Fixed& operator=(const Fixed& asign);
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
};



#endif