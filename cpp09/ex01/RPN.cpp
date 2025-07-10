/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:02:57 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/10 20:13:19 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string& argv) : _operand()
{
    _operator.push("+");
    _operator.push("-");
    _operator.push("/");
    _operator.push("*");

    std::istringstream iss(argv);
    std::string token;
    
    while (iss >> token)
    {
        if (!token.empty())
            _arg.push(token);
    }
}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        _arg = other._arg;
        _operator = other._operator;
        _operand = other._operand;
    }
    return (*this);
}

RPN::~RPN() {}

bool RPN::isNumeric(const std::string &str)
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        if (!std::isdigit(*it))
        {
            return false;
        }
    }
    return !str.empty();
}

bool RPN::isOperator(const std::string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

void RPN::handleError(void) const
{
    for (MutantStack<std::string>::const_iterator it = _arg.begin(); it != _arg.end(); ++it)
    {
        std::string arg = *it;
        if (it == _arg.begin() && isOperator(arg))
        {
                throw std::runtime_error("Error: invalid token '" + arg + "'");
        }
    }
}

float RPN::fromFloat(const std::string& literal)
{
    std::istringstream iss(literal);
    float f;
    double d;

    if (!(iss >> d))
        throw std::runtime_error("Conversion to float: impossible");
        
    if (d < 0 || d > 9)
        throw std::runtime_error("not a number in range.");
    
    f = static_cast<float>(d);

    if (std::isinf(f) || d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
       return (f > 0 ? std::numeric_limits<float>::infinity() : -std::numeric_limits<float>::infinity());
    else if (std::isnan(f))
        return std::numeric_limits<float>::quiet_NaN();
    
    return (f);
}

void runRPN(const std::string& argv)
{
    RPN rpn(argv);

    rpn.handleError();
    
    /*std::istringstream iss(argv);
    std::string token;
    double n;
    
    while (std::getline(iss, token, ' '))
    {
        if (!token.empty())
        {
            if (std::isdigit(token))
            {
                
            }
            else
                n = rpn.fromFloat(token);

            
            output.push(static_cast<float>(n));
        }
    }*/
      
}
