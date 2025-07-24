/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:56:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/24 20:38:47 by rhanitra         ###   ########.fr       */
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

/*std::vector<int> PmergeMe::fordJohnsonVecSort(std::vector<int> inputMax)
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
}*/

cpp

Collapse

Wrap

Copy
#include <vector>
#include <algorithm>
#include <limits>

class PmergeMe {
private:
    std::vector<int> _inputVec;
    std::vector<int> _sortedVec;

public:
    PmergeMe(const std::vector<int>& input) : _inputVec(input) {}

    std::vector<size_t> VecGenerateJacobsthal(size_t maxIndex) {
        std::vector<size_t> indices;
        if (maxIndex <= 2) {
            for (size_t i = 0; i < maxIndex; ++i) {
                indices.push_back(i);
            }
            return indices;
        }

        // Générer les nombres de Jacobsthal
        std::vector<size_t> jacob;
        jacob.push_back(0); // J_0
        jacob.push_back(1); // J_1
        size_t i = 2;
        while (jacob.back() < maxIndex) {
            jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
            ++i;
        }

        // Créer l'ordre d'insertion
        indices.push_back(0); // Insérer Min[0] en premier
        size_t prev = 1;
        for (size_t j = 2; j < jacob.size() && prev < maxIndex; ++j) {
            size_t start = prev;
            size_t end = jacob[j] < maxIndex ? jacob[j] : maxIndex;
            for (size_t k = end; k > start && k <= maxIndex; --k) {
                indices.push_back(k - 1);
            }
            prev = jacob[j];
        }

        // Ajouter les indices restants
        std::vector<bool> used(maxIndex, false);
        for (size_t i = 0; i < indices.size(); ++i) {
            if (indices[i] < maxIndex) {
                used[indices[i]] = true;
            }
        }
        for (size_t i = 0; i < maxIndex; ++i) {
            if (!used[i]) {
                indices.push_back(i);
            }
        }

        return indices;
    }

    size_t findIndex(const std::vector<std::pair<int, size_t> >& array, int value) {
        for (size_t i = 0; i < array.size(); ++i) {
            if (array[i].first == value) {
                return array[i].second;
            }
        }
        return std::numeric_limits<size_t>::max();
    }

    std::vector<int> fordJohnsonVecSort(std::vector<int> inputMax) {
        int n = static_cast<int>(inputMax.size());
        if (n <= 1) {
            return inputMax;
        }
        if (n <= 3) {
            std::sort(inputMax.begin(), inputMax.end());
            return inputMax;
        }

        // Étape 1 : Créer les paires
        std::vector<std::pair<int, int> > pairs;
        int single = -1;

        for (int i = 0; i + 1 < n; i += 2) {
            if (inputMax[i] < inputMax[i + 1]) {
                pairs.push_back(std::make_pair(inputMax[i + 1], inputMax[i]));
            } else {
                pairs.push_back(std::make_pair(inputMax[i], inputMax[i + 1]));
            }
        }
        if (n % 2 != 0) {
            single = inputMax[n - 1];
        }

        // Étape 2 : Trier les maximaux
        std::vector<int> maxS;
        for (size_t i = 0; i < pairs.size(); ++i) {
            maxS.push_back(pairs[i].first);
        }

        std::vector<int> sorted = fordJohnsonVecSort(maxS);

        // Créer une table de correspondance pour associer xi à sa position dans sorted
        std::vector<std::pair<int, size_t> > xi_to_pos;
        xi_to_pos.reserve(sorted.size());
        for (size_t i = 0; i < sorted.size(); ++i) {
            xi_to_pos.push_back(std::make_pair(sorted[i], i));
        }

        // Étape 3 : Créer Min
        std::vector<int> Min;
        for (size_t i = 0; i < pairs.size(); ++i) {
            Min.push_back(pairs[i].second);
        }

        // Étape 4 : Générer l'ordre d'insertion et insérer Min[0]
        std::vector<size_t> jacob = VecGenerateJacobsthal(Min.size());
        if (!Min.empty()) {
            sorted.insert(sorted.begin(), Min[0]); // Insérer y1
            for (size_t i = 0; i < xi_to_pos.size(); ++i) {
                xi_to_pos[i].second += 1; // Décaler les positions
            }
        }

        // Étape 5 : Insérer les éléments restants de Min selon l'ordre de Jacobsthal
        for (size_t i = 0; i < jacob.size() && jacob[i] < Min.size(); ++i) {
            size_t j = jacob[i];
            if (j == 0 || j >= Min.size()) {
                continue;
            }
            // Trouver la position de xi associé à Min[j]
            int xi = pairs[j - 1].first; // xi associé à yi (Min[j])
            size_t pos = findIndex(xi_to_pos, xi);
            if (pos >= sorted.size()) {
                continue; // Sécurité
            }
            std::vector<int>::iterator xi_pos = sorted.begin() + pos;
            // Recherche dichotomique de Min[j] dans sorted[0, xi_pos)
            std::vector<int>::iterator insert_pos = std::lower_bound(sorted.begin(), xi_pos, Min[j]);
            sorted.insert(insert_pos, Min[j]);
            // Mettre à jour xi_to_pos
            for (size_t k = 0; k < xi_to_pos.size(); ++k) {
                if (xi_to_pos[k].second >= static_cast<size_t>(insert_pos - sorted.begin())) {
                    xi_to_pos[k].second += 1;
                }
            }
        }

        // Insérer le singleton, si présent
        if (single != -1) {
            std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), single);
            sorted.insert(pos, single);
        }

        return sorted;
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

