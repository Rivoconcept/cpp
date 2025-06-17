/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:41:42 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/17 19:10:25 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "iter.hpp"

#include <iostream>
#include <stdexcept>
#include <cstddef> // pour size_t

// 1. Définition de is_same_myFunc<T, U>
template<typename T, typename U>
struct is_same_myFunc {
    enum { value = 0 }; // false
};

template<typename T>
struct is_same_myFunc<T, T> {
    enum { value = 1 }; // true
};

// 2. printInt qui vérifie que T == int
template<typename T>
void printInt(T &val)
{
    int type_check[is_same_myFunc<T, int>::value ? 1 : -1]; // Erreur si T ≠ int
    (void)type_check;

    std::cout << val << " ";
}

// 3. iter générique
template <typename T, typename F>
void iter(T* array, size_t length, F function)
{
    if (!array || length == 0)
        throw std::invalid_argument("An error of argument!!!");

    for (size_t i = 0; i < length; ++i)
        function(array[i]); // Appel de la fonction
}

// 4. main
int main(void)
{
    { 
        int tabInt[] = {5, 35, 87, 42, 9};
        size_t tabSize = sizeof(tabInt) / sizeof(tabInt[0]);

        std::cout << "The contents of the array: ";
        try
        {
            iter(tabInt, tabSize, &printInt<int>);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << std::endl;
        return 0;
    }
    {
        const char *tabInt[2] = {"skd", "lkdfj"};

        std::cout << "The contents of the array: ";
        try
        {
            iter(tabInt, 2, &printInt<int>);;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << std::endl;
    }
}
