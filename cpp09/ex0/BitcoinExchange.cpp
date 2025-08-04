/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:51:03 by rhanitra          #+#    #+#             */
/*   Updated: 2025/08/04 16:32:53 by rhanitra         ###   ########.fr       */
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
        throw std::runtime_error("not a positive number.");
    
    f = static_cast<float>(d);

    if (std::isinf(f) || d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
       return (f > 0 ? std::numeric_limits<float>::infinity() : -std::numeric_limits<float>::infinity());
    else if (std::isnan(f))
        return std::numeric_limits<float>::quiet_NaN();
    
    return (f);
}

const std::list<std::string>& BitcoinExchange::getDataBase() const
{
    return (_dataBase);
}

const std::list<std::string>& BitcoinExchange::getFileContent() const
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

std::list<float> BitcoinExchange::ftSplitToFloat(const std::string& str, char delimiter)
{
    std::list<float> output;
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

void BitcoinExchange::findDuplicates(std::list<std::string>& dataBase)
{   
    std::string dataBase_1 = getListElement(dataBase, 1);
    
    if (dataBase.empty() || (!dataBase.empty() && dataBase_1.empty()))
        throw std::runtime_error("Empty file!!!!");
        
    int found = 0;
    std::list<std::string>::iterator it = dataBase.begin();
    
    while (it != dataBase.end())
    {
        found = 0;
        for (std::list<std::string>::iterator itFind = dataBase.begin(); itFind != dataBase.end(); itFind++)
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
        throw std::runtime_error("cannot open file '" + fileName + "'");
    }
    
    std::string line;
    
    while (std::getline(ifs, line))
    {
        line = removeSpaces(line);
        _dataBase.push_back(line);
    }

    std::string dataBase_0 = getListElement(_dataBase, 0);
    if (dataBase_0 != "date,exchange_rate" && !_dataBase.empty())
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

    std::string fileContent_0 = getListElement(_fileContent, 0);

    if (fileContent_0 != "date|value" && !_fileContent.empty())
        throw std::runtime_error("The table header in the file does not match the subject.");
        
    findDuplicates(_fileContent);
    
    ifs.close();
} 

void findValue(const std::string& dbName, char *inputFileName)
{
    std::istringstream iss(inputFileName);
    std::string file;
    
    if (!(iss >> file))
        throw std::runtime_error("could not open file.");

    BitcoinExchange btc;

    btc.putDataBase(dbName);
    btc.putFileContent(file);
    std::list<std::string> dataFile = btc.getFileContent();
    std::list<std::string> dataBase = btc.getDataBase();

    std::list<std::string>::const_iterator it = dataFile.begin();
    ++it;

    for (; it != dataFile.end(); ++it)
    {
        std::string lineFileOriginal = *it;
        std::string lineFile = *it;

        if (lineFileOriginal.empty())
            continue;

        try
        {
            lineFile = btc.myRegexReplace(lineFile, "-|", ' ');
            std::list<float> tabLine = btc.ftSplitToFloat(lineFile, ' ');

            int tabLine_0 = getListElement(tabLine, 0);
            int tabLine_1 = getListElement(tabLine, 1);
            int tabLine_2 = getListElement(tabLine, 2);
            
            if (!btc.isValidDate(tabLine_0, tabLine_1, tabLine_2))
            throw std::runtime_error("bad input => " + lineFileOriginal.substr(0, 10));
            
            float tabLine_3 = getListElement(tabLine, 3);
            
            if ((tabLine_3 > 1000) && !dataFile.empty())
                throw std::runtime_error("too large a number.");

            if ((tabLine_3 == -0) && !dataFile.empty())
                tabLine_3 = 0;
            
            std::list<std::string>::const_iterator itdb = std::lower_bound(dataBase.begin(), dataBase.end(), lineFileOriginal.substr(0, 10));

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
                throw std::runtime_error("The date is too low");

            std::string dbLine = *itdb;
            dbLine = btc.myRegexReplace(dbLine, "-,", ' ');
            std::list<float> dbTab = btc.ftSplitToFloat(dbLine, ' ');

            float dbTab_3 = getListElement(dbTab, 3);

            std::cout << lineFileOriginal.substr(0, 10) << " => " << btc.formatNumber(tabLine_3) << " = " << btc.formatNumber(tabLine_3 * dbTab_3) << std::endl;

        } 
        catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }
    }
}
