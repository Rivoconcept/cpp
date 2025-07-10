/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:31:09 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/10 16:41:50 by rhanitra         ###   ########.fr       */
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
#include <cmath>
#include <iomanip>
#include <deque>

class BitcoinExchange
{
    private:
    
        std::deque<std::string> _fileContent;
        std::deque<std::string> _dataBase;

        static float fromFloat(const std::string& literal);
        static bool isLeapYear(int year);
        static std::string removeSpaces(const std::string& str);
        static void findDuplicates(std::deque<std::string>& dataBase);
       
    public:
       
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        const std::deque<std::string>& getDataBase() const;
        const std::deque<std::string>& getFileContent() const;

        const std::string formatNumber(float);
        bool isValidDate(int day, int month, int year);
        const std::string& myRegexReplace(std::string& str, const std::string& reg, char c);
        std::deque<float> ftSplitToFloat(const std::string& str, char delimiter);
        
        void putFileContent(const std::string& fileName);
        void putDataBase(const std::string& fileName);

              
};
    
void findValue(const std::string& dbName, char *inputFileName);

#endif