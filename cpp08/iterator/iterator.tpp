/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:55:42 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/02 08:20:36 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.hpp"

template <typename T>
Container<T>::Container(unsigned int size): _size(size), _array(new T[size]) {}

template <typename T>
Container<T>::Container(const Container<T>& other): _size(other._size), _array(new T[other._size])
{
    for (unsigned int i = 0; i < _size; i++)
    {
        _array[i] = other._array[i];
    }   
}

template <typename T>
Container<T>& Container<T>::operator=(const Container<T>& other)
{
    if (this != &other)
    {
        delete[] _array;
        _size = other._size;
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
        {
            _array[i] = other._array[i];
        }
    }
    return (*this);
}

template <typename T>
Container<T>::~Container()
{
    delete[] _array;
}

template <typename T>
Container<T>::Iterator::Iterator(T* it): _it(it) {}

// Opérateur de déréférencement
template <typename T>
T& Container<T>::Iterator::operator*()
{
    return (*_it);
}

// Pré-incrémentation
template <typename T>
typename Container<T>::Iterator& Container<T>::Iterator::operator++()
{
    ++_it;
    return (*this);
}

template <typename T>
bool Container<T>::Iterator::operator!=(const Iterator& other) const
{
    return (_it != other._it);
}

template <typename T>
typename Container<T>::Iterator Container<T>::begin()
{
    return (Iterator(_array));
}

template <typename T>
typename Container<T>::Iterator Container<T>::end()
{
    return (Iterator(_array + _size));
}

// Accès avec vérification des limites (optionnel)
template <typename T>
T& Container<T>::operator[](unsigned int index)
{
    return _array[index];
}

template <typename T>
const T& Container<T>::operator[](unsigned int index) const
{
    return _array[index];
}

template <typename T>
unsigned int Container<T>::size() const {
    return _size;
}

// Pré-décrémentation
template <typename T>
typename Container<T>::Iterator& Container<T>::Iterator::operator--()
{
    --_it;
    return *this;
}

// Post-décrémentation
template <typename T>
typename Container<T>::Iterator Container<T>::Iterator::operator--(int)
{
    Iterator tmp = *this;
    --_it;
    return tmp;
}


template <typename T>
bool Container<T>::Iterator::operator==(const Iterator& other) const
{
    return _it == other._it;
}

// Accès membre
template <typename T>
T* Container<T>::Iterator::operator->()
{
    return _it;
}

template <typename T>
typename Container<T>::Iterator Container<T>::Iterator::operator+(int n) const
{
    return Iterator(_it + n);
}

template <typename T>
typename Container<T>::Iterator Container<T>::Iterator::operator-(int n) const
{
    return Iterator(_it - n);
}

// Ajout en fin
template <typename T>
void Container<T>::push_back(const T& value)
{
    // Version simplifiée (sans gestion de capacité)
    T* new_array = new T[_size + 1];
    for (unsigned int i = 0; i < _size; ++i)
    {
        new_array[i] = _array[i];
    }
    new_array[_size] = value;
    delete[] _array;
    _array = new_array;
    ++_size;
}

// Suppression en fin
template <typename T>   
void Container<T>::pop_back()
{
    if (_size == 0)
        return;
    
    T* new_array = new T[_size - 1];
    
    for (unsigned int i = 0; i < _size - 1; ++i)
    {
        new_array[i] = _array[i];
    }
    
    delete[] _array;
    
    _array = new_array;
    --_size;
}