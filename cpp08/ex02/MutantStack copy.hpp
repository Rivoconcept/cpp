/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:55:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/02 12:57:37 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <stack>
#include <cstddef>



template <typename T>
class MutantStack
{
private:
    std::stack<T> _stack;

public:
    // Constructeurs et opérateurs
    MutantStack() {}
    MutantStack(const MutantStack& other) : _stack(other._stack) {}
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) {
            _stack = other._stack;
        }
        return *this;
    }
    ~MutantStack() {}

    // Interface std::stack redirigée
    bool empty() const { return _stack.empty(); }
    size_t size() const { return _stack.size(); }
    T& top() { return _stack.top(); }
    const T& top() const { return _stack.top(); }
    void push(const T& val) { _stack.push(val); }
    void pop() { _stack.pop(); }

    // Itérateurs personnalisés
    class Iterator
    {
    private:
        typename std::deque<T>::iterator _it;

    public:
        Iterator(typename std::deque<T>::iterator it) : _it(it) {}
        T& operator*() { return *_it; }
        Iterator& operator++() { ++_it; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++_it; return tmp; }
        bool operator==(const Iterator& other) const { return _it == other._it; }
        bool operator!=(const Iterator& other) const { return _it != other._it; }
    };

    Iterator begin() { 
        return Iterator(static_cast<std::deque<T>&>(_stack.*&std::stack<T>::c).begin());
    }
    
    Iterator end() { 
        return Iterator(static_cast<std::deque<T>&>(_stack.*&std::stack<T>::c).end());
    }
};

#include "MutantStack.tpp"

#endif