/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:56:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/22 15:23:45 by rivoinfo         ###   ########.fr       */
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
            throw std::runtime_error("Conversion to integer: impossible");

        if (input < 0)
            throw std::runtime_error("Error: not a positive number.");

        if (input > std::numeric_limits<int>::max())
            throw std::runtime_error("input integer out of range: " + token);

        int final = static_cast<int>(input);
        _inputVec.push_back(final);
        _inputDeq.push_back(final);
    }

    // findDuplicates(_inputVec);

    if (_inputVec.size() % 2 != 0)
        _single = _inputVec[_inputVec.size() - 1];
    else
        _single = -1;
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) 
{
    if (this != &other)
    {
        _single = other._single;
        _inputVec = other._inputVec;
        _inputDeq = other._inputDeq;
        _sortedVec = other._sortedVec;
        _sortedDeq = other._sortedDeq;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {};

void PmergeMe::displayArray(size_t i)
{
    std::cout << i << " ";
}


bool PmergeMe::isNumeric(const std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); ++i)
    {
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

// VECTOR SIMULATION //////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<std::pair<int, int> > PmergeMe::createPairsVec(const std::vector<int>& array)
{
    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < array.size(); i += 2)
    {
        int first = array[i];
        int second = array[i + 1];
        
        if (first < second)
            std::swap(first, second);
        
        pairs.push_back(std::make_pair(first, second));
    }

    return (pairs);
}

std::vector<int> PmergeMe::VecExtractMinX(const std::vector<std::pair<int, int> >& pairs)
{
    std::vector<int> MinX;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        MinX.push_back(pairs[i].second);
    }
    
    if (_single != -1)
        MinX.push_back(_single);

    return (MinX);
}

std::vector<size_t> PmergeMe::VecGenerateJacobsthal(size_t maxIndex)
{
    std::vector<size_t> indices;
    if (maxIndex == 0)
        return (indices);

    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    size_t i = 2;
    
    while (jacob.back() < maxIndex)
    {
        jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
        ++i;
    }

    std::set<size_t> usedIndices;
    
    for (size_t i = 1; i < jacob.size() && jacob[i] < maxIndex; ++i)
    {
        if (usedIndices.find(jacob[i]) == usedIndices.end())
        {
            indices.push_back(jacob[i]);
            usedIndices.insert(jacob[i]);
        }
    }

    for (size_t i = 0; i < maxIndex; ++i)
    {
        if (usedIndices.find(i) == usedIndices.end())
        {
            indices.push_back(i);
            usedIndices.insert(i);
        }
    }

    return (indices);
}

std::vector<int> PmergeMe::fordJohnsonVecSort(std::vector<int> inputMax)
{
    int n = inputMax.size();
    if (n <= 1)
        return inputMax;

    if (n <= 3)
    {
        std::sort(inputMax.begin(), inputMax.end());
        return inputMax;
    }

    std::vector<int> maxS;
    std::vector<int> minS;
    int single = -1;

    for (int i = 0; i + 1 < n; i += 2)
    {
        if (inputMax[i] < inputMax[i + 1])
        {
            minS.push_back(inputMax[i]);
            maxS.push_back(inputMax[i + 1]);
        }
        else
        {
            minS.push_back(inputMax[i + 1]);
            maxS.push_back(inputMax[i]);
        }
    }
    if (n % 2 != 0)
        single = inputMax[n - 1];

    std::vector<int> maxSorted = fordJohnsonVecSort(maxS);

    std::vector<size_t> jacobIndices = VecGenerateJacobsthal(minS.size());
    
    std::vector<bool> inserted(minS.size(), false);

    for (size_t i = 0; i < jacobIndices.size(); ++i)
    {
        size_t index = jacobIndices[i];
        if (index < minS.size() && !inserted[index])
        {
            std::vector<int>::iterator pos = std::lower_bound(maxSorted.begin(), maxSorted.end(), minS[index]);
            maxSorted.insert(pos, minS[index]);
            inserted[index] = true;
        }
    }

    if (single != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(maxSorted.begin(), maxSorted.end(), single);
        maxSorted.insert(pos, single);
    }

    return maxSorted;
}

void PmergeMe::PmergeMeVector()
{
    std::vector<std::pair<int, int> > pairs = createPairsVec(_inputVec);

    std::vector<int> maxX;
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        maxX.push_back(it->first);
    }

    _sortedVec = fordJohnsonVecSort(maxX);
    
    std::vector<int> minX = VecExtractMinX(pairs);

    if (!minX.empty())
    {
        std::vector<int>::iterator minIt = std::min_element(minX.begin(), minX.end());
        std::vector<int>::iterator pos = std::lower_bound(_sortedVec.begin(), _sortedVec.end(), *minIt);
        _sortedVec.insert(pos, *minIt);
        minX.erase(minIt);
    }

    std::vector<size_t> jacob = VecGenerateJacobsthal(minX.size());
    std::vector<bool> inserted(minX.size(), false);

    for (size_t i = 0; i < jacob.size(); ++i)
    {
        size_t index = jacob[i];
        if (index < minX.size() && !inserted[index])
        {
            std::vector<int>::iterator pos = std::lower_bound(_sortedVec.begin(), _sortedVec.end(), minX[index]);
            _sortedVec.insert(pos, minX[index]);
            inserted[index] = true;
        }
    }
}

// DEQUE SIMULATION /////////////////////////////////////////////////////////////////////////////////////////////////

