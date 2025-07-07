/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:13:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/07 13:57:08 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
# include <string>
#include <sstream>
# include <fstream>
#include <limits> 
#include <regex>
#include <deque>

class BitcoinExchange
{
    private:
        std::deque<std::string> _dataToFind;
        std::deque<std::string> _fileContent;
        std::deque<std::string> _dataBase;

        static bool isLeapYear(int year);
        static bool is_valid_date(int day, int month, int year);
        static std::deque<int> ft_split_to_string(const std::string& str, char delimiter);

    public:

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        const std::deque<std::string>& getDataBase() const;
        const std::deque<std::string>& getFileContent() const;

        void putFileContent(const std::string& file);
        void putDataBase(const std::string& inputFile);
        
        void findValue(const std::deque<std::string> dataFile);
        
};


#endif