/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:56:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/21 20:04:29 by rhanitra         ###   ########.fr       */
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

    // Créer les groupes avec tailles basées sur les différences de Jacobsthal
    std::vector<std::vector<size_t> > groups;
    size_t prev = 1;
    for (size_t j = 2; j < jacob.size() && prev < maxIndex; ++j) {
        std::vector<size_t> group;
        size_t start = prev;
        size_t end = jacob[j] < maxIndex ? jacob[j] : maxIndex;
        for (size_t k = end; k > start && k <= maxIndex; --k) {
            group.push_back(k - 1); // Indices de 0 à maxIndex-1
        }
        if (!group.empty()) {
            groups.push_back(group);
        }
        prev = jacob[j];
    }

    // Ajouter les indices restants
    std::set<size_t> usedIndices;
    for (size_t g = 0; g < groups.size(); ++g) {
        for (size_t k = 0; k < groups[g].size(); ++k) {
            usedIndices.insert(groups[g][k]);
        }
    }
    std::vector<size_t> remaining;
    for (size_t i = 0; i < maxIndex; ++i) {
        if (usedIndices.find(i) == usedIndices.end()) {
            remaining.push_back(i);
        }
    }

    // Concaténer les groupes et les indices restants
    for (size_t g = 0; g < groups.size(); ++g) {
        for (size_t k = 0; k < groups[g].size(); ++k) {
            indices.push_back(groups[g][k]);
        }
    }
    for (size_t k = 0; k < remaining.size(); ++k) {
        indices.push_back(remaining[k]);
    }

    return indices;
}

std::vector<int> PmergeMe::fordJohnsonVecSort(std::vector<int> inputMax)
{
    int n = static_cast<int>(inputMax.size());
    if (n <= 1) {
        return inputMax;
    }

    if (n <= 3) {
        std::sort(inputMax.begin(), inputMax.end());
        return inputMax;
    }

    std::vector<std::pair<int, int> > pairs;
    int single = -1;

    // Créer les paires (max, min)
    for (int i = 0; i + 1 < n; i += 2) {
        if (inputMax[i] < inputMax[i + 1]) {
            pairs.push_back(std::pair<int, int>(inputMax[i + 1], inputMax[i]));
        } else {
            pairs.push_back(std::pair<int, int>(inputMax[i], inputMax[i + 1]));
        }
    }
    if (n % 2 != 0) {
        single = inputMax[n - 1];
    }

    // Extraire les maximums
    std::vector<int> maxS;
    for (size_t i = 0; i < pairs.size(); ++i) {
        maxS.push_back(pairs[i].first);
    }

    // Trier récursivement les maximums
    std::vector<int> maxSorted = fordJohnsonVecSort(maxS);

    // Générer les indices de Jacobsthal
    std::vector<size_t> jacobIndices;
    if (single != -1) {
        // Inclure _single comme y_i avec un indice max
        pairs.push_back(std::pair<int, int>(std::numeric_limits<int>::max(), single));
        jacobIndices = VecGenerateJacobsthal(pairs.size());
    } else {
        jacobIndices = VecGenerateJacobsthal(pairs.size());
    }

    std::vector<bool> inserted(pairs.size(), false);

    // Insérer les minimums (y_i, incluant single si présent)
    for (size_t i = 0; i < jacobIndices.size(); ++i) {
        size_t index = jacobIndices[i];
        if (index < pairs.size() && !inserted[index]) {
            int yi = pairs[index].second; // Minimum (y_i)
            int xi = pairs[index].first;  // Maximum correspondant (x_i)

            // Trouver la position de x_i dans maxSorted
            std::vector<int>::iterator xi_pos = maxSorted.begin();
            while (xi_pos != maxSorted.end() && *xi_pos != xi) {
                ++xi_pos;
            }
            if (xi_pos == maxSorted.end() || xi == std::numeric_limits<int>::max()) {
                xi_pos = maxSorted.end(); // Pour single ou sécurité
            }

            // Recherche binaire du début jusqu'à x_i exclu
            std::vector<int>::iterator pos = std::lower_bound(maxSorted.begin(), xi_pos, yi);
            maxSorted.insert(pos, yi);
            inserted[index] = true;
        }
    }

    return maxSorted;
}

