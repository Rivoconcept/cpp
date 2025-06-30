/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:42:51 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/23 17:18:16 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm> 
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>


class MutantStack
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
    
    public:
        MutantStack(unsigned int N);
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        unsigned int getMaxSize() const;

        void addNumber(int n);

        int shortestMutantStack() const;
        int longestMutantStack() const;

};


#endif