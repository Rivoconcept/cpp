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

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

template <typename T>
class easyfind
{
    private:
        T* _easyfind;
        int _size;
         
    public:
        easyfind();
        explicit easyfind(unsigned int n);
        easyfind(const easyfind& other);
        easyfind& operator=(const easyfind& other);
        ~easyfind();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;
};

#include "easyfind.tpp"

#endif