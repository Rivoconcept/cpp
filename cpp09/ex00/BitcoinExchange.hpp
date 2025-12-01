/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:31:09 by rhanitra          #+#    #+#             */
/*   Updated: 2025/12/01 18:02:44 by rhanitra         ###   ########.fr       */
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
#include <list>
#include <set>

class BitcoinExchange
{
    private:
    
        std::set<std::string> _fileContent;
        std::list<std::string> _listContent;
        
        std::set<std::string> _dataBase;
        std::list<std::string> _listBase;

        static bool isLeapYear(int year);
        static std::string trim(const std::string& str);
        static void findDuplicates(std::list<std::string>& dataBase);
        
        public:
        
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        
        const std::set<std::string>& getDataBase() const;
        const std::list<std::string>& getFileContent() const;
        
        const std::string formatNumber(float);
        std::string removeSpaces(const std::string& str);
        bool isValidDate(int day, int month, int year);
        bool checkErrorDate(std::list<std::string> tabLine);
        float fromFloat(const std::string& literal);
        const std::string& myRegexReplace(std::string& str, const std::string& reg, char c);
        std::list<std::string> simpleSplit(const std::string& str, char delimiter);
        std::list<std::string> ftSplitStr(const std::string& str, char delimiter);
        
        void putFileContent(const std::string& fileName);
        void putDataBase(const std::string& fileName);

              
};
    
template <typename T>
T& getListElement(std::list<T>& lst, size_t index)
{
    if (index >= lst.size())
        throw std::runtime_error("bad input => null");

    typename std::list<T>::iterator it = lst.begin();
    std::advance(it, index);
    return (*it);
}

template <typename T>
const T& getListElement(const std::set<T>& lst, size_t index)
{
    if (index >= lst.size())
        throw std::runtime_error("bad input => null");
        
    typename std::set<T>::const_iterator it = lst.begin();
    std::advance(it, index);
    return (*it);
}

void findValue(const std::string& dbName, char *inputFileName);

#endif