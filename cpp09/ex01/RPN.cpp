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

        if (!isNumeric(arg) && !isOperator(arg))
            throw std::runtime_error("token is not valid");
        
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

    MutantStack<std::string> rpn = calc.getArgv();


    for (MutantStack<std::string>::const_iterator it = rpn.begin(); it != rpn.end(); ++it)
    {
        std::string arg = *it;
        
        std::cout << *it << " ";

    }
    std::cout << std::endl;
      
}

double evaluateRPN(const std::string& expr) {
    std::stack<double> stack;
    std::string token;
    size_t pos = 0;

    while ((pos = expr.find(' ')) != std::string::npos) {
        token = expr.substr(0, pos);
        expr.erase(0, pos + 1);

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                std::cerr << "Erreur : Pas assez d'opérandes pour '" << token << "'\n";
                return NAN; // Not a Number
            }
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            
            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") stack.push(a / b); // /0 → ±inf
        } 
        else {
            stack.push(std::stod(token)); // Convertit en double
        }
    }

    if (stack.size() != 1) {
        std::cerr << "Erreur : Expression invalide (trop d'opérandes)\n";
        return NAN;
    }
    return stack.top();
}

int main() {
    std::string expr = "5 2 / 3 * 1 +"; // (5/2)*3 + 1 = 8.5
    double result = evaluateRPN(expr);
    std::cout << "Résultat : " << result << "\n"; // 8.5

    // Test avec division par zéro
    std::string expr2 = "1 0 /"; // inf
    std::cout << "1 / 0 = " << evaluateRPN(expr2) << "\n"; // inf

    return 0;
}