/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:27:15 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/03 17:21:01 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : _array(NULL), _size(0) {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) 
    : _array(new T[other._size]), _size(other._size)
{
    std::copy(other._array, other._array + _size, _array);
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    if (this != &other)
    {
        delete[] _array;
        _size = other._size;
        _array = new T[_size];
        std::copy(other._array, other._array + _size, _array);
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    delete[] _array;
}

template <typename T>
MutantStack<T>::iterator::iterator(T* it) : _it(it) {}

template <typename T>
T& MutantStack<T>::iterator::operator*() { return *_it; }

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator++()
{
    ++_it;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(int)
{
    iterator tmp = *this;
    ++_it;
    return tmp;
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--()
{
    --_it;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(int)
{
    iterator tmp = *this;
    --_it;
    return tmp;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator+(int n) const
{
    return iterator(_it + n);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator-(int n) const
{
    return iterator(_it - n);
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(const iterator& other) const
{
    return _it != other._it;
}

template <typename T>
bool MutantStack<T>::iterator::operator==(const iterator& other) const
{
    return _it == other._it;
}

template <typename T>
T* MutantStack<T>::iterator::operator->() { return _it; }

template <typename T>
T& MutantStack<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return _array[index];
}

template <typename T>
const T& MutantStack<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return _array[index];
}

/*template <typename T>
bool MutantStack<T>::empty() const { return _size == 0; }

template <typename T>
size_t MutantStack<T>::size() const { return _size; }

template <typename T>
T& MutantStack<T>::top()
{
    if (_size == 0)
        throw std::out_of_range("Stack is empty");
    return _array[_size - 1];
}

template <typename T>
const T& MutantStack<T>::top() const
{
    if (_size == 0)
        throw std::out_of_range("Stack is empty");
    return _array[_size - 1];
}

template <typename T>
void MutantStack<T>::push(const T& val)
{
    T* new_array = new T[_size + 1];
    std::copy(_array, _array + _size, new_array);
    new_array[_size] = val;
    delete[] _array;
    _array = new_array;
    ++_size;
}

template <typename T>
void MutantStack<T>::pop()
{
    if (_size == 0)
        throw std::out_of_range("Stack is empty");
    
    T* new_array = new T[_size - 1];
    std::copy(_array, _array + _size - 1, new_array);
    delete[] _array;
    _array = new_array;
    --_size;
}*/

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return iterator(_array);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return iterator(_array + _size);
}