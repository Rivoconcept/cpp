/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:53:00 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/06 16:02:50 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <sstream>
#include <iomanip>
#include <limits>

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
    if (argc < 2)
    {
        std::cout << "Use: ./Span <number1> <number2> ... <numberN>" << std::endl;
        return (1);
    }

    std::string str;

    for (int i = 1; i < argc; ++i)
    {
        str += argv[i];
        if (i != argc - 1)
            str += " ";
    }
    
    std::vector<int> tokens;
    try
    {
        tokens = ft_split_to_ints(str, ' ');
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    if (tokens.empty())
    {
        std::cerr << "Error: No valid numbers provided." << std::endl;
        return 1;
    }
    
    try
    {
        Span sp(tokens.size());
        for (std::vector<int>::iterator it = tokens.begin(); it != tokens.end(); ++it)
        {
            sp.addNumber(*it);
        }
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Span Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}