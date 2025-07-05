/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:53:00 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/05 17:11:17 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"
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
    if (argc > 2 || (argc == 2 && !argv[1][0]))
    {
        std::cout << "Use: ./btc <file's name>" << std::endl;
        return (1);
    }
    
    std::istringstream iss(argv[1]);
    std::string str;
    if (!(iss >> str))
    {
        std::cout << "Bad parameter on nbrToFind" << std::endl;
        return (1);
    }


    
    try
    {


    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}