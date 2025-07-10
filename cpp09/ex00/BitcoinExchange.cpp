/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:51:03 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/10 09:03:12 by rivoinfo         ###   ########.fr       */
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

const char* BitcoinExchange::generalException::what() const throw()
{
  return ("This program has many errors");   
}

const std::string BitcoinExchange::formatNumber(float value)
{
    std::ostringstream oss;
    if (value == std::floor(value) && std::abs(value) >= 1e9)
    {
        oss << std::fixed << std::setprecision(0) << value;
    }
    else
    {
        oss << value;
    }
    return oss.str();
}


float BitcoinExchange::fromFloat(const std::string& literal)
{
    std::istringstream iss(literal);
    float f;
    double d;

    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    {
        if (literal == "nanf") return std::numeric_limits<float>::quiet_NaN();
        if (literal == "+inff") return std::numeric_limits<float>::infinity();
        if (literal == "-inff") return -std::numeric_limits<float>::infinity();
    }

    if (!(iss >> d))
        throw std::runtime_error("Conversion to float: impossible");
        
    if (d < 0)
        throw std::runtime_error("Error: not a positive number.");
    
    f = static_cast<float>(d);

    if (std::isinf(f) || d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
       return (f > 0 ? std::numeric_limits<float>::infinity() : -std::numeric_limits<float>::infinity());
    else if (std::isnan(f))
        return std::numeric_limits<float>::quiet_NaN();
    
    return (f);
}

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

bool BitcoinExchange::isValidDate(int year, int month, int day)
{
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
        days_in_month[1] = 29;

    if (day > days_in_month[month - 1])
        return (false);

    return true;
}

const std::string& BitcoinExchange::myRegexReplace(std::string& str, const std::string& charsToReplace, char c)
{
    if (str.empty() || charsToReplace.empty())
        return str;

    for (size_t i = 0; i < str.size(); ++i)
    {
        for (size_t j = 0; j < charsToReplace.size(); ++j)
        {
            if (charsToReplace[j] == str[i])
            {
                if (str[i] == '-' && str[i - 1] == ' ')
                    break ;
                str[i] = c;
                break ;
            }
        }
    }
    return str;
}

std::string BitcoinExchange::removeSpaces(const std::string& str)
{
    std::string result;

    for (size_t i = 0; i < str.size(); ++i)
    {
        if (!isspace(static_cast<unsigned char>(str[i])))
        {
            result += str[i];
        }
    }
    
    if (!result.empty() && result[0] == ' ')
    {
        result.erase(0, 1);
    }
    
    if (!result.empty() && result[result.size() - 1] == ' ')
    {
        result.erase(result.size() - 1, 1);
    }

    return (result);
}

std::deque<float> BitcoinExchange::ftSplitToFloat(const std::string& str, char delimiter)
{
    std::deque<float> output;
    std::istringstream iss(str);
    std::string token;
    
    while (std::getline(iss, token, delimiter))
    {
        if (!token.empty())
        {
            std::istringstream iss_token(token);
            float n;
            char extra;
            
            if (!(iss_token >> n) || (iss_token >> extra))
                throw std::runtime_error("Token invalide: '" + token + "'");
            
            output.push_back(fromFloat(token));
        }
    }

    return (output);
}

void BitcoinExchange::findDuplicates(std::deque<std::string>& dataBase)
{   
    if (dataBase.empty() || (!dataBase.empty() && dataBase[1].empty()))
        throw std::runtime_error("Empty file!!!!");
        
    int found = 0;
    std::deque<std::string>::iterator it = dataBase.begin();
    
    while (it != dataBase.end())
    {
        found = 0;
        for (std::deque<std::string>::iterator itFind = dataBase.begin(); itFind != dataBase.end(); itFind++)
        {
            if (*it == *itFind)
                found++;
        }
        if (found > 1)
        {
            std::ostringstream oss;
            oss << "The file has duplicates: " << *it;
            throw std::runtime_error(oss.str());
        }
        ++it;
    }
}

void BitcoinExchange::putDataBase(const std::string& fileName)
{
    std::ifstream ifs(fileName.c_str());
    if (!ifs)
    {
        throw std::runtime_error("Error: cannot open file '" + fileName + "'");
    }
    
    std::string line;
    
    while (std::getline(ifs, line))
    {
        line = removeSpaces(line);
        _dataBase.push_back(line);
    }

    if (_dataBase[0] != "date,exchange_rate" && !_dataBase.empty())
        throw std::runtime_error("The table header in the file does not match the subject.");  
    
    findDuplicates(_dataBase);
 
    ifs.close();
}

void BitcoinExchange::putFileContent(const std::string& fileName)
{
    std::ifstream ifs(fileName.c_str());
    if (!ifs)
    {
        throw std::runtime_error("could not open file.");
    }
    
    std::string line;
    
    while (std::getline(ifs, line))
    {
        line = removeSpaces(line);
        _fileContent.push_back(line);
    }

    if (_fileContent[0] != "date|value" && !_fileContent.empty())
        throw std::runtime_error("The table header in the file does not match the subject.");
        
    findDuplicates(_fileContent);
    
    ifs.close();
} 

void BitcoinExchange::findValue(const std::deque<std::string>& dataBase, const std::deque<std::string>& dataFile)
{
    for (std::deque<std::string>::const_iterator it = dataFile.begin() + 1; it != dataFile.end(); ++it)
    {
        std::string lineFileOriginal = *it;
        std::string lineFile = *it;

        if (lineFileOriginal.empty())
            continue;

        try
        {
            lineFile = myRegexReplace(lineFile, "-|", ' ');
            std::deque<float> tabLine = ftSplitToFloat(lineFile, ' ');

            if (!isValidDate(tabLine[0], tabLine[1], tabLine[2]))
                throw std::runtime_error("bad input => " + lineFileOriginal.substr(0, 10));

            if ((tabLine[3] > 1000) && !dataFile.empty())
                throw std::runtime_error("Error: too large a number.");

            std::deque<std::string>::const_iterator itdb = std::lower_bound(dataBase.begin(), dataBase.end(), lineFileOriginal.substr(0, 10));

            if (itdb == dataBase.end())
            {
                if (!dataBase.empty())
                    itdb = --dataBase.end();
            }
            else if (itdb->substr(0, 10) != lineFileOriginal.substr(0, 10))
            {
                if (itdb != dataBase.begin())
                    itdb--;
            }

            if (itdb->substr(0, 4) == "date")
            {
                throw std::runtime_error("The date is too low");
            }

            std::string dbLine = *itdb;
            dbLine = myRegexReplace(dbLine, "-,", ' ');
            std::deque<float> dbTab = ftSplitToFloat(dbLine, ' ');
             
            std::cout << lineFileOriginal.substr(0, 10) << " => " << formatNumber(tabLine[3]) << " = " << formatNumber(tabLine[3] * dbTab[3]) << std::endl;

        } 
        catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }
    }
}
