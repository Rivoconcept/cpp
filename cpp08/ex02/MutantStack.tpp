/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:55:42 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/02 15:05:04 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
 
// Constructeurs et destructeur
template <typename T>
MutantStack<T>::MutantStack() : _elements(NULL), _capacity(0), _size(0) {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) 
    : _elements(new T[other._capacity]), _capacity(other._capacity), _size(other._size)
{
    std::copy(other._elements, other._elements + _size, _elements);
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    if (this != &other)
    {
        delete[] _elements;
        _capacity = other._capacity;
        _size = other._size;
        _elements = new T[_capacity];
        std::copy(other._elements, other._elements + _size, _elements);
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    delete[] _elements;
}

// Méthodes stack
template <typename T>
void MutantStack<T>::push(const T& value)
{
    if (_size >= _capacity)
    {
        size_t new_capacity = _capacity == 0 ? 1 : _capacity * 2;
        T* new_elements = new T[new_capacity];
        std::copy(_elements, _elements + _size, new_elements);
        delete[] _elements;
        _elements = new_elements;
        _capacity = new_capacity;
    }
    _elements[_size++] = value;
}

template <typename T>
void MutantStack<T>::pop()
{
    if (_size == 0)
        throw std::out_of_range("Stack is empty");
    --_size;
}

template <typename T>
T& MutantStack<T>::top()
{
    if (_size == 0)
        throw std::out_of_range("Stack is empty");
    return _elements[_size - 1];
}

template <typename T>
const T& MutantStack<T>::top() const
{
    if (_size == 0)
        throw std::out_of_range("Stack is empty");
    return _elements[_size - 1];
}

template <typename T>
bool MutantStack<T>::empty() const { return _size == 0; }

template <typename T>
size_t MutantStack<T>::size() const { return _size; }

// Implémentation de l'itérateur
template <typename T>
MutantStack<T>::iterator::iterator(T* ptr) : _ptr(ptr) {}

template <typename T>
T& MutantStack<T>::iterator::operator*() const { return *_ptr; }

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator++()
{
    ++_ptr;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(int)
{
    iterator tmp = *this;
    ++_ptr;
    return tmp;
}

template <typename T>
bool MutantStack<T>::iterator::operator==(const iterator& other) const
{
    return _ptr == other._ptr;
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(const iterator& other) const
{
    return _ptr != other._ptr;
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--()
{
    --_ptr;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(int)
{
    iterator tmp = *this;
    --_ptr;
    return tmp;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator+(int n) const
{
    return iterator(_ptr + n);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator-(int n) const
{
    return iterator(_ptr - n);
}

template <typename T>
T* MutantStack<T>::iterator::operator->() const { return _ptr; }

// Méthodes d'accès aux itérateurs
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return iterator(_elements);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return iterator(_elements + _size);
}