std::deque<std::pair<int, int> > PmergeMe::createPairsDeq(const std::deque<int>& array)
{
    std::deque<std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < array.size(); i += 2)
    {
        int first = array[i];
        int second = array[i + 1];
        
        if (first < second)
            std::swap(first, second);
        
        pairs.push_back(std::make_pair(first, second));
    }

    return (pairs);
}

std::deque<int> PmergeMe::DeqExtractMinX(const std::deque<std::pair<int, int> >& pairs)
{
    std::deque<int> MinX;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        MinX.push_back(pairs[i].second);
    }
    
    if (_single != -1)
        MinX.push_back(_single);

    return (MinX);
}

std::deque<size_t> PmergeMe::DeqGenerateJacobsthal(size_t maxIndex)
{
    std::deque<size_t> indices;
    if (maxIndex == 0)
        return indices;

    std::deque<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    size_t i = 2;
    
    while (jacob.back() < maxIndex)
    {
        jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
        ++i;
    }

    std::set<size_t> usedIndices;
    
    for (size_t i = 1; i < jacob.size() && jacob[i] < maxIndex; ++i)
    {
        if (usedIndices.find(jacob[i]) == usedIndices.end())
        {
            indices.push_back(jacob[i]);
            usedIndices.insert(jacob[i]);
        }
    }

    for (size_t i = 0; i < maxIndex; ++i)
    {
        if (usedIndices.find(i) == usedIndices.end())
        {
            indices.push_back(i);
            usedIndices.insert(i);
        }
    }

    return indices;
}

std::deque<int> PmergeMe::fordJohnsonDeqSort(std::deque<int> inputMax)
{
    int n = inputMax.size();
    if (n <= 1)
        return inputMax;

    if (n <= 3)
    {
        std::sort(inputMax.begin(), inputMax.end());
        return inputMax;
    }

    std::deque<int> maxS;
    std::deque<int> minS;
    int single = -1;

    for (int i = 0; i + 1 < n; i += 2)
    {
        if (inputMax[i] < inputMax[i + 1])
        {
            minS.push_back(inputMax[i]);
            maxS.push_back(inputMax[i + 1]);
        }
        else
        {
            minS.push_back(inputMax[i + 1]);
            maxS.push_back(inputMax[i]);
        }
    }
    if (n % 2 != 0)
        single = inputMax[n - 1];

    std::deque<int> maxSorted = fordJohnsonDeqSort(maxS);

    std::deque<size_t> jacobIndices = DeqGenerateJacobsthal(minS.size());
    std::deque<bool> inserted(minS.size(), false);

    for (size_t i = 0; i < jacobIndices.size(); ++i)
    {
        size_t index = jacobIndices[i];
        if (index < minS.size() && !inserted[index])
        {
            std::deque<int>::iterator pos = std::lower_bound(maxSorted.begin(), maxSorted.end(), minS[index]);
            maxSorted.insert(pos, minS[index]);
            inserted[index] = true;
        }
    }

    if (single != -1)
    {
        std::deque<int>::iterator pos = std::lower_bound(maxSorted.begin(), maxSorted.end(), single);
        maxSorted.insert(pos, single);
    }

    return (maxSorted);
}

void PmergeMe::PmergeMeDeque()
{
    std::deque<std::pair<int, int> > pairs = createPairsDeq(_inputDeq);

    std::deque<int> maxX;
    for (std::deque<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        maxX.push_back(it->first);
    }

    _sortedDeq = fordJohnsonDeqSort(maxX);
    
    std::deque<int> minX = DeqExtractMinX(pairs);

    if (!minX.empty())
    {
        std::deque<int>::iterator minIt = std::min_element(minX.begin(), minX.end());
        std::deque<int>::iterator pos = std::lower_bound(_sortedDeq.begin(), _sortedDeq.end(), *minIt);
        _sortedDeq.insert(pos, *minIt);
        minX.erase(minIt);
    }

    std::deque<size_t> jacob = DeqGenerateJacobsthal(minX.size());
    std::deque<bool> inserted(minX.size(), false);

    for (size_t i = 0; i < jacob.size(); ++i)
    {
        size_t index = jacob[i];
        if (index < minX.size() && !inserted[index])
        {
            std::deque<int>::iterator pos = std::lower_bound(_sortedDeq.begin(), _sortedDeq.end(), minX[index]);
            _sortedDeq.insert(pos, minX[index]);
            inserted[index] = true;
        }
    }
}

// RUN SIMULATION //////////////////////////////////////////////////////////////////////////////////////////////////

void PmergeMe::mergeInsertSort()
{

    for_each(_inputVec.begin(), _inputVec.end(), displayArray);
    std::cout << std::endl;
    
    clock_t startTime = clock();
    PmergeMeVector();
    _timeVec = (clock() - startTime) / (double)CLOCKS_PER_SEC;

    startTime = clock();
    PmergeMeDeque();
    _timeDeq = (clock() - startTime )/ (double)CLOCKS_PER_SEC;


    std::cout << "After:  ";
    for_each(_sortedVec.begin(), _sortedVec.end(), displayArray);
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _inputVec.size() 
                << " elements with std::vector: " << std::fixed << std::setprecision(5) 
                << _timeVec << " us\n";
    std::cout << "Time to process a range of " << _inputDeq.size() 
                << " elements with std::deque:  " << std::fixed << std::setprecision(5) 
                << _timeDeq << " us\n";
}

