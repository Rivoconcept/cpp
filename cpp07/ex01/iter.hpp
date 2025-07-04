/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:42:51 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/18 17:25:46 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstddef>

template <typename T, typename F>
void iter(T* array, size_t length, F function)
{
    if (!array || length <= 0)
        throw std::invalid_argument("Bad parameter!!!");
        
    for (size_t i = 0; i < length; ++i)
    {
        function(array[i]);
    }
}
#endif