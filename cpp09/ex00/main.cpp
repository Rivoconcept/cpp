/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:53:00 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/09 18:58:34 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{

    if (argc != 2 || (argc == 2 && !argv[1][0]))
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    
    std::istringstream iss(argv[1]);
    std::string file;
    if (!(iss >> file))
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    
    BitcoinExchange btc;
    try
    {
        btc.putDataBase("data.csv");
        btc.putFileContent(file);
        std::deque<std::string> dataFile = btc.getFileContent();
        std::deque<std::string> dataBase = btc.getDataBase();

        btc.findValue(dataBase, dataFile);
        /*for (std::deque<std::string>::iterator it = base.begin(); it != base.end(); ++it)
        {
            std::cout << *it << std::endl;
        }*/

    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    return 0;
}