/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:40:49 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/01 15:21:07 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    void*(other);
}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    void*(other);
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    void*(other);
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string& str) {
    return str.length() == 1 && !std::isdigit(str[0]);
}

static bool isFloat(const std::string& str) {
    if (str == "-inff" || str == "+inff" || str == "nanf") return true;
    char* end;
    std::strtof(str.c_str(), &end);
    return (*end == 'f' && *(end + 1) == '\0');
}

static bool isDouble(const std::string& str) {
    if (str == "-inf" || str == "+inf" || str == "nan") return true;
    char* end;
    std::strtod(str.c_str(), &end);
    return *end == '\0';
}

static bool isInt(const std::string& str) {
    char* end;
    std::strtol(str.c_str(), &end, 10);
    return *end == '\0';
}

void ScalarConverter::convert(const std::string& literal)
{
     const std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    AForm* (*functions[])(const std::string&) = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};

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