void PmergeMe::PmergeMeVector()
{
    std::vector<std::pair<int, int> > pairs = createPairsVec(_inputVec);

    std::vector<int> maxX;
    for (size_t i = 0; i < pairs.size(); ++i) {
        maxX.push_back(pairs[i].first);
    }

    _sortedVec = fordJohnsonVecSort(maxX);

    std::vector<int> minX = VecExtractMinX(pairs);

    // Étape 4 : Insérer le plus petit élément
    if (!minX.empty()) {
        std::vector<int>::iterator minIt = minX.begin();
        for (std::vector<int>::iterator it = minX.begin(); it != minX.end(); ++it) {
            if (*it < *minIt) {
                minIt = it;
            }
        }
        size_t minIndex = 0;
        for (std::vector<int>::iterator it = minX.begin(); it != minIt; ++it) {
            ++minIndex;
        }
        std::vector<int>::iterator pos = std::lower_bound(_sortedVec.begin(), _sortedVec.end(), *minIt);
        _sortedVec.insert(pos, *minIt);
        minX.erase(minIt);
        pairs.erase(pairs.begin() + minIndex);
    }

    // Étape 5 : Insérer les éléments restants avec Jacobsthal, incluant _single
    if (_single != -1) {
        // Ajouter _single comme y_i avec un indice max
        pairs.push_back(std::pair<int, int>(std::numeric_limits<int>::max(), _single));
    }

    std::vector<size_t> jacob = VecGenerateJacobsthal(pairs.size());
    std::vector<bool> inserted(pairs.size(), false);

    // Débogage : Afficher les indices de Jacobsthal
    for (size_t i = 0; i < jacob.size(); ++i) {
        std::cout << jacob[i] << " ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < jacob.size(); ++i) {
        size_t index = jacob[i];
        if (index < pairs.size() && !inserted[index]) {
            int yi = pairs[index].second; // Minimum (y_i)
            int xi = pairs[index].first;  // Maximum correspondant (x_i)

            // Trouver la position de x_i dans _sortedVec
            std::vector<int>::iterator xi_pos = _sortedVec.begin();
            while (xi_pos != _sortedVec.end() && *xi_pos != xi) {
                ++xi_pos;
            }
            if (xi_pos == _sortedVec.end() || xi == std::numeric_limits<int>::max()) {
                xi_pos = _sortedVec.end(); // Pour _single ou sécurité
            }

            // Recherche binaire du début jusqu'à x_i exclu
            std::vector<int>::iterator pos = std::lower_bound(_sortedVec.begin(), xi_pos, yi);
            _sortedVec.insert(pos, yi);
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
    if (maxIndex <= 2) {
        for (size_t i = 0; i < maxIndex; ++i) {
            indices.push_back(i);
        }
        return indices;
    }

    // Générer les nombres de Jacobsthal
    std::deque<size_t> jacob;
    jacob.push_back(0); // J_0
    jacob.push_back(1); // J_1
    size_t i = 2;
    while (jacob.back() < maxIndex) {
        jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
        ++i;
    }

    // Créer les groupes avec tailles basées sur les différences de Jacobsthal
    std::deque<std::deque<size_t> > groups;
    size_t prev = 1;
    for (size_t j = 2; j < jacob.size() && prev < maxIndex; ++j) {
        std::deque<size_t> group;
        size_t start = prev;
        size_t end = jacob[j] < maxIndex ? jacob[j] : maxIndex;
        for (size_t k = end; k > start && k <= maxIndex; --k) {
            group.push_back(k - 1); // Indices de 0 à maxIndex-1
        }
        if (!group.empty()) {
            groups.push_back(group);
        }
        prev = jacob[j];
    }

    // Ajouter les indices restants
    std::set<size_t> usedIndices;
    for (size_t g = 0; g < groups.size(); ++g) {
        for (size_t k = 0; k < groups[g].size(); ++k) {
            usedIndices.insert(groups[g][k]);
        }
    }
    std::deque<size_t> remaining;
    for (size_t i = 0; i < maxIndex; ++i) {
        if (usedIndices.find(i) == usedIndices.end()) {
            remaining.push_back(i);
        }
    }

    // Concaténer les groupes et les indices restants
    for (size_t g = 0; g < groups.size(); ++g) {
        for (size_t k = 0; k < groups[g].size(); ++k) {
            indices.push_back(groups[g][k]);
        }
    }
    for (size_t k = 0; k < remaining.size(); ++k) {
        indices.push_back(remaining[k]);
    }

    return indices;
}

std::deque<int> PmergeMe::fordJohnsonDeqSort(std::deque<int> inputMax)
{
    int n = static_cast<int>(inputMax.size());
    if (n <= 1) {
        return inputMax;
    }

    if (n <= 3) {
        std::sort(inputMax.begin(), inputMax.end());
        return inputMax;
    }

    std::deque<std::pair<int, int> > pairs;
    int single = -1;

    // Créer les paires (max, min)
    for (int i = 0; i + 1 < n; i += 2) {
        if (inputMax[i] < inputMax[i + 1]) {
            pairs.push_back(std::pair<int, int>(inputMax[i + 1], inputMax[i]));
        } else {
            pairs.push_back(std::pair<int, int>(inputMax[i], inputMax[i + 1]));
        }
    }
    if (n % 2 != 0) {
        single = inputMax[n - 1];
    }

    // Extraire les maximums
    std::deque<int> maxS;
    for (size_t i = 0; i < pairs.size(); ++i) {
        maxS.push_back(pairs[i].first);
    }

    // Trier récursivement les maximums
    std::deque<int> maxSorted = fordJohnsonDeqSort(maxS);

    // Générer les indices de Jacobsthal
    std::deque<size_t> jacobIndices;
    if (single != -1) {
        // Inclure _single comme y_i avec un indice max
        pairs.push_back(std::pair<int, int>(std::numeric_limits<int>::max(), single));
        jacobIndices = DeqGenerateJacobsthal(pairs.size());
    } else {
        jacobIndices = DeqGenerateJacobsthal(pairs.size());
    }

    std::deque<bool> inserted(pairs.size(), false);

    // Insérer les minimums (y_i, incluant single si présent)
    for (size_t i = 0; i < jacobIndices.size(); ++i) {
        size_t index = jacobIndices[i];
        if (index < pairs.size() && !inserted[index]) {
            int yi = pairs[index].second; // Minimum (y_i)
            int xi = pairs[index].first;  // Maximum correspondant (x_i)

            // Trouver la position de x_i dans maxSorted
            std::deque<int>::iterator xi_pos = maxSorted.begin();
            while (xi_pos != maxSorted.end() && *xi_pos != xi) {
                ++xi_pos;
            }
            if (xi_pos == maxSorted.end() || xi == std::numeric_limits<int>::max()) {
                xi_pos = maxSorted.end(); // Pour single ou sécurité
            }

            // Recherche binaire du début jusqu'à x_i exclu
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
    for (size_t i = 0; i < pairs.size(); ++i) {
        maxX.push_back(pairs[i].first);
    }

    _sortedDeq = fordJohnsonDeqSort(maxX);

    std::deque<int> minX = DeqExtractMinX(pairs);

    // Étape 4 : Insérer le plus petit élément
    if (!minX.empty()) {
        std::deque<int>::iterator minIt = minX.begin();
        for (std::deque<int>::iterator it = minX.begin(); it != minX.end(); ++it) {
            if (*it < *minIt) {
                minIt = it;
            }
        }
        size_t minIndex = 0;
        for (std::deque<int>::iterator it = minX.begin(); it != minIt; ++it) {
            ++minIndex;
        }
        std::deque<int>::iterator pos = std::lower_bound(_sortedDeq.begin(), _sortedDeq.end(), *minIt);
        _sortedDeq.insert(pos, *minIt);
        minX.erase(minIt);
        pairs.erase(pairs.begin() + minIndex);
    }

    // Étape 5 : Insérer les éléments restants avec Jacobsthal, incluant _single
    if (_single != -1) {
        // Ajouter _single comme y_i avec un indice max
        pairs.push_back(std::pair<int, int>(std::numeric_limits<int>::max(), _single));
    }

    std::deque<size_t> jacob = DeqGenerateJacobsthal(pairs.size());
    std::deque<bool> inserted(pairs.size(), false);

    // Débogage : Afficher les indices de Jacobsthal
    for (size_t i = 0; i < jacob.size(); ++i) {
        std::cout << jacob[i] << " ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < jacob.size(); ++i) {
        size_t index = jacob[i];
        if (index < pairs.size() && !inserted[index]) {
            int yi = pairs[index].second; // Minimum (y_i)
            int xi = pairs[index].first;  // Maximum correspondant (x_i)

            // Trouver la position de x_i dans _sortedVec
            std::deque<int>::iterator xi_pos = _sortedDeq.begin();
            while (xi_pos != _sortedDeq.end() && *xi_pos != xi) {
                ++xi_pos;
            }
            if (xi_pos == _sortedDeq.end() || xi == std::numeric_limits<int>::max()) {
                xi_pos = _sortedDeq.end(); // Pour _single ou sécurité
            }

            // Recherche binaire du début jusqu'à x_i exclu
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
    
    clock_t start = clock();
    PmergeMeVector();
    _timeVec = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1e6;

    start = clock();
    PmergeMeDeque();
    _timeDeq = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1e6;

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


