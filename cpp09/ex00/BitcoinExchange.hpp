/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:31:09 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/08 20:08:43 by rhanitra         ###   ########.fr       */
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
        std::deque<std::string> _dataToFind;
        std::deque<std::string> _fileContent;
        std::deque<std::string> _dataBase;

        static void displayValue(float);
        static float fromFloat(const std::string& literal);

        static bool isLeapYear(int year);
        static bool isValidDate(int day, int month, int year);
        static const std::string& myRegexReplace(std::string& str, const std::string& reg, char c);
        static std::string removeSpaces(const std::string& str);
        static std::string removeOtherSpace(const std::string& str);
        static std::deque<float> ftSplitToFloat(const std::deque<std::string>& dataBase, const std::string& str, char delimiter);
        static void findDuplicates(std::deque<std::string>& dataBase);

    public:

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        const std::deque<std::string>& getDataBase() const;
        const std::deque<std::string>& getFileContent() const;

        void putFileContent(const std::string& fileName);
        void putDataBase(const std::string& fileName);
        
        void findValue(const std::deque<std::string>& dataBase, const std::deque<std::string>& dataFile);


        class generalException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
};


#endif