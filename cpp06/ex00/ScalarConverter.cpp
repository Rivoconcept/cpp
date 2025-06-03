/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:40:49 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/03 18:24:52 by rhanitra         ###   ########.fr       */
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

void ScalarConverter::fromChar(const std::string& literal)
{
    char c = literal[0];

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::fromInt(const std::string& literal) {
    long num = std::strtol(literal.c_str(), nullptr, 10);

    if (num < CHAR_MIN || num > CHAR_MAX)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(num)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;

    if (num < INT_MIN || num > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(num) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void ScalarConverter::fromFloat(const std::string& literal) {
    float f = std::strtof(literal.c_str(), NULL);

    if (std::isnan(f) || f < CHAR_MIN || f > CHAR_MAX)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(f)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

    if (std::isnan(f) || f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::fromDouble(const std::string& literal) {
    double d = std::strtod(literal.c_str(), NULL);

    if (std::isnan(d) || d < CHAR_MIN || d > CHAR_MAX)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    if (std::isnan(d) || d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    typedef bool (*Checker)(const std::string&);
    typedef void (*Converter)(const std::string&);

    Checker checkers[] = {
        &ScalarConverter::isCharLiteral,
        &ScalarConverter::isIntLiteral,
        &ScalarConverter::isFloatLiteral,
        &ScalarConverter::isDoubleLiteral
    };

    Converter converters[] = {
        &ScalarConverter::fromChar,
        &ScalarConverter::fromInt,
        &ScalarConverter::fromFloat,
        &ScalarConverter::fromDouble
    };

    for (int i = 0; i < 4; ++i)
    {
        if (checkers[i](literal))
        {
            converters[i](literal);
            return;
        }
    }

    std::cout << "Conversion type unknown or invalid literal" << std::endl;
}



/*void ScalarConverter::convert(const std::string& literal)
{
     const std::string fConvert[] = {};

    bool (*functions[])(const std::string&) = {
        &ScalarConverter::isCharLiteral, 
        &ScalarConverter::isIntLiteral, 
        &ScalarConverter::isFloatLiteral,
        &ScalarConverter::isDoubleLiteral
    };

    for (int i = 0; i < 3; ++i)
    {
        if (literal == fConvert[i])
        {

            return (functions[i]());
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
}*/
