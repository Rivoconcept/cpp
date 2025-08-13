/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:55:48 by rhanitra          #+#    #+#             */
/*   Updated: 2025/08/12 18:09:44 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
# include <string>
#include <sstream>
# include <fstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <stack>

template <typename T>
class MutantStack
{
    private:
        T* _data;
        size_t _size;
        size_t _capacity;

        void _reserve(size_t newCapacity);
        
    public:
        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        typedef T* iterator;
        typedef const T* const_iterator;
        typedef T* reverse_iterator;
        typedef const T* const_reverse_iterator;
        
        void push_back(const T& value);
        void pop_back();
        T& back();
        const T& back() const;
        size_t size() const;
        bool empty() const;
        
        T& operator[](size_t index);
        const T& operator[](size_t index) const;

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
};

template <typename T>
MutantStack<T>::MutantStack() : _data(NULL), _size(0), _capacity(0) {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : _data(NULL), _size(0), _capacity(0)
{
    *this = other;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    if (this != &other)
    {
        delete[] _data;
        
        _size = other._size;
        _capacity = other._capacity;
        _data = new T[_capacity];
        
        for (size_t i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    delete[] _data;
}

template <typename T>
void MutantStack<T>::_reserve(size_t newCapacity)
{
    if (newCapacity <= _capacity)
        return;
        
    T* newData = new T[newCapacity];
    
    for (size_t i = 0; i < _size; ++i)
        newData[i] = _data[i];
        
    delete[] _data;
    
    _data = newData;
    _capacity = newCapacity;
}

template <typename T>
void MutantStack<T>::push_back(const T& value)
{
    if (_size == _capacity)
        _reserve(_capacity == 0 ? 1 : _capacity * 2);
    _data[_size++] = value;
}

template <typename T>
void MutantStack<T>::pop_back()
{
    if (_size == 0)
        throw std::runtime_error("Pop from empty stack");
    --_size;
}

template <typename T>
T& MutantStack<T>::back()
{
    if (_size == 0)
        throw std::runtime_error("Empty stack");
    return _data[_size - 1];
}

template <typename T>
const T& MutantStack<T>::back() const
{
    if (_size == 0)
        throw std::runtime_error("Empty stack");
    return _data[_size - 1];
}

template <typename T>
size_t MutantStack<T>::size() const
{
    return _size;
}

template <typename T>
T& MutantStack<T>::operator[](size_t index)
{
    if (index >= _size)
        throw std::runtime_error("Index out of bounds");
    return _data[index];
}

template <typename T>
const T& MutantStack<T>::operator[](size_t index) const
{
    if (index >= _size)
        throw std::runtime_error("Index out of bounds");
    return _data[index];
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return _data;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return _data + _size;
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return _data;
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return _data + _size;
}

template <typename T>
bool MutantStack<T>::empty() const
{
    return _size == 0;
}

class RPN
{
    private:
        MutantStack<std::string> _argv;

        static bool isNumeric(const std::string &str);
        static bool isOperator(const std::string& token);
       
    public:
       
        RPN(const std::string& argv);
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        const MutantStack<std::string>& getArgv() const;

        class GeneralException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        float fromFloat(const std::string& literal);
        void handleError(void) const;

};
    
void runRPN(const std::string& argv);

#endif