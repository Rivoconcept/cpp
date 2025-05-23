/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:59:50 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/30 12:54:55 by rhanitra         ###   ########.fr       */
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
        int     _fixePointNumber;
        static const int val;  

    public:
        Fixed();
        Fixed(const Fixed& val);
        ~Fixed();

        Fixed& operator=(const Fixed& value);
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
};



#endif