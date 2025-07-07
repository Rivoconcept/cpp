/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:19:19 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/07 14:03:04 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _fileContent(0), _dataBase(0) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        _dataBase = other._dataBase;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

const std::deque<std::string>& BitcoinExchange::getDataBase() const
{
    return (_dataBase);
}

const std::deque<std::string>& BitcoinExchange::getFileContent() const
{
    return (_fileContent);
}

bool BitcoinExchange::isLeapYear(int year) 
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

bool BitcoinExchange::is_valid_date(int day, int month, int year)
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

std::vector<int> BitcoinExchange::ft_split_to_ints(const std::string& str, char delimiter)
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

void BitcoinExchange::putDataBase(const std::string& inputFile)
{
    std::ifstream ifs(inputFile.c_str());
    if (!ifs)
    {
        throw std::runtime_error("Error: cannot open file '" + inputFile + "'");
    }
    
    std::string line;
    
    while (std::getline(ifs, line))
    {
        _dataBase.push_back(line);
    }
    ifs.close();
} 

void BitcoinExchange::putFileContent(const std::string& file)
{
    std::ifstream ifs(file.c_str());
    if (!ifs)
    {
        throw std::runtime_error("Error: cannot open file '" + file + "'");
    }
    
    std::string line;
    std::deque<int> tabLine;
    
    while (std::getline(ifs, line))
    {
        line = std::regex_replace(line, std::regex("[-,]"), " ");
        tabLine = ft_split_to_ints(line, ' ');
    }
    ifs.close();
}

void BitcoinExchange::findValue(const std::deque<std::string> dataFile)
{
    if (dataFile.empty())
        return ;
    
    int d, m, y;

    for (std::deque<std::string>::iterator it; dataFile.begin() != dataFile.end(); ++it)
    {
        
    }

}
