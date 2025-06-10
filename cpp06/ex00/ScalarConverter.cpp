/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:40:49 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/10 15:48:57 by rivoinfo         ###   ########.fr       */
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

const char* ScalarConverter::InvalidLiteralExecption::what() const throw()
{
  return "Conversion type unknown or invalid literal";   
}



bool ScalarConverter::isCharLiteral(const std::string& str)
{
    return (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]));
}

bool ScalarConverter::isIntLiteral(const std::string& str)
{
    std::istringstream iss(str);
    long n;
    char extra;

    if (!(iss >> n))
        return false;

    if (iss >> extra)
        return false;

    if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
        return false;

    return true;
}

bool ScalarConverter::isFloatLiteral(const std::string& str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return true;

    if (str.empty() || str[str.length() - 1] != 'f')
        return false;

    std::string floatPart = str.substr(0, str.length() - 1);
    std::istringstream iss(floatPart);
    double d; 
    char c;

    if (!(iss >> d))
        return false;

    if (iss >> c)
        return false;

    if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
        return false;

    return true;
}

bool ScalarConverter::isDoubleLiteral(const std::string& str)
{
    if (str == "+inf" || str == "-inf" || str == "nan")
        return true;

    std::istringstream iss(str);
    double d;
    char c;

    if (!(iss >> d))
        return false;

    if (iss >> c)
        return false;

    return true;
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

void ScalarConverter::fromInt(const std::string& literal)
{
    std::istringstream iss(literal);
    int n;
    
    if (!(iss >> n) || !iss.eof())
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
        return;
    }
    iss >> n;
    if (n < std::numeric_limits<char>::min() || n > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(n)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;

    std::cout << "int: " << n << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(n) << std::endl;
}

void ScalarConverter::fromFloat(const std::string& literal)
{
    std::string value = literal;
    bool isSpecial = false;

    if (value == "+inff" || value == "-inff" || value == "nanf")
    {
        isSpecial = true;
        value = value.substr(0, value.length() - 1);
    }

    std::istringstream iss(value);
    float f;
    if (!(iss >> f) || !iss.eof())
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
        return;
    }

    if (std::isnan(f) || f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(f)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

    if (f < static_cast<float>(std::numeric_limits<int>::min()) ||
        f > static_cast<float>(std::numeric_limits<int>::max()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    if (isSpecial && (f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max()))
        std::cout << "float: " << literal << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::fromDouble(const std::string& literal)
{
    std::string value = literal;
    bool isSpecial = false;

    if (value == "+inf" || value == "-inf" || value == "nan")
        isSpecial = true;

    std::istringstream iss(value);
    double d;
    if (!(iss >> d) || !iss.eof())
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
        return;
    }

    if (std::isnan(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    if (d < static_cast<double>(std::numeric_limits<int>::min()) ||
        d > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
    {
        float f = static_cast<float>(d);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
    }

    std::cout << std::fixed << std::setprecision(1);
    if (isSpecial)
        std::cout << "double: " << value << std::endl;
    else
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

    throw ScalarConverter::InvalidLiteralExecption();
}

