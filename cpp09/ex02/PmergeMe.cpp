/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:56:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/29 15:57:56 by rivoinfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::string& args) : _sizeTab(0), _timeVec(0), _timeDeq(0)
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
        // _inputDeq.push_back(final);
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
        _sizeTab = other._sizeTab;
        _inputVec = other._inputVec;
        _inputDeq = other._inputDeq;
        _sortedVec = other._sortedVec;
        _sortedDeq = other._sortedDeq;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{};

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

std::vector<std::pair<int, int> > PmergeMe::createPairsVec(const std::vector<int>& input)
{
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        if (input[i] < input[i + 1])
        {
            pairs.push_back(std::pair<int, int>(input[i + 1], input[i]));
        } else
        {
            pairs.push_back(std::pair<int, int>(input[i], input[i + 1]));
        }
    }
    return pairs;
}

std::vector<size_t> PmergeMe::VecGenerateJacobsthal(size_t maxIndex)
{
    std::vector<size_t> indices;
    if (maxIndex <= 2)
    {
        for (size_t i = 0; i < maxIndex; ++i)
        {
            indices.push_back(i);
        }
        return indices;
    }

    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    size_t i = 2;
    while (jacob.back() < maxIndex)
    {
        jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
        ++i;
    }

    std::vector<std::vector<size_t> > groups;
    size_t prev = 1;
    for (size_t j = 2; j < jacob.size() && prev < maxIndex; ++j)
    {
        std::vector<size_t> group;
        size_t start = prev;
        size_t end = jacob[j] < maxIndex ? jacob[j] : maxIndex;
        for (size_t k = end; k > start && k <= maxIndex; --k)
        {
            group.push_back(k - 1);
        }
        if (!group.empty())
        {
            groups.push_back(group);
        }
        prev = jacob[j];
    }

    std::set<size_t> usedIndices;
    for (size_t g = 0; g < groups.size(); ++g)
    {
        for (size_t k = 0; k < groups[g].size(); ++k)
        {
            usedIndices.insert(groups[g][k]);
        }
    }
    std::vector<size_t> remaining;
    for (size_t i = 0; i < maxIndex; ++i)
    {
        if (usedIndices.find(i) == usedIndices.end())
        {
            remaining.push_back(i);
        }
    }

    for (size_t g = 0; g < groups.size(); ++g)
    {
        for (size_t k = 0; k < groups[g].size(); ++k)
        {
            indices.push_back(groups[g][k]);
        }
    }
    for (size_t k = 0; k < remaining.size(); ++k)
    {
        indices.push_back(remaining[k]);
    }

    return indices;
}

/*std::vector<size_t> PmergeMe::VecgenerateJacobsthalGroup(size_t maxIndex)
{
    std::vector<size_t> groupSizes;
    std::vector<size_t> groupIndex(maxIndex, 0);
    if (maxIndex == 0)
        return groupSizes;

    std::vector<size_t> jacob;
    jacob.push_back(3);
    size_t j1 = 3, j2 = 1;
    while (j1 < maxIndex)
    {
        j1 = j1 + 2 * j2;
        j2 = jacob.back();
        jacob.push_back(j1);
    }

    for (size_t i = 0; i < jacob.size(); ++i)
    {
        groupIndex[jacob[i]] = jacob[i];
    }

    return groupIndex;
}*/

std::vector<size_t> PmergeMe::VecgenerateJacobsthalGroup(size_t maxIndex)
{
    std::vector<size_t> groupIndex;
    if (maxIndex <= 3)
        return groupIndex;

    std::vector<size_t> jacob;
    jacob.push_back(3);
    size_t j1 = 3, j2 = 1;
    while (j1 < maxIndex)
    {
        j1 = j1 + 2 * j2;
        j2 = jacob.back();
        jacob.push_back(j1);
    }

    return jacob;
}

std::vector<int> PmergeMe::fordJohnsonVecSort(std::vector<int> inputMax)
{
    size_t n = static_cast<size_t>(inputMax.size());
    if (n <= 1)
    {
        return inputMax;
    }

    std::vector<std::pair<int, int> > pairs;
    int single = -1;

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        if (inputMax[i] < inputMax[i + 1])
        {
            pairs.push_back(std::make_pair(inputMax[i + 1], inputMax[i]));
        }
        else
        {
            pairs.push_back(std::make_pair(inputMax[i], inputMax[i + 1]));
        }
    }

    if (n % 2 != 0)
    {
        single = inputMax[n - 1];
    }

    std::vector<int> maxS;
    for (std::vector<std::pair<int, int> >::iterator it =  pairs.begin(); it != pairs.end(); it++)
    {
        maxS.push_back(it->first);
    }

    std::vector<int> sorted = fordJohnsonVecSort(maxS);


    for_each(sorted.begin(), sorted.end(), displayArray);
    std::cout << std::endl;

    size_t size = sorted.empty() ? 0 : static_cast<unsigned int>(sorted.back() + 1);
    unsigned int* map = new unsigned int[size];


    for (std::vector<std::pair<int, int> >::iterator it =  pairs.begin(); it != pairs.end(); it++)
    {
        if (it->first < static_cast<int>(size))
        {
            map[it->first] = it->second;
        }
    }

    std::vector<int> MinS;
    for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it)
    {
        if (*it < static_cast<int>(size))
        {
            MinS.push_back(map[*it]);
        }
    }

    if (!MinS.empty())
    {
        sorted.insert(sorted.begin(), MinS[0]);
    }

    std::cout << "MinFirst: " << MinS[0] << std::endl;


    std::vector<size_t> jacob = VecGenerateJacobsthal(MinS.size());
    
    for (size_t i = 0; i < jacob.size() && i < MinS.size(); ++i)
    {
        size_t index = jacob[i];
        if (index >= MinS.size() || index == 0)
            continue;
               
        
        std::vector<int>::iterator insert_pos = std::lower_bound(sorted.begin(), sorted.end(), MinS[index]);
        sorted.insert(insert_pos, MinS[index]);

        std::cout << "i: " << i << "    index: " << index << "    Min: " << sorted[index] << std::endl;

    }

    if (single != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), single);
        sorted.insert(pos, single);
    }

    return (sorted);
}



