/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:53:00 by rhanitra          #+#    #+#             */
/*   Updated: 2025/06/27 16:49:32 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <vector>
#include <cmath>

std::vector<int> ft_split_to_ints(const std::string& str, char delimiter)
{
    std::vector<int> output;
    std::istringstream iss(str);
    std::string token;
    
    while (std::getline(iss, token, delimiter))
    {
        if (!token.empty())
        {
            std::istringstream iss_token(token);
            long n;
            char extra;
            
            if (!(iss_token >> n) || (iss_token >> extra))
                throw std::runtime_error("Token invalide: '" + token + "'");
            
            if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
                throw std::runtime_error("Nombre hors limites: " + token);
            
            output.push_back(static_cast<int>(n));
        }
    }
    
    return (output);
}

int main(int argc, char **argv)
{
    if (argc < 3 || (argc == 2 && !argv[1][0]))
    {
        std::cout << "Use at least 3 parameters: ./easyfind <more arguments separated by spaces>" << std::endl;
        return (1);
    }

    std::string str;

    for (int i = 1; i < argc - 1; ++i)
    {
        str += argv[i];
        if (i != argc - 1)
            str += " ";
    }
    
    std::istringstream iss(argv[argc - 1]);
    int nbrToFind;
    if (!(iss >> nbrToFind))
    {
        std::cout << "Bad parameter on nbrToFind" << std::endl;
        return (1);
    }

    std::vector<int> tokens = ft_split_to_ints(str, ' ');
    
    try
    {
        std::vector<int>::iterator it = easyfind(tokens, nbrToFind);
        std::cout << "Found: " << *it << " at position " << (it - tokens.begin()) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}