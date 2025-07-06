/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:53:00 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/06 18:02:43 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*std::vector<int> ft_split_to_ints(const std::string& str, char delimiter)
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
}*/

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
        BitcoinExchange btc;
        btc.dataEntry("data.csv");
        std::deque<std::string> base = btc.getDataBase();
        for (std::deque<std::string>::iterator it = base.begin(); it != base.end(); ++it)
        {
            std::cout << *it << std::endl;
        }

    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "----------------- FILE ----------------------" << std::endl;

        BitcoinExchange btc;
        btc.dataEntry("input.txt");
        std::deque<std::string> file = btc.getDataBase();
        for (std::deque<std::string>::iterator it = file.begin(); it != file.end(); ++it)
        {
            std::cout << *it << std::endl;
        }

    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}