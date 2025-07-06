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


bool isLeapYear(int year) 
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

bool is_valid_date(int day, int month, int year)
{
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
        days_in_month[1] = 29;

    if (day > days_in_month[month - 1])
        return false;

    return true;
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
    
    BitcoinExchange btc;
    try
    {
        btc.putDataBase("data.csv");
        btc.putFileContent("input.txt");
        std::deque<std::string> base = btc.getDataBase();
        /*for (std::deque<std::string>::iterator it = base.begin(); it != base.end(); ++it)
        {
            std::cout << *it << std::endl;
        }*/

    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "----------------- FILE ----------------------" << std::endl;

        
        std::deque<std::string> file = btc.getFileContent();
        /*for (std::deque<std::string>::iterator it = file.begin(); it != file.end(); ++it)
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