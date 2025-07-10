/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:55:42 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/03 18:57:57 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    if (this != &other)
        std::stack<T>::operator=(other);
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    if (this->empty()) return iterator(NULL);
    return iterator(&this->top() - (this->size() - 1));
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    if (this->empty()) return iterator(NULL);
    return iterator(&this->top() + 1);
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    if (this->empty()) return const_iterator(NULL);
    return const_iterator(&this->top() - (this->size() - 1));
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    if (this->empty()) return const_iterator(NULL);
    return const_iterator(&this->top() + 1);
}

// Itérateurs inversés
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    if (this->empty()) return reverse_iterator(NULL);
    return reverse_iterator(&this->top());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    if (this->empty()) return reverse_iterator(NULL);
    return reverse_iterator(&this->top() - this->size());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
    if (this->empty()) return const_reverse_iterator(NULL);
    return const_reverse_iterator(&this->top());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    if (this->empty()) return const_reverse_iterator(NULL);
    return const_reverse_iterator(&this->top() - this->size());
}
