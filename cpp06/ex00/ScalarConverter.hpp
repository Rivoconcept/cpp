/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:00:42 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/03 18:20:13 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
//#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>

#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>


class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();
        
        static bool isFloatLiteral(const std::string&);
        static bool isDoubleLiteral(const std::string&);
        static bool isIntLiteral(const std::string&);
        static bool isCharLiteral(const std::string&);

        static void fromChar(const std::string&);
        static void fromInt(const std::string&);
        static void fromFloat(const std::string&);
        static void fromDouble(const std::string&);

    public:
        static void convert(const std::string& literal);

        class InvalidLiteralExecption : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
