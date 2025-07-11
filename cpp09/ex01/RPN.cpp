/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:02:57 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/11 15:58:37 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string& argv) : _operand()
{
    std::istringstream iss(argv);
    std::string token;

    while (std::getline(iss, token, ' '))
    {
        if (!token.empty())
            _argv.push((token));
    }  

    /*while (iss >> token)
    {
        if (!token.empty())
            _argv.push(token);
    }*/

    for (int i = 0; i != _argv.size(); ++i)
    {
        std::cout << _argv[i] << std::endl;
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
        _operand = other._operand;
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
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        if (!std::isdigit(*it))
        {
            return false;
        }
    }
    return !str.empty();
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
    // size_t numCount = 0;
    
    for (MutantStack<std::string>::const_iterator it = _argv.begin(); it != _argv.end(); ++it)
    {
        std::string arg = *it;
        
        if (it == _argv.begin() && isOperator(arg))
            throw std::runtime_error("Operator at start");
        
        if (arg == "0" && it != _argv.begin())
        {
            MutantStack<std::string>::const_iterator prev = it;
            --prev;
            if (*prev == "/")
                throw std::runtime_error("Division by zero");
        }

        if (arg.find_first_of("()") != std::string::npos)
            throw std::runtime_error("Parentheses not allowed in RPN");
        
        if (isOperator(arg))
            opCount++;
    }

    
    if (opCount == 0)
        throw GeneralException();

    if (opCount != static_cast<int>(_argv.size()) - 1)
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

    MutantStack<std::string> rpn = calc.getArgv();


    for (MutantStack<std::string>::const_iterator it = rpn.begin(); it != rpn.end(); ++it)
    {
        std::string arg = *it;
        
        std::cout << *it << " ";

    }
    std::cout << std::endl;
      
}
