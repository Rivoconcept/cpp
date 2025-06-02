/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:00:42 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/02 15:41:16 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
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

    public:
        static void convert(const std::string& literal);

        class InvalidLiteralExecption : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
