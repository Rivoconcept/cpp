/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack copy 2.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:55:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/02 18:57:38 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <stdexcept>


template <typename T>
class MutantStack : public std::stack<T>
{
public:

    typedef typename std::stack<T>::iterator iterator;
    typedef typename std::stack<T>::const_iterator const_iterator;
    typedef typename std::stack<T>::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::const_reverse_iterator const_reverse_iterator;

    // Constructeurs
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();

    // Méthodes stack
    void push(const T& value);
    void pop();
    T& top();
    const T& top() const;
    bool empty() const;
    size_t size() const;

    // Accès aux éléments
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // Itérateurs
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif