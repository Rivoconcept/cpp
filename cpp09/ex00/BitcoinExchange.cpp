/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:51:03 by rhanitra          #+#    #+#             */
/*   Updated: 2025/11/29 16:50:22 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _fileContent(), _listContent(), _dataBase(), _listBase() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        _fileContent = other._fileContent;
        _listContent = other._listContent;
        _dataBase = other._dataBase;
        _listBase = other._listBase;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

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
        throw std::runtime_error("Error: Conversion to float: impossible");
        
    if (d < 0)
        throw std::runtime_error("Error: not a positive number.");
    
    f = static_cast<float>(d);

    if (std::isinf(f) || d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
       return (f > 0 ? std::numeric_limits<float>::infinity() : -std::numeric_limits<float>::infinity());
    else if (std::isnan(f))
        return std::numeric_limits<float>::quiet_NaN();
    
    return (f);
}

const std::set<std::string>& BitcoinExchange::getDataBase() const
{
    return (_dataBase);
}

const std::list<std::string>& BitcoinExchange::getFileContent() const
{
    return (_listContent);
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
    if (year < 1800 || month < 1 || month > 12 || day < 1)
        return false;

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
        days_in_month[1] = 29;

    if (day > days_in_month[month - 1])
        return (false);

    return true;
}

bool BitcoinExchange::checkErrorDate(std::list<std::string> tabDate)
{
    std::string yearSize = getListElement(tabDate, 0);
    std::string monthSize = getListElement(tabDate, 1);
    std::string daySize = getListElement(tabDate, 2);

    return (yearSize.size() == 4 && monthSize.size() == 2 && daySize.size() == 2);
}

const std::string& BitcoinExchange::myRegexReplace(std::string& str, const std::string& charsToReplace, char c)
{
    if (str.empty() || charsToReplace.empty())
        return str;

    for (size_t i = 0; i < str.size(); ++i)
    {
        for (size_t j = 0; j < charsToReplace.size(); ++j)
        {
            if (str[i] == charsToReplace[j])
            {
                str[i] = c;
                break;
            }
        }
    }
    return str;
}

std::string BitcoinExchange::trim(const std::string& str)
{
    size_t start = 0;
    while (start < str.size() && isspace(static_cast<unsigned char>(str[start]))) ++start;
    size_t end = str.size();
    while (end > start && isspace(static_cast<unsigned char>(str[end - 1]))) --end;
    return str.substr(start, end - start);
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

std::list<std::string> BitcoinExchange::simpleSplit(const std::string& str, char delimiter)
{
    std::list<std::string> output;
    std::string token;

    for (std::size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == delimiter)
        {
            if (!token.empty())
                output.push_back(token);
            token.clear();
        }
        else
        {
            token += str[i];
        }
    }

    if (!token.empty())
        output.push_back(token);

    return output;
}


std::list<std::string> BitcoinExchange::ftSplitStr(const std::string& str, char delimiter)
{
    std::list<std::string> output;
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
                throw std::runtime_error("Error: Token invalide: '" + token + "'");
            
            output.push_back((token));
        }
    }

    return (output);
}

void BitcoinExchange::findDuplicates(std::list<std::string>& dataBase)
{
    if (dataBase.empty())
        throw std::runtime_error("Error: Empty file!!!!");

    if (dataBase.size() == 1)
        return;

    std::list<std::string>::iterator it = dataBase.begin();
    while (it != dataBase.end())
    {
        int found = 0;
        for (std::list<std::string>::iterator itFind = dataBase.begin(); itFind != dataBase.end(); ++itFind)
        {
            if (*it == *itFind)
                found++;
        }
        if (found > 1)
        {
            std::ostringstream oss;
            oss << "The file has duplicates: " << *it;
            throw std::runtime_error("Error: " + oss.str());
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

    if (std::getline(ifs, line))
    {
        line = removeSpaces(line);
        if (line != "date,exchange_rate")
            throw std::runtime_error("Error: The table header in the file does not match the subject.");
    }
    
    while (std::getline(ifs, line))
    {
        line = removeSpaces(line);
        _dataBase.insert(line);
        _listBase.push_back(line);
    }
    
    findDuplicates(_listBase);
    
    ifs.close();
}

void BitcoinExchange::putFileContent(const std::string& fileName)
{
    std::ifstream ifs(fileName.c_str());
    if (!ifs)
        throw std::runtime_error("Error: could not open file.");
    
    std::string line;

    if (!std::getline(ifs, line))
        throw std::runtime_error("Error: Empty file.");
    
    std::string header = removeSpaces(line);
    if (header != "date|value")
        throw std::runtime_error("Error: The table header in the file does not match the subject.");
    
    while (std::getline(ifs, line))
    {
        line = trim(line);
        if (line.empty())
            continue;
        _fileContent.insert(line);
        _listContent.push_back(line);
    }
    findDuplicates(_listContent);
    ifs.close();
}



void findValue(const std::string& dbName, char *inputFileName)
{
    std::istringstream iss(inputFileName);
    std::string file;
    
    if (!(iss >> file))
        throw std::runtime_error("Error: could not open file.");

    BitcoinExchange btc;

    btc.putDataBase(dbName);
    btc.putFileContent(file);
    
    std::list<std::string> dataFile = btc.getFileContent();
    std::set<std::string> dataBase = btc.getDataBase();

    std::list<std::string>::const_iterator it = dataFile.begin();

    for (; it != dataFile.end(); ++it)
    {
        std::string lineFileOriginal = *it;
        std::string lineFile = *it;

        if (lineFileOriginal.empty())
            continue;

        try
        {          
            // lineFile = btc.myRegexReplace(lineFile, "-|", ' ');
            std::list<std::string> tabLine;
            if (lineFileOriginal.find('|') != std::string::npos) {
                tabLine = btc.simpleSplit(lineFile, '|');
            } else {
                throw std::runtime_error("Error: '|' is not found in :" + lineFileOriginal);
            }
            
            if (tabLine.size() > 2)
                throw std::runtime_error("Error: Bad number of argument => " + lineFileOriginal);
                
            std::string strDate = btc.myRegexReplace(getListElement(tabLine, 0), "-", ' ');
            std::string strValue = getListElement(tabLine, 1);
            std::list<std::string> tabDate = btc.ftSplitStr(strDate, ' ');
            std::list<std::string> tabValue = btc.ftSplitStr(strValue, ' ');
                 
            if (tabDate.size() > 3 || tabValue.size() > 1)
                throw std::runtime_error("Error: Bad number of argument => " + lineFileOriginal);
            
            // std::cout << tabLine.size() << std::endl;
            
            if (!btc.checkErrorDate(tabDate))
                throw std::runtime_error("Error: bad input => " + lineFileOriginal.substr(0, lineFileOriginal.find('|')));

            int date_0 = btc.fromFloat(getListElement(tabDate, 0));
            int date_1 = btc.fromFloat(getListElement(tabDate, 1));
            int date_2 = btc.fromFloat(getListElement(tabDate, 2));

            
            if (!btc.isValidDate(date_0, date_1, date_2))
                throw std::runtime_error("Error: bad input => " + lineFileOriginal.substr(0, lineFileOriginal.find('|')));
            
            float value = btc.fromFloat(getListElement(tabValue, 0));
            
            if ((value > 1000) && !dataFile.empty())
                throw std::runtime_error("Error: too large a number.");

            if ((value == -0) && !dataFile.empty())
                value = 0;
            
            std::string toFind = lineFileOriginal.substr(0, 10);

            if (!dataBase.empty() && toFind < (*dataBase.begin()).substr(0, 10))
            {
                throw std::runtime_error("Error: The date is too low");
            }

            std::set<std::string>::const_iterator itdb = std::lower_bound(dataBase.begin(), dataBase.end(), toFind);

            if (itdb == dataBase.end())
            {
                itdb = --dataBase.end();
            }
            else if (itdb->substr(0, 10) != toFind)
            {
                if (itdb != dataBase.begin())
                    --itdb;
            }

            if (!dataBase.empty() && toFind < (*dataBase.begin()).substr(0, 10))
                throw std::runtime_error("Error: The date is too low");

            std::string dbLine = *itdb;
            
            dbLine = btc.myRegexReplace(dbLine, "-,", ' ');
            std::list<std::string> dbTab = btc.ftSplitStr(dbLine, ' ');

            float dbTab_3 = btc.fromFloat(getListElement(dbTab, 3));

            std::cout << lineFileOriginal.substr(0, 10) << " => " << btc.formatNumber(value) << " = " << btc.formatNumber(value * dbTab_3) << std::endl;
        } 
        catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }
    }
}
          if (tabLine.size() > 2)
                throw std::runtime_error("Error: Bad number of argument => " + lineFileOriginal);