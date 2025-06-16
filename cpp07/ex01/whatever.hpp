/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:42:51 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/16 18:33:35 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void swap(T* a, T* b)
{
    if (!a || !b)
        throw std::invalid_argument("Null pointer passed to swap");
              
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

template <typename T>
const T& min(const T &a, const T &b)
{
    return ((a < b) ? a : b);
}

template <typename T>
const T* min(const T* a, const T* b)
{
    if (!a || !b)
        throw std::invalid_argument("Null pointer in min");
    return (*a < *b) ? a : b;
}


template <typename T>
const T& max(const T &a, const T &b)
{
    return ((a > b) ? a : b);
}

template <typename T>
const T* max(const T* a, const T* b) {
    if (!a || !b)
        throw std::invalid_argument("Null pointer in max");
    return (*a > *b) ? a : b;
}


#endif