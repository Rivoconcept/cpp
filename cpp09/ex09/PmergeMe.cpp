/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:56:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/29 15:16:49 by rivoinfo         ###   ########.fr       */
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

std::vector<int> PmergeMe::VecExtractMinX(const std::vector<std::pair<int, int> >& pairs)
{
    std::vector<int> minX;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        minX.push_back(pairs[i].second);
    }
    return minX;
}


size_t PmergeMe::findIndex(std::vector<int>& array, int value)
{
    for (std::vector<int>::iterator it = array.begin(); it != array.end(); ++it)
    {
        if (*it == value)
            return std::distance(array.begin(), it);
    }
    return std::numeric_limits<size_t>::max();
}

std::vector<int>::iterator PmergeMe::findIt(std::vector<int>& array, int value)
{
    for (std::vector<int>::iterator it = array.begin(); it != array.end(); ++it)
    {
        if (*it == value)
            return (it);
    }
    return (array.end());
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
std::vector<int> PmergeMe::fordJohnsonVecSort(std::vector<int> inputMax)
{
    size_t n = static_cast<size_t>(inputMax.size());
    if (n <= 1)
    {
        return inputMax;
    }

    std::vector<std::pair<int, int> > pairs;
    int single_element = -1; 

    // 1. Create pairs (larger, smaller)
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
        single_element = inputMax[n - 1];
    }

    // 2. Recursively sort the larger elements (main chain)
    std::vector<int> maxS_chain;
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        maxS_chain.push_back(it->first);
    }
    
    std::vector<int> sorted_main_chain = fordJohnsonVecSort(maxS_chain);

    // 3. Prepare MinS for insertion: Create a list of (MinS_value, MaxS_partner_value)
    // This mapping from original MaxS value to MinS value is essential.
    std::vector<std::pair<int, int> > MinS_with_partners_ordered;
    // We need to map sorted_main_chain elements back to their MinS partners.
    // For C++98, if values are large and sparse, std::map is better.
    // If values are within a reasonable range, a vector as a lookup table works (current approach).

    // Determine max value in input to safely resize map
    int max_val_in_input = 0;
    for (size_t i = 0; i < inputMax.size(); ++i) {
        if (inputMax[i] > max_val_in_input) {
            max_val_in_input = inputMax[i];
        }
    }

    std::vector<int> max_val_to_min_val_map;
    // Resize map based on max value present in original input to avoid out-of-bounds access
    if (max_val_in_input >= 0) {
        max_val_to_min_val_map.resize(max_val_in_input + 1, -1);
    }
    
    // Populate the map: MaxS value -> MinS value
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (static_cast<size_t>(it->first) < max_val_to_min_val_map.size())
        {
            max_val_to_min_val_map[it->first] = it->second;
        }
    }

    // Populate MinS_with_partners_ordered based on the sorted_main_chain order
    // This list will contain pairs (min_value, max_partner_value)
    for (std::vector<int>::iterator it = sorted_main_chain.begin(); it != sorted_main_chain.end(); ++it)
    {
        if (static_cast<size_t>(*it) < max_val_to_min_val_map.size() && max_val_to_min_val_map[*it] != -1)
        {
            MinS_with_partners_ordered.push_back(std::make_pair(max_val_to_min_val_map[*it], *it));
        }
    }

    // 4. Generate Jacobsthal insertion sequence for all MinS elements
    std::vector<size_t> jacob_insertion_order = VecGenerateJacobsthal(MinS_with_partners_ordered.size());
    
    // 5. Perform insertions based on Jacobsthal sequence
    for (size_t i = 0; i < jacob_insertion_order.size(); ++i)
    {
        size_t minS_ordered_idx = jacob_insertion_order[i];

        if (minS_ordered_idx >= MinS_with_partners_ordered.size())
            continue;
        
        int value_to_insert = MinS_with_partners_ordered[minS_ordered_idx].first;
        int partner_max_value = MinS_with_partners_ordered[minS_ordered_idx].second; // The original MaxS partner value

        // Find the actual current position of the partner_max_value in sorted_main_chain.
        // This accounts for all previous insertions.
        std::vector<int>::iterator xi_pos = std::lower_bound(sorted_main_chain.begin(), sorted_main_chain.end(), partner_max_value);
        
        // The actual limit for searching is up to (but not including) the element which is `partner_max_value`
        // in the current `sorted_main_chain`. This is because `value_to_insert` is guaranteed to be smaller
        // than its `partner_max_value`, and therefore must come before it.
        std::vector<int>::iterator insert_pos = std::lower_bound(sorted_main_chain.begin(), xi_pos, value_to_insert);
        
        sorted_main_chain.insert(insert_pos, value_to_insert);
    }

    // 6. Insert the single element if it exists
    if (single_element != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(sorted_main_chain.begin(), sorted_main_chain.end(), single_element);
        sorted_main_chain.insert(pos, single_element);
    }

    return sorted_main_chain;
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
    
    for_each(_sortedVec.begin(), _sortedVec.end(), displayArray);
    std::cout << std::endl;

    std::vector<int> minX = VecExtractMinX(pairs);

    size_t size = _sortedVec.empty() ? 0 : _sortedVec.back() + 1;

    std::vector<int> map(size, 0);

    for (std::vector<std::pair<int, int> >::iterator it =  pairs.begin(); it != pairs.end(); it++)
    {
        if (it->first< static_cast<int>(map.size()))
        {
            map[it->first] = it->second;
        }
    }

    std::vector<int> MinSorted;
    for (std::vector<int>::iterator it = _sortedVec.begin(); it != _sortedVec.end(); ++it)
    {
        if (*it < static_cast<int>(map.size()))
        {
            MinSorted.push_back(map[*it]);
        }
    }

    if (!MinSorted.empty())
    {
        _sortedVec.insert(_sortedVec.begin(), MinSorted[0]);
    }

    std::vector<size_t> jacob = VecGenerateJacobsthal(MinSorted.size());

    // std::vector<size_t> jacobG = VecgenerateJacobsthalGroup(MinSorted.size());

    // size_t sizeTab = 0;
    for (size_t i = 0; i < jacob.size() && i < MinSorted.size(); ++i)
    {
        size_t index = jacob[i];
        if (index >= MinSorted.size() || index == 0)
            continue;

        // if (jacobG[i])
        //     sizeTab = jacobG[i];
        
        std::vector<int>::iterator xi_pos = _sortedVec.begin() + std::min(_sortedVec.size(), index + i + 1);

        std::vector<int>::iterator insert_pos = std::lower_bound(_sortedVec.begin(), xi_pos, MinSorted[index]);
        _sortedVec.insert(insert_pos, MinSorted[index]);
        

        std::cout  << "  i: " << i << "    index: " << index << "    Min: " << MinSorted[index] << std::endl;
    }

    if (_single != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(_sortedVec.begin(), _sortedVec.end(), _single);
        _sortedVec.insert(pos, _single);
    }
}

