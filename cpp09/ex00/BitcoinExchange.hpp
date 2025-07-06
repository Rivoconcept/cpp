/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:13:38 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/06 17:59:27 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
# include <string>
#include <sstream>
# include <fstream>
#include <deque>

class BitcoinExchange
{
    private:
        std::deque<std::string> _fileContent;
        std::deque<std::string> _dataBase;

    public:

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        const std::deque<std::string>& getDataBase() const;
        const std::deque<std::string>& getFileContent() const;

        void putFileContent(const std::string& file);
        void putDataBase(const std::string& inputFile);
        
        void formatValue(const std::string& value);
        
};


#endif