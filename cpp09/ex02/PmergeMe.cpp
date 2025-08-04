/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:56:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/30 19:25:58 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(const std::string& args) : _timeVec(0), _timeDeq(0)
{
    if (args.empty())
        throw std::runtime_error("no number to sort");

    std::istringstream iss(args);
    std::string token;
    long input;

    while (iss >> token)
    {
        if (!isNumeric(token))
            throw std::runtime_error("invalid token");

        std::istringstream litteral(token);
        if (!(litteral >> input))
            throw std::runtime_error("conversion to integer: impossible");

        if (input < 0)
            throw std::runtime_error(token + " is not a positive number.");

        if (input > std::numeric_limits<int>::max())
            throw std::runtime_error("input integer out of range: " + token);

        int final = static_cast<int>(input);
        _inputVec.push_back(final);
        _inputDeq.push_back(final);
    }

    findDuplicates(_inputVec);
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) 
{
    if (this != &other)
    {
        _timeVec = other._timeVec;
        _timeDeq = other._timeDeq;
        _inputVec = other._inputVec;
        _inputDeq = other._inputDeq;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {};

bool PmergeMe::isNumeric(const std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == '-' || str[i] == '+')
        {
            continue;
        }
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PmergeMe::findDuplicates(std::vector<int>& input)
{
    if (input.empty())
        throw std::runtime_error("Empty input");

    std::vector<int> sorted = input;

    for (size_t i = 0; i < sorted.size(); ++i)
    {
        for (size_t j = 0; j < sorted.size() - i - 1; ++j)
        {
            if (sorted[j] > sorted[j + 1])
                std::swap(sorted[j], sorted[j + 1]);
        }
    }

    for (size_t i = 0; i < sorted.size() - 1; ++i)
    {
        if (sorted[i] == sorted[i + 1])
        {
            std::ostringstream oss;
            oss << "Duplicate found: " << sorted[i];
            throw std::runtime_error(oss.str());
        }
    }
}

 void PmergeMe::displayArray(size_t i)
 {
    std::cout << i << " ";
 }

bool PmergeMe::isSorted(const std::vector<int>& vec, const std::vector<int> initVec)
{
    if (vec.size() <= 1)
    {
        return true;
    }
    
    for (size_t i = 1; i < vec.size(); ++i)
    {
        if (vec[i] < vec[i - 1])
        {
            std::cout << std::endl;
            std::cerr << "Sorting error at index " << i << ": " 
                      << vec[i - 1] << " > " << vec[i] << std::endl;
            return false;
        }
    }

    if (vec.size() != initVec.size())
    {
        std::cout << std::endl;
        std::cerr << "sizeVec: " << vec.size() << std::endl;
        std::cerr << "sizeInput: " << initVec.size() << std::endl;
        std::cerr << "Error size !!!" << std::endl;
    }
    return true;
}

// VECTOR SIMULATION //////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<size_t> PmergeMe::VecGenerateJacobsthal(size_t maxIndex)
{
    std::vector<size_t> jacobI;
    if (maxIndex <= 1)
        return (jacobI);

    std::vector<size_t> jacob;
    jacob.push_back(1);
    jacob.push_back(1);
    size_t j1 = 1, j2 = 1;
    while (j1 < maxIndex)
    {
        j1 = j1 + 2 * j2;
        j2 = jacob.back();
        jacob.push_back(j1);
    }

    std::vector<size_t> orderIndex;
    size_t prev = 1;
    for (size_t j = 2; j < jacob.size(); ++j)
    {
        size_t curr = jacob[j];
        if (curr > maxIndex)
            curr = maxIndex;
        for (size_t k = curr; k > prev && k <= maxIndex; --k)
            orderIndex.push_back(k - 1);
        prev = curr;
    }

    return (orderIndex);
}

std::vector<int> PmergeMe::PmergeMeVector(std::vector<int> input)
{
    if (input.size() <= 1)
        return (input);
    
    if (input.size() == 2)
    {
        if (input[0] > input[1])
            std::swap(input[0], input[1]);
        return (input);
    }

    int single = -1;
    std::vector<int> current = input;
    if (current.size() % 2 != 0)
    {
        single = current.back();
        current.pop_back();
    }
    
    std::vector<int> maxs;
    std::map<int, int> maxToMin;
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < current.size(); i += 2)
    {
        if (current[i] > current[i+1])
            pairs.push_back(std::make_pair(current[i], current[i+1]));
        else
            pairs.push_back(std::make_pair(current[i+1], current[i]));
        
        maxs.push_back(pairs.back().first);
        maxToMin[pairs.back().first] = pairs.back().second;
    }

    std::vector<int> sortedMaxs = PmergeMeVector(maxs);
    
    std::vector<int> sortedVec = sortedMaxs;
    
    size_t inserted = 0;
    if (!sortedMaxs.empty())
    {
        int firstMin = maxToMin[sortedMaxs[0]];
        sortedVec.insert(sortedVec.begin(), firstMin);
        
        maxToMin.erase(sortedMaxs[0]);
        
        inserted++;
    }

    std::vector<size_t> orderIndex = VecGenerateJacobsthal(pairs.size());

    for (size_t j = 0; j < orderIndex.size(); ++j)
    {
        size_t index = orderIndex[j];

        if (index < sortedMaxs.size() && maxToMin.find(sortedMaxs[index]) != maxToMin.end())
        {
            int minToInsert = maxToMin[sortedMaxs[index]];
            
            size_t xiPos = std::min(sortedVec.size(), index + inserted);
            std::vector<int>::iterator itXi = sortedVec.begin() + xiPos;
            
            std::vector<int>::iterator ItPos = std::lower_bound(sortedVec.begin(), itXi, minToInsert);
            sortedVec.insert(ItPos, minToInsert);
            
            inserted++;
            
            maxToMin.erase(sortedMaxs[index]);
        }
    }

    if (single != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(sortedVec.begin(), sortedVec.end(), single);
        sortedVec.insert(pos, single);
    }

    return (sortedVec);
}

// DEQUE SIMULATION /////////////////////////////////////////////////////////////////////////////////////////////////

std::deque<size_t> PmergeMe::DeqGenerateJacobsthal(size_t maxIndex)
{
    std::deque<size_t> jacobI;
    if (maxIndex <= 1)
        return (jacobI);

    std::deque<size_t> jacob;
    jacob.push_back(1);
    jacob.push_back(1);
    size_t j1 = 1, j2 = 1;
    while (j1 < maxIndex)
    {
        j1 = j1 + 2 * j2;
        j2 = jacob.back();
        jacob.push_back(j1);
    }

    std::deque<size_t> orderIndex;
    size_t prev = 1;
    for (size_t j = 2; j < jacob.size(); ++j)
    {
        size_t curr = jacob[j];
        if (curr > maxIndex)
            curr = maxIndex;
        for (size_t k = curr; k > prev && k <= maxIndex; --k)
            orderIndex.push_back(k - 1);
        prev = curr;
    }

    return (orderIndex);
}

std::deque<int> PmergeMe::PmergeMeDeque(std::deque<int> input)
{
    if (input.size() <= 1)
        return (input);
    
    if (input.size() == 2)
    {
        if (input[0] > input[1])
            std::swap(input[0], input[1]);
        return (input);
    }

    int single = -1;
    std::deque<int> current = input;
    if (current.size() % 2 != 0)
    {
        single = current.back();
        current.pop_back();
    }
    
    std::deque<int> maxs;
    std::map<int, int> maxToMin;
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < current.size(); i += 2)
    {
        if (current[i] > current[i+1])
            pairs.push_back(std::make_pair(current[i], current[i+1]));
        else
            pairs.push_back(std::make_pair(current[i+1], current[i]));
        
        maxs.push_back(pairs.back().first);
        maxToMin[pairs.back().first] = pairs.back().second;
    }

    std::deque<int> sortedMaxs = PmergeMeDeque(maxs);
    
    std::deque<int> sortedDeq = sortedMaxs;
    
    std::deque<size_t> maxPos(pairs.size());

    size_t inserted = 0;
    if (!sortedMaxs.empty())
    {
        int firstMin = maxToMin[sortedMaxs[0]];
        sortedDeq.push_front(firstMin);
        
        maxToMin.erase(sortedMaxs[0]);
        
        inserted++;
    }

    std::deque<size_t> orderIndex = DeqGenerateJacobsthal(pairs.size());

    for (size_t j = 0; j < orderIndex.size(); ++j)
    {
        size_t index = orderIndex[j];

        if (index < sortedMaxs.size() && maxToMin.find(sortedMaxs[index]) != maxToMin.end())
        {
            int minToInsert = maxToMin[sortedMaxs[index]];
            
            size_t xiPos = std::min(sortedDeq.size(), index + inserted);
            std::deque<int>::iterator itXi = sortedDeq.begin() + xiPos;
            
            std::deque<int>::iterator ItPos = std::lower_bound(sortedDeq.begin(), itXi, minToInsert);
            sortedDeq.insert(ItPos, minToInsert);
            
            inserted++;
            
            maxToMin.erase(sortedMaxs[index]);
        }
    }

    if (single != -1)
    {
        std::deque<int>::iterator pos = std::lower_bound(sortedDeq.begin(), sortedDeq.end(), single);
        sortedDeq.insert(pos, single);
    }

    return (sortedDeq);
}

