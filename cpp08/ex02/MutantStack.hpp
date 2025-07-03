/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:55:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/03 18:52:02 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <cstddef>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack& other);
    ~MutantStack();
    MutantStack& operator=(const MutantStack& other);

    // Itérateur standard
    class iterator
    {
    private:
        T* _ptr;
        
    public:
        iterator(T* ptr = NULL) : _ptr(ptr) {}
        iterator(const iterator& other) : _ptr(other._ptr) {}
        ~iterator() {}
        
        iterator& operator=(const iterator& other) {
            if (this != &other) _ptr = other._ptr;
            return *this;
        }
        
        T& operator*() { return *_ptr; }
        T* operator->() { return _ptr; }
        iterator& operator++() { ++_ptr; return *this; }
        iterator operator++(int) { iterator tmp(*this); ++_ptr; return tmp; }
        bool operator==(const iterator& other) const { return _ptr == other._ptr; }
        bool operator!=(const iterator& other) const { return _ptr != other._ptr; }
    };

    // Itérateur constant
    class const_iterator
    {
    private:
        const T* _ptr;
        
    public:
        const_iterator(const T* ptr = NULL) : _ptr(ptr) {}
        const_iterator(const const_iterator& other) : _ptr(other._ptr) {}
        ~const_iterator() {}
        
        const T& operator*() const { return *_ptr; }
        const T* operator->() const { return _ptr; }
        const_iterator& operator++() { ++_ptr; return *this; }
        const_iterator operator++(int) { const_iterator tmp(*this); ++_ptr; return tmp; }
        bool operator==(const const_iterator& other) const { return _ptr == other._ptr; }
        bool operator!=(const const_iterator& other) const { return _ptr != other._ptr; }
    };

    // Itérateur inverse
    class reverse_iterator
    {
    private:
        T* _ptr;
        
    public:
        reverse_iterator(T* ptr = NULL) : _ptr(ptr) {}
        reverse_iterator(const reverse_iterator& other) : _ptr(other._ptr) {}
        ~reverse_iterator() {}
        
        T& operator*() { return *_ptr; }
        T* operator->() { return _ptr; }
        reverse_iterator& operator++() { --_ptr; return *this; }
        reverse_iterator operator++(int) { reverse_iterator tmp(*this); --_ptr; return tmp; }
        bool operator==(const reverse_iterator& other) const { return _ptr == other._ptr; }
        bool operator!=(const reverse_iterator& other) const { return _ptr != other._ptr; }
    };

    // Itérateur inverse constant
    class const_reverse_iterator
    {
    private:
        const T* _ptr;
        
    public:
        const_reverse_iterator(const T* ptr = NULL) : _ptr(ptr) {}
        const_reverse_iterator(const const_reverse_iterator& other) : _ptr(other._ptr) {}
        ~const_reverse_iterator() {}
        
        const T& operator*() const { return *_ptr; }
        const T* operator->() const { return _ptr; }
        const_reverse_iterator& operator++() { --_ptr; return *this; }
        const_reverse_iterator operator++(int) { const_reverse_iterator tmp(*this); --_ptr; return tmp; }
        bool operator==(const const_reverse_iterator& other) const { return _ptr == other._ptr; }
        bool operator!=(const const_reverse_iterator& other) const { return _ptr != other._ptr; }
    };

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