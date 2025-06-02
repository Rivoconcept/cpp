/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:40:49 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/02 16:08:27 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { *this = other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
     (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isCharLiteral(const std::string& str)
{
    return (str.length() == 1 && !std::isdigit(str[0]));
}

bool ScalarConverter::isFloatLiteral(const std::string& str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return true;

    try
    {
        size_t pos;
        std::stof(str, &pos);
        return (str.back() == 'f' && pos == str.length() - 1);
    }
    catch (...)
    {
        return false;
    }
}


bool ScalarConverter::isDoubleLiteral(const std::string& str)
{
    if (str == "-inf" || str == "+inf" || str == "nan")
        return true;

    try
    {
        size_t pos;
        std::stod(str, &pos);
        return (pos == str.length());
    }
    catch (...)
    {
        return false;
    }
}


bool ScalarConverter::isIntLiteral(const std::string& str)
{
    try
    {
        size_t pos;
        std::stoi(str, &pos);
        return (pos == str.length());
    } 
    catch (...)
    {
        return false;
    }
}


void ScalarConverter::convert(const std::string& literal)
{
     const std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    bool (*functions[])(const std::string&) = {
        &ScalarConverter::isCharLiteral, 
        &ScalarConverter::isIntLiteral, 
        &ScalarConverter::isFloatLiteral,
        &ScalarConverter::isDoubleLiteral
    };

    for (int i = 0; i < 3; ++i)
    {
        if (form == names[i])
        {
            std::cout << "Intern creates " << form << std::endl;
            return (functions[i](target));
        }
    }
    
    char c = 0;
    int i = 0;
    float f = 0;
    double d = 0;

    // Detect type
    if (isChar(literal)) {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } else if (isInt(literal)) {
        i = std::atoi(literal.c_str());
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    } else if (isFloat(literal)) {
        f = std::strtof(literal.c_str(), nullptr);
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
    } else if (isDouble(literal)) {
        d = std::strtod(literal.c_str(), nullptr);
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
    } else {
        std::cout << "Error: invalid literal" << std::endl;
        return;
    }

    // CHAR
    std::cout << "char: ";
    if (std::isnan(d) || d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;

    // INT
    std::cout << "int: ";
    if (std::isnan(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;

    // FLOAT
    std::cout << "float: ";
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    // DOUBLE
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}
