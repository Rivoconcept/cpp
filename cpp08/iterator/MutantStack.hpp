/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:55:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/02 12:17:51 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <stack>
#include <deque>
#include <cstddef>


template <typename T>
class MutantStack
{
private:
    std::stack<T> _stack;

    // Helper pour accéder au conteneur sous-jacent (std::deque par défaut)
    typedef typename std::stack<T>::container_type Container;
    Container& getContainer();

public:
    // Constructeurs et opérateurs
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();

    // Méthodes de std::stack redirigées
    bool empty() const;
    size_t size() const;
    T& top();
    const T& top() const;
    void push(const T& val);
    void pop();

    // Itérateur personnalisé
    class Iterator
    {
    private:
        typename Container::iterator _it;

    public:
        Iterator(typename Container::iterator it);
        T& operator*();
        Iterator& operator++();
        Iterator operator++(int);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin();
    Iterator end();
};

#include "MutantStack.tpp"

#endif