/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:41:42 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/18 17:41:53 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printInt(int val)
{
    std::cout << val << " ";
}

void printString(std::string val)
{
    std::cout << val << " ";
}

int main(void)
{
    { 
        int tabInt[] = {5, 35, 87, 42, 9};
        size_t tabSize = sizeof(tabInt) / sizeof(tabInt[0]);

        std::cout << "The contents of the tabInt: ";
        try
        {
            iter(tabInt, tabSize, printInt);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << std::endl;
    }

    {
        std::string tabStr[2] = {"Banana", "pinapple"};

        std::cout << "The contents of the tabStr: ";
        try
        {
            iter(tabStr, 2, printString);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << std::endl;
    }

    return 0;
}
