/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:56:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/29 20:32:33 by rhanitra         ###   ########.fr       */
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
        return (groupIndex);

    std::vector<size_t> jacob;
    jacob.push_back(3);
    size_t j1 = 3, j2 = 1;
    while (j1 < maxIndex)
    {
        j1 = j1 + 2 * j2;
        j2 = jacob.back();
        jacob.push_back(j1);
    }

    return (jacob);
}

/*std::vector<size_t> PmergeMe::VecGenerateJacobsthal(size_t maxIndex)
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
}*/

/*std::vector<int> PmergeMe::fordJohnsonVecSort(std::vector<int> inputMax)
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

    std::map<int, int> map;
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        map.insert(std::pair<int, int>(it->first, it->second));
    }

    std::vector<int> MinS;
    for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it)
    {
            MinS.push_back(map[*it]);
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
               
        size_t max_pos = std::min(sorted.size(), index + i + 1);
        std::vector<int>::iterator xi_pos = sorted.begin() + max_pos;
        
        std::vector<int>::iterator insert_pos = std::lower_bound(sorted.begin(), xi_pos, MinS[index]);
        sorted.insert(insert_pos, MinS[index]);

        std::cout << "i: " << i << "    index: " << index << "    Min: " << sorted[index] << std::endl;

    }

    if (single != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), single);
        sorted.insert(pos, single);
    }
    return (sorted);
}*/


std::vector<size_t> PmergeMe::VecGenerateJacobsthal(size_t maxIndex)
{
    std::vector<size_t> jacob;
    if (maxIndex == 0)
        return jacob;

    // Ajouter les indices 0 et 1
    jacob.push_back(0);
    if (maxIndex == 1)
        return jacob;

    jacob.push_back(1);
    if (maxIndex <= 2)
        return jacob;

    // Générer la séquence Jacobsthal à partir de 3
    size_t j1 = 1, j2 = 1; // j1 = Jn, j2 = Jn-1
    while (j1 < maxIndex)
    {
        j1 = j1 + 2 * j2; // Jn+1 = Jn + 2 * Jn-1
        j2 = jacob.back();
        jacob.push_back(j1);
    }

    // S'assurer que le dernier indice est <= maxIndex - 1
    if (!jacob.empty() && jacob.back() > maxIndex - 1)
        jacob.pop_back();

    return jacob;
}

std::vector<int> PmergeMe::fordJohnsonVecSort(std::vector<int> inputMax)
{
    if (inputMax.size() <= 1)
        return (inputMax);

    int single = -1;
    std::vector<int> maxS;
    std::vector<int> minS;
    std::vector<std::pair<int, int> > pairs;

    for (int i = 0; i + 1 < static_cast<int>(inputMax.size()); i += 2)
    {
        if (inputMax[i] < inputMax[i + 1])
        {
            pairs.push_back(std::pair<int, int>(inputMax[i + 1], inputMax[i]));
        }
        else
        {
            pairs.push_back(std::pair<int, int>(inputMax[i], inputMax[i + 1]));
        }
        maxS.push_back(pairs[pairs.size() - 1].first);
        minS.push_back(pairs[pairs.size() - 1].second);
    }

    if (inputMax.size() % 2 != 0)
        single = inputMax[inputMax.size() - 1];

    std::vector<int> maxSorted = fordJohnsonVecSort(maxS);

    std::map<int, int> mapMin;
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        mapMin.insert(std::pair<int, int>(it->first, it->second));
    }

    if (!minS.empty())
    {
        maxSorted.insert(maxSorted.begin(), mapMin[maxSorted[0]]);
    }


    std::vector<size_t> jacobG = VecGenerateJacobsthal(minS.size());

    for_each(jacobG.begin(), jacobG.end(), displayArray);
    std::cout  << std::endl;

    size_t i = 0;
    size_t limit = 0;

    for (size_t j = 0; j < jacobG.size(); j++)
    {
        size_t index = jacobG[j] - 1;
        
        if (index >= maxSorted.size())
        {
            index = maxSorted.size() - 1;
        }
        
        while (index != limit && i < maxSorted.size())
        {      
            if (index == 0)
                break;
            size_t max_pos = std::min(maxSorted.size(), index + i + 1);
            std::vector<int>::iterator xi_pos = maxSorted.begin() + max_pos;
            
            int to_insert = mapMin[maxSorted[index]];
            
            std::cout  << "ti: " << to_insert <<std::endl;
            
            
            std::vector<int>::iterator insert_pos = std::lower_bound(maxSorted.begin(), xi_pos, to_insert);
            maxSorted.insert(insert_pos, to_insert);
            
            i++;
            index--;
        }
        limit = jacobG[j] - 1;
    }

    if (single != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(maxSorted.begin(), maxSorted.end(), single);
        maxSorted.insert(pos, single);
    }

    return (maxSorted);
}


void PmergeMe::PmergeMeVector()
{
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

    std::map<int, int> mapMin;

    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        mapMin.insert(std::pair<int, int>(it->first, it->second));
    }

    _sortedVec = MaxSorted;

    std::cout << "maxSorted: ";
    for_each(MaxSorted.begin(), MaxSorted.end(), displayArray);
    std::cout << std::endl;
    
    if (!minX.empty())
    {
        _sortedVec.insert(_sortedVec.begin(), mapMin[MaxSorted[0]]);
    }

    std::vector<size_t> jacobG = VecgenerateJacobsthalGroup(minX.size());

    size_t i = 0;
    size_t limit = 0;

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


