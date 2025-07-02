/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:55:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/02 18:44:32 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stdexcept>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
    T* _array;
    size_t _size;

public:
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();

    class iterator
    {
    private:
        T* _it;

    public:
        iterator(T* it);
        T& operator*();
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);
        iterator operator+(int n) const;
        iterator operator-(int n) const;
        bool operator!=(const iterator& other) const;
        bool operator==(const iterator& other) const;
        T* operator->();
    };

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    bool empty() const;
    size_t size() const;
    T& top();
    const T& top() const;
    void push(const T& val);
    void pop();

    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"

#endif