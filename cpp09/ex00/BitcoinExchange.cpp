/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:51:03 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/08 20:08:58 by rhanitra         ###   ########.fr       */
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

void BitcoinExchange::displayValue(float value)
{
    if (value == std::floor(value) && std::abs(value) >= 1e9)
    {
        std::cout << std::fixed << std::setprecision(0) << value << " ";
        std::cout.unsetf(std::ios::fixed);
    }
    else
        std::cout << value << " ";
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
        
    // if (d < 0)
    //     throw std::runtime_error("Error: not a positive number.");
    
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

std::string BitcoinExchange::removeOtherSpace(const std::string& str)
{
    std::string result;
    bool inSpace = false;

    for (size_t i = 0; i < str.size(); ++i)
    {
        if (isspace(static_cast<unsigned char>(str[i])))
        {
            if (!inSpace)
            {
                result += ' ';
                inSpace = true;
            }
        }
        else
        {
            result += str[i];
            inSpace = false;
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



std::deque<float> BitcoinExchange::ftSplitToFloat(const std::deque<std::string>& dataBase, const std::string& str, char delimiter)
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
            
            if ((n < 0 || n > 1000) && !dataBase.empty() && dataBase[0] == "date | value")
                throw std::runtime_error("Error: too large a number.");
            
            output.push_back(fromFloat(token));
        }
    }
    std::ostringstream oss;
    oss << "bad input => " << output[0] << "-" << output[1] << "-" << output[2];
    std::string err = oss.str();
    
    if (!isValidDate(output[0], output[1], output[2]))
        throw std::runtime_error(err);
        
    return (output);
}

void BitcoinExchange::findDuplicates(std::deque<std::string>& dataBase)
{   
    if (dataBase.empty())
        throw std::runtime_error("The data.csv is empty!!!");
        
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
        line = removeOtherSpace(line);
        _fileContent.push_back(line);
    }

    if (_fileContent[0] != "date | value" && !_fileContent.empty())
        throw std::runtime_error("The table header in the file does not match the subject.");
        
    findDuplicates(_fileContent);
    
    ifs.close();
} 

void BitcoinExchange::findValue(const std::deque<std::string>& dataBase, const std::deque<std::string>& dataFile)
{
    if (dataFile.empty())
        throw std::runtime_error("The input.txt is empty!!!");
    if (dataBase.empty())
        throw std::runtime_error("The data.csv is empty!!!");

    std::string lineFile;
    std::string lineDataBase;
    std::deque<float> tabLine;
    
    (void)dataBase;

    for (std::deque<std::string>::const_iterator it = dataFile.begin() + 1; it != dataFile.end(); ++it)
    {
        lineFile = *it;
        lineFile = myRegexReplace(lineFile, "-|", ' ');
        lineFile = removeOtherSpace(lineFile);
        
        try
        {
            tabLine = ftSplitToFloat(dataFile, lineFile, ' ');
 
            for (std::deque<float>::const_iterator itTabLine = tabLine.begin(); itTabLine != tabLine.end(); ++itTabLine)
            {
                displayValue(*itTabLine);
            }
            std::cout << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}



