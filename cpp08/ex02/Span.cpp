/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 12:59:19 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/30 11:40:06 by rivoinfo         ###   ########.fr       */
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
    if (_numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers to calculate span");
    
    std::vector<int> tmp(_numbers);
    std::sort(tmp.begin(), tmp.end());
    
    int minSpan = tmp[1] - tmp[0];
    for (size_t i = 2; i < tmp.size(); ++i) {
        minSpan = std::min(minSpan, tmp[i] - tmp[i-1]);
    }
    return (minSpan);
}


 int  Span::longestSpan() const
{
    if (_numbers.size() <= 1)
    {
        throw std::runtime_error("Not enough numbers to calculate span");
    }
    
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}