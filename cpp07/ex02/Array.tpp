/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:29:46 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/21 15:00:04 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : _array(new T[other._size]), _size(other._size)
{
    for (unsigned int i = 0; i < _size; ++i)
        _array[i] = other._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
{
        delete[] _array;
        _size = other._size;
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
            _array[i] = other._array[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}
