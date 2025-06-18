/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:22:58 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/18 18:24:00 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

// Constructeur par défaut
template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

// Constructeur avec taille
template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

// Constructeur de copie
template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(0)
{
    _size = other._size;
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; ++i)
        _array[i] = other._array[i];
}

// Opérateur d'affectation
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
    return *this;
}

// Destructeur
template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

// Opérateur []
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

// Méthode size()
template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

#endif
