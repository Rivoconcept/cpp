/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:02:57 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/13 11:18:35 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string& argv)
{
    
    std::istringstream iss(argv);
    std::string token;

    while (iss >> token)
    {
        _argv.push(token);
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
        _argv = other._argv;
    }
    return (*this);
}

RPN::~RPN() {}

std::string& RPN::operator[](unsigned int index)
{
    return _argv[index];
}

const std::string& RPN::operator[](unsigned int index) const
{
    return _argv[index];
}
const MutantStack<std::string>& RPN::getArgv() const
{
    return (_argv);
}

bool RPN::isNumeric(const std::string &str)
{
    std::istringstream iss(str);
    float f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}

const char* RPN::GeneralException::what() const throw()
{
    return ("impossible operation");
}

bool RPN::isOperator(const std::string& token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

void RPN::handleError(void) const
{
    
    if (_argv.empty())
        throw GeneralException();
    
    int opCount = 0;
    int numCount = 0;
    
    for (MutantStack<std::string>::const_iterator it = _argv.begin(); it != _argv.end(); ++it)
    {
        std::string arg = *it;
        
        if (it == _argv.begin() && isOperator(arg))
            throw std::runtime_error("Operator at start");

        if (arg.find_first_of("()") != std::string::npos)
            throw std::runtime_error("Parentheses not allowed in RPN");

        if (!isNumeric(arg) && !isOperator(arg))
            throw std::runtime_error("token is not valid");
        
        if (isOperator(arg))
            opCount++;
        else
            numCount++;
    }

    if (opCount == 0)
        throw GeneralException();

    if (opCount != numCount - 1)
    {
        std::cout << _argv.size() << std::endl;
        throw std::runtime_error("Invalid operator/operand ratio");
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
    
    return (f);
}

void runRPN(const std::string& argv)
{
    RPN calc(argv);

    calc.handleError();

    MutantStack<std::string> expression = calc.getArgv();
    std::stack<float> rpn;
    float a;
    float b;
    
    for (MutantStack<std::string>::const_iterator it = expression.begin(); it != expression.end(); ++it)
    {
        std::string arg = *it;

        if (arg == "+" || arg == "-" || arg == "*" || arg == "/")
        {
            if (rpn.size() < 2)
                throw RPN::GeneralException();
                
            b = rpn.top(); rpn.pop();
            a = rpn.top(); rpn.pop();
            
            if (arg == "+")
                rpn.push(a + b);
            else if(arg == "-")
                rpn.push(a - b);
            else if (arg == "*")
                rpn.push(a * b);
            else if (arg == "/")
                rpn.push(a / b);
        } 
        else
            rpn.push(calc.fromFloat(arg));
    }
    
    if (rpn.size() != 1)
        throw RPN::GeneralException();
        
    std::cout << rpn.top() << std::endl;   
}
