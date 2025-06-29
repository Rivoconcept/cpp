/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 12:59:19 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/29 17:08:07 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;   
    }
    return (*this);
}

Span::~Span() {}


unsigned int Span::getMaxSize() const
{
    return (_maxSize);
}

void Span::addNumber(int n)
{
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Cannot add more numbers: Span is full.");
        
    _numbers.push_back(n);
}


int Span::shortestSpan() const
{
    int dif = 2147483647;
    int tmp;

    if (_numbers.size() <= 1 )
        throw std::runtime_error("Can't find the difference between two numbers!");
        
    for (unsigned int i = 0; i < _maxSize; i++)
    {
        if (_numbers[i] > _numbers[i + 1])
            tmp = _numbers[i] - _numbers[i + 1];
        else
            tmp = _numbers[i + 1] - _numbers[i];
        if (tmp < dif)
            dif = tmp;
    }
    return (dif);
}

int Span::longestSpan() const
{
    int dif = 0;
    int tmp;

    if (_numbers.size() <= 1)
        throw std::runtime_error("Can't find the difference between two numbers!");
    
    for (unsigned int i = 0; i < _maxSize; i++)
    { 
        if (_numbers[i] > _numbers[i + 1])
            tmp = _numbers[i] - _numbers[i + 1];
        else if (_numbers[i] < _numbers[i + 1])
            tmp = _numbers[i + 1] - _numbers[i];
        if (tmp > dif)
            dif = tmp;
    }
    return (dif);
}