/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:55:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/03 18:40:12 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <algorithm> 
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

template <typename T>
class Container
{
    private:
        unsigned int _size;
        T* _array;
    
    public:
        Container(unsigned int size);
        Container(const Container<T>& other);
        Container& operator=(const Container<T>& other);
        ~Container();

        class Iterator
        {
            private:
                T* _it;

            public:

        };

        Iterator begin();
        Iterator end();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;

        void push_back(const T& value); 
        void pop_back();

};

#include "iterator.tpp"

#endif