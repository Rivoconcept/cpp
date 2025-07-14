/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:53:00 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/14 15:43:07 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "use: ./PmergeMe <a sequence of positive integers>" << std::endl;
        return (1);
    }

    std::string str;

    for (int i = 1; i < argc; ++i)
    {
        str += argv[i];
        if (i != argc - 1)
            str += " ";
    }

    std::cout << str << std::endl;

    
    /*try
    {
        runRPN(str);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }*/

    return (0);
}