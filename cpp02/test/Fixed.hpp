/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:59:50 by rhanitra          #+#    #+#             */
/*   Updated: 2025/03/30 12:54:11 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <cstdint>
# include <cstdlib>
# include <cmath>
# include <iostream>
# include <cstring>

class Fixed
{
private:
    int     _fixePointNumber);
    static const int val;
    char*   _name;  // Nouveau membre pour stocker le nom

public:
    Fixed();
    Fixed(const Fixed& copy);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const int value, const char* name);
    Fixed(const float value, const char* name);
    ~Fixed();

    Fixed& operator=(const Fixed& assign);
    float toFloat() const;
    int toInt() const;
    
    int getRawBits() const;
    void setRawBits(int const raw);
    
    const char* getName() const;
    void setName(const char* newName);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif