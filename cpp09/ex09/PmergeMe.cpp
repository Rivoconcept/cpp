/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivoinfo <rivoinfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:56:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/30 14:21:52 by rivoinfo         ###   ########.fr       */
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

std::vector<size_t> PmergeMe::VecgenerateJacobsthalGroup(size_t maxIndex)
{
    std::vector<size_t> jacobIndices;
    if (maxIndex <= 1)
        return (jacobIndices);

    std::vector<size_t> jacob;
    jacob.push_back(3);
    size_t j1 = 3, j2 = 1;
    while (j1 < maxIndex)
    {
        j1 = j1 + 2 * j2;
        j2 = jacob.back();
        jacob.push_back(j1);
    }

    std::vector<size_t> orderIndex;
    size_t prev = 1;
    for (size_t j = 0; j < jacob.size(); ++j)
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

std::vector<int> PmergeMe::fordJohnsonVecSort(std::vector<int> input)
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

    std::vector<int> sortedMaxs = fordJohnsonVecSort(maxs);
    
    std::vector<int> sorted = sortedMaxs;
    
    std::vector<size_t> maxPos(pairs.size());

    for (size_t i = 0; i < sortedMaxs.size(); ++i)
        maxPos[i] = i;

    if (!sortedMaxs.empty())
    {
        int firstMin = maxToMin[sortedMaxs[0]];
        sorted.insert(sorted.begin(), firstMin);
        maxToMin.erase(sortedMaxs[0]);
        for (size_t i = 0; i < maxPos.size(); ++i)
            maxPos[i]++;
    }

    std::vector<size_t> orderIndex = VecgenerateJacobsthalGroup(pairs.size());

    for_each(orderIndex.begin(), orderIndex.end(), displayArray);
    std::cout << std::endl;

    for (size_t j = 0; j < orderIndex.size(); ++j)
    {
        size_t index = orderIndex[j];

        if (index < sortedMaxs.size() && maxToMin.find(sortedMaxs[index]) != maxToMin.end())
        {
            int minToInsert = maxToMin[sortedMaxs[index]];
            
            size_t xi_pos_index = maxPos[index];
            std::vector<int>::iterator xi_pos = sorted.begin() + xi_pos_index;
            std::vector<int>::iterator insert_pos = std::lower_bound(sorted.begin(), xi_pos, minToInsert);
            sorted.insert(insert_pos, minToInsert);
            
            size_t insert_index = std::distance(sorted.begin(), insert_pos);
            for (size_t i = 0; i < maxPos.size(); ++i)
            {
                if (maxPos[i] >= insert_index)
                    maxPos[i]++;
            }
            
            maxToMin.erase(sortedMaxs[index]);
        }
    }

    if (single != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), single);
        sorted.insert(pos, single);
    }

    return (sorted);
}

/*std::vector<int> PmergeMe::fordJohnsonVecSort(std::vector<int> input)
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

    std::vector<int> sortedMaxs = fordJohnsonVecSort(maxs);
    
    std::vector<int> sorted = sortedMaxs;
    std::vector<size_t> maxPos(pairs.size());

    for (size_t i = 0; i < sortedMaxs.size(); ++i)
        maxPos[i] = i;

    if (!sortedMaxs.empty())
    {
        int firstMin = maxToMin[sortedMaxs[0]];
        sorted.insert(sorted.begin(), firstMin);
        maxToMin.erase(sortedMaxs[0]); 

        for (size_t i = 0; i < maxPos.size(); ++i)
            maxPos[i]++;
    }

    std::vector<size_t> orderIndex = VecgenerateJacobsthalGroup(pairs.size());

    for (size_t j = 0; j < orderIndex.size(); ++j)
    {
        size_t index = orderIndex[j];
        if (index < sortedMaxs.size() && maxToMin.find(sortedMaxs[index]) != maxToMin.end())
        {
            int minToInsert = maxToMin[sortedMaxs[index]];
            
            size_t xi_pos_index = maxPos[index];
            
            std::vector<int>::iterator xi_pos = sorted.begin() + xi_pos_index;

            std::vector<int>::iterator insert_pos = std::lower_bound(sorted.begin(), xi_pos, minToInsert);
            sorted.insert(insert_pos, minToInsert);

            size_t insert_index = std::distance(sorted.begin(), insert_pos);
            for (size_t i = 0; i < maxPos.size(); ++i)
            {
                if (maxPos[i] >= insert_index)
                    maxPos[i]++;
            }
            
            maxToMin.erase(sortedMaxs[index]);
        }
    }

    if (single != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), single);
        sorted.insert(pos, single);
    }

    return sorted;
}*/

