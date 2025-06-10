/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:00:42 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/10 08:38:12 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <stdexcept>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();
        
        static bool isCharLiteral(const std::string&);
        static bool isIntLiteral(const std::string&);
        static bool isFloatLiteral(const std::string&);
        static bool isDoubleLiteral(const std::string&);

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
