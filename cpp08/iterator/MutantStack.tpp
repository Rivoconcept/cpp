/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:55:42 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/02 12:18:44 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
 
// Helper pour accéder au conteneur sous-jacent (std::deque)
template <typename T>
typename MutantStack<T>::Container& MutantStack<T>::getContainer()
{
    struct Access : std::stack<T> {
        static Container& get(std::stack<T>& stack) {
            return stack.*&Access::c; // Accès protégé via héritage
        }
    };
    return Access::get(_stack);
}

// Constructeurs et destructeur
template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : _stack(other._stack) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

// Méthodes de std::stack
template <typename T>
bool MutantStack<T>::empty() const { return _stack.empty(); }

template <typename T>
size_t MutantStack<T>::size() const { return _stack.size(); }

template <typename T>
T& MutantStack<T>::top() { return _stack.top(); }

template <typename T>
const T& MutantStack<T>::top() const { return _stack.top(); }

template <typename T>
void MutantStack<T>::push(const T& val) { _stack.push(val); }

template <typename T>
void MutantStack<T>::pop() { _stack.pop(); }

// Itérateur
template <typename T>
MutantStack<T>::Iterator::Iterator(typename Container::iterator it) : _it(it) {}

template <typename T>
T& MutantStack<T>::Iterator::operator*() { return *_it; }

template <typename T>
typename MutantStack<T>::Iterator& MutantStack<T>::Iterator::operator++()
{
    ++_it;
    return *this;
}

template <typename T>
typename MutantStack<T>::Iterator MutantStack<T>::Iterator::operator++(int)
{
    Iterator tmp = *this;
    ++_it;
    return tmp;
}

template <typename T>
bool MutantStack<T>::Iterator::operator==(const Iterator& other) const
{
    return _it == other._it;
}

template <typename T>
bool MutantStack<T>::Iterator::operator!=(const Iterator& other) const
{
    return _it != other._it;
}

// Méthodes d'itération
template <typename T>
typename MutantStack<T>::Iterator MutantStack<T>::begin()
{
    return Iterator(getContainer().begin());
}

template <typename T>
typename MutantStack<T>::Iterator MutantStack<T>::end()
{
    return Iterator(getContainer().end());
}

