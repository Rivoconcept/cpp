/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:29:46 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/23 17:21:13 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
easyfind<T>::easyfind() : _easyfind(NULL), _size(0) {}

template <typename T>
easyfind<T>::easyfind(unsigned int n) : _easyfind(new T[n]()), _size(n) {}

template <typename T>
easyfind<T>::easyfind(const easyfind& other) : _easyfind(new T[other._size]), _size(other._size)
{
    for (unsigned int i = 0; i < _size; ++i)
        _easyfind[i] = other._easyfind[i];
}

template <typename T>
easyfind<T>& easyfind<T>::operator=(const easyfind& other)
{
    if (this != &other)
{
        delete[] _easyfind;
        _size = other._size;
        _easyfind = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
            _easyfind[i] = other._easyfind[i];
    }
    return (*this);
}

template <typename T>
easyfind<T>::~easyfind()
{
    delete[] _easyfind;
}

template <typename T>
T& easyfind<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _easyfind[index];
}

template <typename T>
const T& easyfind<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _easyfind[index];
}

template <typename T>
unsigned int easyfind<T>::size() const
{
    return _size;
}