// RUN SIMULATION //////////////////////////////////////////////////////////////////////////////////////////////////

void PmergeMe::mergeInsertSort()
{
    std::cout << "Before:  ";
    for_each(_inputVec.begin(), _inputVec.end(), displayArray);
    std::cout << std::endl;
    
    clock_t startTime = clock();
    std::vector<int> sortedVec = PmergeMeVector(_inputVec);
    _timeVec = (clock() - startTime) / (double)CLOCKS_PER_SEC;

    startTime = clock();
    std::deque<int> sortedDeq = PmergeMeDeque(_inputDeq);
    _timeDeq = (clock() - startTime )/ (double)CLOCKS_PER_SEC;

    std::cout << "After:  ";
    for_each(sortedVec.begin(), sortedVec.end(), displayArray);
    std::cout << std::endl;
   
    std::cout << "Time to process a range of " << _inputVec.size() 
                << " elements with std::vector: " << std::fixed << std::setprecision(5) 
                << _timeVec << " us" << std::endl;
                
    std::cout << "Time to process a range of " << _inputDeq.size() 
                << " elements with std::deque:  " << std::fixed << std::setprecision(5) 
                << _timeDeq << " us" << std::endl;
                
    if (!isSorted(sortedVec, _inputVec))
    {
        std::cerr << "Error: MaxSorted is not sorted!" << std::endl;
    }
}
