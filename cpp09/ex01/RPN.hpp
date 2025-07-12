/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:55:48 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/11 16:02:07 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
# include <string>
#include <sstream>
# include <fstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <stack>
#include <list>

template <typename T, typename Container = std::list<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
        
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) 
    : std::stack<T, Container>(other) {}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other)
{
    if (this != &other)
        std::stack<T, Container>::operator=(other);
    return *this;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
    return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
    return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
    return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
    return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
    return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
    return this->c.rend();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const
{
    return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const
{
    return this->c.rend();
}


template <typename T, typename Container>
T& MutantStack<T, Container>::operator[](size_t index)
{
    if (index >= this->size())
        throw std::out_of_range("Index out of bounds");
    
    typename Container::iterator it = this->c.begin();
    std::advance(it, index);
    return *it;
}

template <typename T, typename Container>
const T& MutantStack<T, Container>::operator[](size_t index) const
{
    if (index >= this->size())
        throw std::out_of_range("Index out of bounds");
    
    typename Container::const_iterator it = this->c.begin();
    std::advance(it, index);
    return *it;
}


class RPN
{
    private:
        MutantStack<std::string> _argv;
        std::stack<float> _operand;

        static bool isNumeric(const std::string &str);
        static bool isOperator(const std::string& token);
       
    public:
       
        RPN(const std::string& argv);
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        const MutantStack<std::string>& getArgv() const;

        std::string& operator[](unsigned int index);
        const std::string& operator[](unsigned int index) const;


        class GeneralException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        float fromFloat(const std::string& literal);
        void handleError(void) const;
        
        std::stack<float> ft_split_to_doubles(const std::string& str, char delimiter);

};
    
void runRPN(const std::string& argv);

#endif