void PmergeMe::PmergeMeVector()
{
    _sortedVec = fordJohnsonVecSort(_inputVec);
}

// DEQUE SIMULATION /////////////////////////////////////////////////////////////////////////////////////////////////


std::deque<size_t> PmergeMe::DeqGenerateJacobsthal(size_t maxIndex)
{
    std::deque<size_t> jacobIndices;
    if (maxIndex <= 1)
        return jacobIndices;

    jacobIndices.push_back(1);
    if (maxIndex > 1)
    {
        jacobIndices.push_back(3);
    }
    
    size_t j1 = 1, j2 = 1;
    while (true)
    {
        size_t next = j1 + 2 * j2;
        if (next > maxIndex)
            break;
        jacobIndices.push_back(next);
        j2 = j1;
        j1 = next;
    }
    
    return jacobIndices;
}

std::deque<int> PmergeMe::fordJohnsonDeqSort(std::deque<int> input)
{
    if (input.size() <= 1)
        return input;
    
    if (input.size() == 2)
    {
        if (input[0] > input[1])
            std::swap(input[0], input[1]);
        return input;
    }

    // Étape 1: Créer les paires et identifier l'élément impair
    int single = -1;
    std::deque<int> current = input;
    if (current.size() % 2 != 0)
    {
        single = current.back();
        current.pop_back();
    }

    // Étape 2: Créer les paires et séparer en max et min avec conservation de l'association
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < current.size(); i += 2)
    {
        if (current[i] > current[i+1])
        {
            pairs.push_back(std::make_pair(current[i], current[i+1])); // (max, min)
        }
        else
        {
            pairs.push_back(std::make_pair(current[i+1], current[i])); // (max, min)
        }
    }

    // Extraire les maximums pour tri récursif
    std::deque<int> maxs;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        maxs.push_back(pairs[i].first);
    }

    // Étape 3: Trier récursivement les maximums
    std::deque<int> sortedMaxs;
    if (maxs.size() == 1)
    {
        sortedMaxs.push_back(maxs[0]);
    }
    else
    {
        sortedMaxs = fordJohnsonDeqSort(maxs);
    }
    
    // Créer un map pour associer chaque max à son min correspondant
    std::map<int, int> maxToMin;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        maxToMin[pairs[i].first] = pairs[i].second;
    }

    // Commencer avec la séquence triée des maximums
    std::deque<int> sorted = sortedMaxs;

    // Étape 4: Insérer le min associé au premier (plus petit) max au début
    if (!pairs.empty())
    {
        int firstMin = maxToMin[sortedMaxs[0]];
        sorted.push_front(firstMin);
    }

    // Étape 5: Insérer les autres mins avec recherche binaire
    for (size_t i = 1; i < sortedMaxs.size(); ++i)
    {
        int minToInsert = maxToMin[sortedMaxs[i]];
        

        // Recherche binaire limitée à la partie où on peut insérer
        std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), minToInsert);
        sorted.insert(pos, minToInsert);
    }

    // Insérer le single à la bonne place
    if (single != -1)
    {
        std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), single);
        sorted.insert(pos, single);
    }

    return sorted;
}

void PmergeMe::PmergeMeDeque()
{
    _sortedDeq = fordJohnsonDeqSort(_inputDeq);
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
        std::cerr << "Error: MaxSorted is not sorted!" << std::endl;
    }
}