void PmergeMe::PmergeMeVector()
{
    // if (_inputVec.size() <= 3)
    // {
    //     std::sort(_inputVec.begin(), _inputVec.end());
    //     _sortedVec = _inputVec;
    //     return ;
    // }
    
    std::vector<std::pair<int, int> > pairs = createPairsVec(_inputVec);

    std::vector<int> maxX, minX;
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        maxX.push_back(it->first);
        minX.push_back(it->second);
        if (_sizeTab < it->second)
            _sizeTab = it->second;
    }

    std::vector<int> MaxSorted = fordJohnsonVecSort(maxX);

    size_t sizeMapMax = MaxSorted.empty() ? 0 : static_cast<size_t>(_sizeTab + 1);
    unsigned int mapMax[sizeMapMax];
    unsigned int* mapMin = new unsigned int[static_cast<unsigned int>(MaxSorted.back() + 1)];

    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        mapMax[it->second] = it->first; // Pas de condition ici
        mapMin[it->first] = it->second;  // Pas de condition ici
    }

    _sortedVec = MaxSorted;

    for_each(MaxSorted.begin(), MaxSorted.end(), displayArray);
    std::cout << std::endl;
    
    if (!minX.empty())
    {
        _sortedVec.insert(_sortedVec.begin(), mapMin[MaxSorted[0]]);
    }
    (void)mapMax;

    std::vector<size_t> jacobG = VecgenerateJacobsthalGroup(minX.size());

    size_t i = 0;
    size_t limit = 0;

    for_each(jacobG.begin(), jacobG.end(), displayArray);
    std::cout << std::endl;

    for (size_t j = 0; j < jacobG.size(); j++)
    {
        
        size_t index = jacobG[j] - 1;
        
        if (index >= MaxSorted.size())
        {
            index = MaxSorted.size() - 1;
        }
        while (index != limit && i < minX.size() )
        {      
            if (index == 0)
                break;
            size_t max_pos = std::min(_sortedVec.size(), index + i + 1);
            std::vector<int>::iterator xi_pos = _sortedVec.begin() + max_pos;
            
            std::cout <<  "  i: " << i << "    index: " << index  << "    limit: " << limit << "    Min: " << MaxSorted[index] << std::endl;
            int to_insert = mapMin[MaxSorted[index]];
            std::cout << to_insert << std::endl;

            std::vector<int>::iterator insert_pos = std::lower_bound(_sortedVec.begin(), xi_pos, to_insert);
            _sortedVec.insert(insert_pos, to_insert);
            
            i++;
            index--;
        }
        limit = jacobG[j] - 1;

    }

    if (_single != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(_sortedVec.begin(), _sortedVec.end(), _single);
        _sortedVec.insert(pos, _single);
    }
    
    delete[] mapMin;
}

// DEQUE SIMULATION /////////////////////////////////////////////////////////////////////////////////////////////////


// RUN SIMULATION //////////////////////////////////////////////////////////////////////////////////////////////////

void PmergeMe::mergeInsertSort()
{
    std::cout << "Before:  ";
    for_each(_inputVec.begin(), _inputVec.end(), displayArray);
    std::cout << std::endl;
    
    clock_t startTime = clock();
    PmergeMeVector();
    _timeVec = (clock() - startTime) / (double)CLOCKS_PER_SEC;

    /*startTime = clock();
    PmergeMeDeque();
    _timeDeq = (clock() - startTime )/ (double)CLOCKS_PER_SEC;*/

    std::cout << "After:  ";
    for_each(_sortedVec.begin(), _sortedVec.end(), displayArray);
    std::cout << std::endl;
   
    std::cout << "Time to process a range of " << _inputVec.size() 
                << " elements with std::vector: " << std::fixed << std::setprecision(5) 
                << _timeVec << " us" << std::endl;
                
    /*std::cout << "Time to process a range of " << _inputDeq.size() 
                << " elements with std::deque:  " << std::fixed << std::setprecision(5) 
                << _timeDeq << " us" << std::endl;*/
                
    if (!isSorted(_sortedVec, _inputVec))
    {
        std::cerr << "Error: MaxSorted is not sorted!" << std::endl;
    }
}


