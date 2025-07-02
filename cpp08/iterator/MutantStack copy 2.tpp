/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:55:42 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/02 17:37:41 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    if (this != &other)
    {
        std::stack<T>::operator=(other);
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}


template <typename T>
void MutantStack<T>::push(const T& value)
{
    this->push_back(value);
}

template <typename T>
void MutantStack<T>::pop()
{
    if (this->empty())
        throw std::out_of_range("MutantStack::pop(): stack is empty");
    this->pop_back();
}

template <typename T>
T& MutantStack<T>::top()
{
    if (this->empty())
        throw std::out_of_range("MutantStack::top(): stack is empty");
    return this->back();
}

template <typename T>
const T& MutantStack<T>::top() const
{
    if (this->empty())
        throw std::out_of_range("MutantStack::top(): stack is empty");
    return this->back();
}

template <typename T>
bool MutantStack<T>::empty() const
{
    return std::stack<T>::empty();
}

template <typename T>
size_t MutantStack<T>::size() const
{
    return std::stack<T>::size();
}

template <typename T>
T& MutantStack<T>::operator[](size_t index)
{
    if (index >= this->size())
        throw std::out_of_range("MutantStack::operator[]: index out of range");
    
    iterator it = this->begin();
    std::advance(it, index);
    return *it;
}

template <typename T>
const T& MutantStack<T>::operator[](size_t index) const
{
    if (index >= this->size())
        throw std::out_of_range("MutantStack::operator[]: index out of range");
    
    const_iterator it = this->begin();
    std::advance(it, index);
    return *it;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return std::stack<T>::begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return std::stack<T>::end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return std::stack<T>::begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return std::stack<T>::end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return std::stack<T>::rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return std::stack<T>::rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return std::stack<T>::rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return std::stack<T>::rend();
}