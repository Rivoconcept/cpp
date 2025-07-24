/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:56:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/24 20:56:29 by rhanitra         ###   ########.fr       */
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
        //_inputDeq.push_back(final);
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

    // Générer les nombres de Jacobsthal
    std::vector<size_t> jacob;
    jacob.push_back(0); // J_0
    jacob.push_back(1); // J_1
    size_t i = 2;
    while (jacob.back() < maxIndex)
    {
        jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
        ++i;
    }

    // Créer les groupes avec tailles basées sur les différences de Jacobsthal
    std::vector<std::vector<size_t> > groups;
    size_t prev = 1;
    for (size_t j = 2; j < jacob.size() && prev < maxIndex; ++j)
    {
        std::vector<size_t> group;
        size_t start = prev;
        size_t end = jacob[j] < maxIndex ? jacob[j] : maxIndex;
        for (size_t k = end; k > start && k <= maxIndex; --k)
        {
            group.push_back(k - 1); // Indices de 0 à maxIndex-1
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

size_t PmergeMe::findIndex(std::vector<int>& array, int value)
{
    for (std::vector<int>::iterator it = array.begin(); it != array.end(); ++it)
    {
        if (*it == value)
            return std::distance(array.begin(), it);
    }
    return std::numeric_limits<size_t>::max();
}


std::vector<int> PmergeMe::fordJohnsonVecSort(std::vector<int> inputMax) {
    int n = inputMax.size();
    if (n <= 1) {
        return inputMax;
    }

    if (n <= 3) {
        std::sort(inputMax.begin(), inputMax.end());
        return inputMax;
    }

    std::vector<int> maxS;
    std::vector<int> minS;
    int single = -1;

    // Trouver la valeur maximale pour dimensionner index
    int maxValue = *std::max_element(inputMax.begin(), inputMax.end());
    if (maxValue < 0) {
        maxValue = 0;
    }
    size_t size = static_cast<size_t>(maxValue) + 1;
    std::vector<int> index(size, 0);

    // Créer les paires et remplir maxS, minS, index
    for (int i = 0; i + 1 < n; i += 2) {
        if (inputMax[i] < inputMax[i + 1]) {
            minS.push_back(inputMax[i]);
            maxS.push_back(inputMax[i + 1]);
            if (inputMax[i + 1] >= 0 && static_cast<size_t>(inputMax[i + 1]) < size) {
                index[inputMax[i + 1]] = inputMax[i];
            }
        } else {
            minS.push_back(inputMax[i + 1]);
            maxS.push_back(inputMax[i]);
            if (inputMax[i] >= 0 && static_cast<size_t>(inputMax[i]) < size) {
                index[inputMax[i]] = inputMax[i + 1];
            }
        }
    }

    // Gérer l'élément non apparié
    if (n % 2 != 0) {
        single = inputMax[n - 1];
        maxS.push_back(single); // Ajouter à maxS pour le tri récursif
        if (single >= 0 && static_cast<size_t>(single) < size) {
            index[single] = -1; // Indiquer qu'il n'a pas de minimum apparié
        }
    }

    // Trier récursivement maxS
    std::vector<int> maxSorted = fordJohnsonVecSort(maxS);

    return maxSorted;
}

/*std::vector<int> PmergeMe::fordJohnsonVecSort(std::vector<int> inputMax) {
    int n = inputMax.size();
    if (n <= 1) {
        return inputMax;
    }

    if (n <= 3) {
        std::sort(inputMax.begin(), inputMax.end());
        return inputMax;
    }

    std::vector<int> maxS;
    std::vector<int> minS;
    int single = -1;

    // Trouver la valeur maximale dans inputMax pour dimensionner index
    int maxValue = *std::max_element(inputMax.begin(), inputMax.end());
    if (maxValue < 0) {
        maxValue = 0; // Gérer les cas où toutes les valeurs sont négatives
    }
    // Ajouter 1 car les indices commencent à 0
    size_t size = static_cast<size_t>(maxValue) + 1;
    std::vector<int> index(size, 0); // Allouer avec la taille nécessaire

    for (int i = 0; i + 1 < n; i += 2) {
        if (inputMax[i] < inputMax[i + 1]) {
            minS.push_back(inputMax[i]);
            maxS.push_back(inputMax[i + 1]);
            if (inputMax[i + 1] >= 0 && static_cast<size_t>(inputMax[i + 1]) < size) {
                index[inputMax[i + 1]] = inputMax[i];
            }
        } else {
            minS.push_back(inputMax[i + 1]);
            maxS.push_back(inputMax[i]);
            if (inputMax[i] >= 0 && static_cast<size_t>(inputMax[i]) < size) {
                index[inputMax[i]] = inputMax[i + 1];
            }
        }
    }
    
    if (n % 2 != 0) {
        single = inputMax[n - 1];
    }

    std::vector<int> maxSorted = fordJohnsonVecSort(maxS);
   
    std::vector<size_t> jacob = VecGenerateJacobsthal(minS.size());

    std::vector<int> Min;
    for (std::vector<int>::iterator it = maxSorted.begin(); it != maxSorted.end(); ++it) {
        if (*it >= 0 && static_cast<size_t>(*it) < size) {
            Min.push_back(index[*it]);
        }
    }

    if (!Min.empty()) {
        maxSorted.insert(maxSorted.begin(), Min[0]);
    }
    
    for (size_t i = 0; i < jacob.size(); ++i) {
        size_t j = jacob[i] - 1;
        
        if (j >= Min.size() || j == 0) {
            continue;
        }
        
        int xi = findIndex(index, Min[j]);

        // Trouver la position de xi dans sorted
        std::vector<int>::iterator xi_pos = maxSorted.begin();
        while (xi_pos != maxSorted.end() && *xi_pos != xi) {
            ++xi_pos;
        }
        if (xi_pos == maxSorted.end()) {
            xi_pos = maxSorted.end();
        }
        
        std::vector<int>::iterator pos = std::lower_bound(maxSorted.begin(), xi_pos, minS[j]);
        maxSorted.insert(pos, minS[j]);
    }

    return maxSorted;
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
        } else {
            pairs.push_back(std::make_pair(inputMax[i], inputMax[i + 1]));
        }
    }
    if (n % 2 != 0)
    {
        single = inputMax[n - 1];
    }

    std::vector<int> maxS;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        maxS.push_back(pairs[i].first);
    }

    std::vector<int> sorted = fordJohnsonVecSort(maxS);

    size_t size = sorted.empty() ? 0 : sorted.back() + 1;
    std::vector<int> tmp(size, 0);

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first < static_cast<int>(tmp.size()))
        {
            tmp[pairs[i].first] = pairs[i].second;
        }
    }

    std::vector<int> Min;
    for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it)
    {
        if (*it < static_cast<int>(tmp.size()))
        {
            Min.push_back(tmp[*it]);
        }
    }
    
    
    //std::vector<int> MinJacobOrder;

    if (!Min.empty())
    {
        sorted.insert(sorted.begin(), Min[0]);
    }

    for (size_t i = 0; i < jacobOrder.size(); ++i)
    {
        size_t idx = jacobOrder[i];
        if (idx < Min.size() && idx > 0)
        { 
            MinJacobOrder.push_back(Min[idx]);
        }
    }

    std::vector<size_t> jacob = VecGenerateJacobsthal(Min.size());
    
    for_each(jacob.begin(), jacob.end(), displayArray);
    std::cout << std::endl;

    
    for (size_t i = 0; i < jacob.size() && i < Min.size(); ++i)
    {
        size_t index = jacob[i] - 1;
        if (index >= Min.size() || index == 0)
            continue;
        
        int xi = findIndex(tmp, Min[index]);
        std::cout << Min[index]<< std::endl;

        // Trouver la position de xi dans sorted
        std::vector<int>::iterator xi_pos = sorted.begin();
        while (xi_pos != sorted.end() && *xi_pos != xi)
        {
            ++xi_pos;
        }
        if (xi_pos == sorted.end())
        {
            xi_pos = sorted.end();
        }
       
        std::vector<int>::iterator insert_pos = std::lower_bound(sorted.begin(), xi_pos, Min[index]);
        sorted.insert(insert_pos, Min[index]);
       
    }

    // Insérer le singleton, si présent
    if (single != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), single);
        sorted.insert(pos, single);
    }

    return sorted;
}*/



void PmergeMe::PmergeMeVector()
{
    std::vector<std::pair<int, int> > pairs = createPairsVec(_inputVec);

    std::vector<int> maxX;
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        maxX.push_back(it->first);
    }

    _sortedVec = fordJohnsonVecSort(maxX);
    std::cout << "max: ";
    for (std::vector<int>::iterator it = _sortedVec.begin(); it != _sortedVec.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    /*std::vector<int> minX = VecExtractMinX(pairs);

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
    }*/
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
    jacob.push_back(1); // J_1
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

std::deque<int> PmergeMe::fordJohnsonDeqSort(std::deque<int> inputMax)
{
    int n = static_cast<int>(inputMax.size());
    if (n <= 1)
    {
        return inputMax;
    }

    if (n <= 3)
    {
        std::sort(inputMax.begin(), inputMax.end());
        return inputMax;
    }

    std::deque<std::pair<int, int> > pairs;
    int single = -1;

    for (int i = 0; i + 1 < n; i += 2)
    {
        if (inputMax[i] < inputMax[i + 1])
        {
            pairs.push_back(std::pair<int, int>(inputMax[i + 1], inputMax[i]));
        } else
        {
            pairs.push_back(std::pair<int, int>(inputMax[i], inputMax[i + 1]));
        }
    }
    if (n % 2 != 0)
    {
        single = inputMax[n - 1];
    }

    std::deque<int> maxS;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        maxS.push_back(pairs[i].first);
    }

    std::deque<int> maxSorted = fordJohnsonDeqSort(maxS);

    std::deque<size_t> jacob;
    if (single != -1)
    {
        pairs.push_back(std::pair<int, int>(std::numeric_limits<int>::max(), single));
        jacob = DeqGenerateJacobsthal(pairs.size());
    } else
    {
        jacob = DeqGenerateJacobsthal(pairs.size());
    }

    std::deque<bool> inserted(pairs.size(), false);

    for (size_t i = 0; i < jacob.size(); ++i)
    {
        size_t index = jacob[i];
        if (index < pairs.size() && !inserted[index])
        {
            int yi = pairs[index].second;
            int xi = pairs[index].first;

            std::deque<int>::iterator xi_pos = maxSorted.begin();
            while (xi_pos != maxSorted.end() && *xi_pos != xi)
            {
                ++xi_pos;
            }
            if (xi_pos == maxSorted.end() || xi == std::numeric_limits<int>::max())
            {
                xi_pos = maxSorted.end();
            }

            std::deque<int>::iterator pos = std::lower_bound(maxSorted.begin(), xi_pos, yi);
            maxSorted.insert(pos, yi);
            inserted[index] = true;
        }
    }

    return maxSorted;
}

void PmergeMe::PmergeMeDeque()
{
    std::deque<std::pair<int, int> > pairs = createPairsDeq(_inputDeq);

    std::deque<int> maxX;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        maxX.push_back(pairs[i].first);
    }

    _sortedDeq = fordJohnsonDeqSort(maxX);

    std::deque<int> minX = DeqExtractMinX(pairs);
 
    if (!minX.empty())
    {
        std::deque<int>::iterator minIt = minX.begin();
        for (std::deque<int>::iterator it = minX.begin(); it != minX.end(); ++it)
        {
            if (*it < *minIt)
            {
                minIt = it;
            }
        }
        size_t minIndex = 0;
        for (std::deque<int>::iterator it = minX.begin(); it != minIt; ++it)
        {
            ++minIndex;
        }
        std::deque<int>::iterator pos = std::lower_bound(_sortedDeq.begin(), _sortedDeq.end(), *minIt);
        _sortedDeq.insert(pos, *minIt);
        minX.erase(minIt);
        pairs.erase(pairs.begin() + minIndex);
    }

    if (_single != -1)
    {
        pairs.push_back(std::pair<int, int>(std::numeric_limits<int>::max(), _single));
    }

    std::deque<size_t> jacob = DeqGenerateJacobsthal(pairs.size());
    std::deque<bool> inserted(pairs.size(), false);

    for (size_t i = 0; i < jacob.size(); ++i)
    {
        size_t index = jacob[i];
        if (index < pairs.size() && !inserted[index])
        {
            int yi = pairs[index].second;
            int xi = pairs[index].first;

            std::deque<int>::iterator xi_pos = _sortedDeq.begin();
            while (xi_pos != _sortedDeq.end() && *xi_pos != xi)
            {
                ++xi_pos;
            }
            if (xi_pos == _sortedDeq.end() || xi == std::numeric_limits<int>::max())
            {
                xi_pos = _sortedDeq.end();
            }

            std::deque<int>::iterator pos = std::lower_bound(_sortedDeq.begin(), xi_pos, yi);
            _sortedDeq.insert(pos, yi);
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
    _timeVec = static_cast<double>(clock() - startTime) / (double)CLOCKS_PER_SEC;

    /*for_each(_sortedVec.begin(), _sortedVec.end(), displayArray);
    std::cout << std::endl;*/

    /*startTime = clock();
    PmergeMeDeque();
    _timeDeq = static_cast<double>(clock() - startTime )/ (double)CLOCKS_PER_SEC;*/


    std::cout << "After:  ";
    for_each(_sortedVec.begin(), _sortedVec.end(), displayArray);
    std::cout << std::endl;

   /* std::cout << "Time to process a range of " << _inputVec.size() 
                << " elements with std::vector: " << std::fixed << std::setprecision(5) 
                << _timeVec << " us" << std::endl;*/
    std::cout << "Time to process a range of " << _inputDeq.size() 
                << " elements with std::deque:  " << std::fixed << std::setprecision(5) 
                << _timeDeq << " us\n";
}