// DEQUE SIMULATION /////////////////////////////////////////////////////////////////////////////////////////////////

std::deque<std::pair<int, int> > PmergeMe::createPairsDeq(const std::deque<int>& input)
{
    std::deque<std::pair<int, int> > pairs;
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

std::deque<int> PmergeMe::DeqExtractMinX(const std::deque<std::pair<int, int> >& pairs)
{
    std::deque<int> minX;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        minX.push_back(pairs[i].second);
    }
    return minX;
}

std::deque<size_t> PmergeMe::DeqGenerateJacobsthal(size_t maxIndex)
{
    std::deque<size_t> indices;
    if (maxIndex <= 2)
    {
        for (size_t i = 0; i < maxIndex; ++i)
        {
            indices.push_back(i);
        }
        return indices;
    }

    std::deque<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    size_t i = 2;
    while (jacob.back() < maxIndex)
    {
        jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
        ++i;
    }

    std::deque<std::deque<size_t> > groups;
    size_t prev = 1;
    for (size_t j = 2; j < jacob.size() && prev < maxIndex; ++j)
    {
        std::deque<size_t> group;
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
    std::deque<size_t> remaining;
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

size_t PmergeMe::findIndex(std::deque<int>& array, int value)
{
    for (std::deque<int>::iterator it = array.begin(); it != array.end(); ++it)
    {
        if (*it == value)
            return std::distance(array.begin(), it);
    }
    return std::numeric_limits<size_t>::max();
}

std::deque<int>::iterator PmergeMe::findIt(std::deque<int>& array, int value)
{
    for (std::deque<int>::iterator it = array.begin(); it != array.end(); ++it)
    {
        if (*it == value)
            return (it);
    }
    return (array.end());
}

std::deque<int> PmergeMe::fordJohnsonDeqSort(std::deque<int> inputMax)
{
    size_t n = static_cast<size_t>(inputMax.size());
    if (n <= 1)
    {
        return inputMax;
    }

    std::deque<std::pair<int, int> > pairs;
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

    std::deque<int> maxS;
    for (std::deque<std::pair<int, int> >::iterator it =  pairs.begin(); it != pairs.end(); it++)
    {
        maxS.push_back(it->first);
    }

    std::deque<int> sorted = fordJohnsonDeqSort(maxS);

    size_t size = sorted.empty() ? 0 : sorted.back() + 1;
    std::deque<int> map(size, 0);

    for (std::deque<std::pair<int, int> >::iterator it =  pairs.begin(); it != pairs.end(); it++)
    {
        if (it->first< static_cast<int>(map.size()))
        {
            map[it->first] = it->second;
        }
    }

    std::deque<int> MinS;
    for (std::deque<int>::iterator it = sorted.begin(); it != sorted.end(); ++it)
    {
        if (*it < static_cast<int>(map.size()))
        {
            MinS.push_back(map[*it]);
        }
    }

    if (!MinS.empty())
    {
        sorted.insert(sorted.begin(), MinS[0]);
    }

    std::deque<size_t> jacob = DeqGenerateJacobsthal(MinS.size());

    for (size_t i = 0; i < jacob.size() && i < MinS.size(); ++i)
    {
        size_t index = jacob[i];
        if (index >= MinS.size() || index == 0)
            continue;

        std::deque<int>::iterator insert_pos = std::lower_bound(sorted.begin(), sorted.end(), MinS[index]);
        sorted.insert(insert_pos, MinS[index]);
        
    }

    if (single != -1)
    {
        std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), single);
        sorted.insert(pos, single);
    }

    return (sorted);
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

    size_t size = _sortedDeq.empty() ? 0 : _sortedDeq.back() + 1;

    std::deque<int> map(size, 0);

    for (std::deque<std::pair<int, int> >::iterator it =  pairs.begin(); it != pairs.end(); it++)
    {
        if (it->first< static_cast<int>(map.size()))
        {
            map[it->first] = it->second;
        }
    }

    std::deque<int> MinSorted;
    for (std::deque<int>::iterator it = _sortedDeq.begin(); it != _sortedDeq.end(); ++it)
    {
        if (*it < static_cast<int>(map.size()))
        {
            MinSorted.push_back(map[*it]);
        }
    }

    if (!MinSorted.empty())
    {
        _sortedDeq.insert(_sortedDeq.begin(), MinSorted[0]);
    }

    std::deque<size_t> jacob = DeqGenerateJacobsthal(MinSorted.size());
    
    for (size_t i = 0; i < jacob.size() && i < MinSorted.size(); ++i)
    {
        size_t index = jacob[i];
        if (index >= MinSorted.size() || index == 0)
            continue;
        
        std::deque<int>::iterator end_pos = _sortedDeq.begin() + std::min(_sortedDeq.size(), index + i + 1);
        
        std::deque<int>::iterator insert_pos = std::lower_bound(_sortedDeq.begin(), end_pos, MinSorted[index]);
        _sortedDeq.insert(insert_pos, MinSorted[index]);

    }

    if (_single != -1)
    {
        std::deque<int>::iterator pos = std::lower_bound(_sortedDeq.begin(), _sortedDeq.end(), _single);
        _sortedDeq.insert(pos, _single);
    }
}

// RUN SIMULATION //////////////////////////////////////////////////////////////////////////////////////////////////

void PmergeMe::mergeInsertSort()
{
    std::cout << "Before:  ";
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
                << _timeVec << " us" << std::endl;
                
    std::cout << "Time to process a range of " << _inputDeq.size() 
                << " elements with std::deque:  " << std::fixed << std::setprecision(5) 
                << _timeDeq << " us" << std::endl;
                
    if (!isSorted(_sortedVec, _inputVec))
    {
        std::cerr << "Error: _sortedVec is not sorted!" << std::endl;
    }
}


