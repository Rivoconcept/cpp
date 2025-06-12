#include "ScalarConverter.hpp"

void ScalarConverter::fromDouble(const std::string& literal)
{
    std::cout << "from double" << std::endl;

    double d;
    std::istringstream iss(literal);
    if (!(iss >> d))
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
        return;
    }

    // CHAR
    if (std::isnan(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    // INT
    if (std::isnan(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    // FLOAT
    std::cout << std::fixed << std::setprecision(1);
    if (std::isnan(d))
        std::cout << "float: nanf" << std::endl;
    else if (d == std::numeric_limits<double>::infinity())
        std::cout << "float: inff" << std::endl;
    else if (d == -std::numeric_limits<double>::infinity())
        std::cout << "float: -inff" << std::endl;
    else if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

    // DOUBLE
    if (std::isnan(d))
        std::cout << "double: nan" << std::endl;
    else if (d == std::numeric_limits<double>::infinity())
        std::cout << "double: inf" << std::endl;
    else if (d == -std::numeric_limits<double>::infinity())
        std::cout << "double: -inf" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void ScalarConverter::fromDouble(const std::string& literal)
{
    std::string value = literal;
    bool isSpecial = false;
    std::cout << "from double" << std::endl;
    if (value == "+inf" || value == "-inf" || value == "nan")
        isSpecial = true;

    std::istringstream iss(value);
    double d;
    if (!(iss >> d))
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
