/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:19:19 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/06 18:01:46 by rhanitra         ###   ########.fr       */
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
    
    while (std::getline(ifs, line))
    {
        _fileContent.push_back(line);
    }
    ifs.close();
} 