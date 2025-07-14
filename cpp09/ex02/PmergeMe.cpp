/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:56:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/14 19:24:35 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::string& args) : _timeVec(0), _timeDeq(0)
{

    if (args.empty())
        throw std::runtime_error("no number to sort");
        
    std::istringstream iss(args);
    std::string token;

    while (iss >> token)
    {
        if (!isNumeric(token))
            throw std::runtime_error("invalid token");

        _input.push_back(static_cast<int>(fromFloat(token)));
    }
    
    findDuplicates(_input);
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _input = other._input;
        _sortedVec = other._sortedVec;
        _sortedDeq = other._sortedDeq;
        _timeVec = other._timeVec;
        _timeDeq = other._timeDeq;
    }
    return (*this);
    
}

PmergeMe::~PmergeMe() {};

void PmergeMe::setTimeVec(double time)
{
    _timeVec = time;
}

void PmergeMe::setTimeDeq(double time)
{
    _timeDeq = time;
}

double PmergeMe::getTimeVec() const
{
    return _timeVec;
}

double PmergeMe::getTimeDeq() const
{
    return _timeDeq;
}

const std::vector<int>& PmergeMe::getInput() const
{
    return (_input);
}

const std::vector<int>& PmergeMe::getSortedVec() const
{
    return (_sortedVec);
}

const std::deque<int>& PmergeMe::getSortedDeq() const
{
    return (_sortedDeq);
}


bool PmergeMe::isNumeric(const std::string &str)
{
    std::istringstream iss(str);
    float f;
    
    iss >> std::noskipws >> f;
    
    return (iss.eof() && !iss.fail());
}

float PmergeMe::fromFloat(const std::string& literal)
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

void PmergeMe::findDuplicates(std::vector<int>& input)
{   
    if (input.empty())
        throw std::runtime_error("Empty file!!!!");
        
    int found = 0;
    std::vector<int>::iterator it = input.begin();
    
    while (it != input.end())
    {
        found = 0;
        for (std::vector<int>::iterator itFind = input.begin(); itFind != input.end(); itFind++)
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

void PmergeMe::run()
{
    for (std::vector<int>::iterator it = _input.begin(); it != _input.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}


/*void PmergeMe::mergeInsertSortVector(std::vector<int>& arr)
{
    if (arr.size() <= 1) return;

    // Étape 1 : Création des paires
    std::vector<int> bigs, smalls;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (i + 1 < arr.size()) {
            if (arr[i] > arr[i + 1]) {
                bigs.push_back(arr[i]);
                smalls.push_back(arr[i + 1]);
            } else {
                bigs.push_back(arr[i + 1]);
                smalls.push_back(arr[i]);
            }
        } else {
            smalls.push_back(arr[i]);
        }
    }

    // Étape 2 : Tri récursif des grands éléments
    mergeInsertSortVector(bigs);

    // Étape 3 : Fusion avec les petits éléments (ordre Jacobsthal simplifié)
    _sortedVec = bigs;
    _sortedVec.insert(_sortedVec.begin(), smalls[0]); // Premier élément

    for (size_t i = 1; i < smalls.size(); ++i)
    {
        auto it = std::lower_bound(_sortedVec.begin(), _sortedVec.end(), smalls[i]);
        _sortedVec.insert(it, smalls[i]);
    }
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr)
{
    if (arr.size() <= 1) return;

    std::deque<int> bigs, smalls;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (i + 1 < arr.size())
        {
            if (arr[i] > arr[i + 1])
            {
                bigs.push_back(arr[i]);
                smalls.push_back(arr[i + 1]);
            } 
            else
            {
                bigs.push_back(arr[i + 1]);
                smalls.push_back(arr[i]);
            }
        }
        else
        {
            smalls.push_back(arr[i]);
        }
    }

    mergeInsertSortDeque(bigs);

    _sortedDeq = bigs;
    _sortedDeq.insert(_sortedDeq.begin(), smalls[0]);

    for (size_t i = 1; i < smalls.size(); ++i) {
        auto it = std::lower_bound(_sortedDeq.begin(), _sortedDeq.end(), smalls[i]);
        _sortedDeq.insert(it, smalls[i]);
    }
}*/

/*void PmergeMe::run() {
    // Afficher la séquence avant tri
    std::cout << "Before: ";
    for (int num : _input) std::cout << num << " ";
    std::cout << "\n";

    // Tri avec std::vector
    {
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> vecCopy = _input;
        mergeInsertSortVector(vecCopy);
        auto end = std::chrono::high_resolution_clock::now();
        _timeVec = std::chrono::duration<double, std::micro>(end - start).count();
    }

    // Tri avec std::deque
    {
        auto start = std::chrono::high_resolution_clock::now();
        std::deque<int> deqCopy(_input.begin(), _input.end());
        mergeInsertSortDeque(deqCopy);
        auto end = std::chrono::high_resolution_clock::now();
        _timeDeq = std::chrono::duration<double, std::micro>(end - start).count();
    }

    // Afficher les résultats
    std::cout << "After:  ";
    for (int num : _sortedVec) std::cout << num << " ";
    std::cout << "\n";

    std::cout << "Time to process a range of " << _input.size() 
                << " elements with std::vector: " << std::fixed << std::setprecision(5) 
                << _timeVec << " us\n";

    std::cout << "Time to process a range of " << _input.size() 
                << " elements with std::deque:  " << std::fixed << std::setprecision(5) 
                << _timeDeq << " us\n";
}*/
