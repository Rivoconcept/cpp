/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:56:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/16 20:41:30 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::string& args) : _timeVec(0)
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
    }

    findDuplicates(_inputVec);

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
        _inputVec = other._inputVec;
        _vecX = other._vecX;
        _timeVec = other._timeVec;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {};

const std::vector<int>& PmergeMe::getSortedVec() const
{
    return (_vecX);
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

void PmergeMe::mergeInsertSort(std::vector<int>& array)
{
    if (array.size() <= 1)
        return;

    if (array.size() <= 3)
    {
        std::sort(array.begin(), array.end());
        return;
    }

    std::vector<std::pair<int, int> > pairs = createPairsVec(array);
    
    std::vector<int> maxs;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        maxs.push_back(pairs[i].first);
    }

    mergeInsertSort(maxs);

    std::cout << "Creacte S: ";
    for (std::vector<int>::iterator it = maxs.begin(); it != maxs.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::vector<int> S = maxs;

    std::vector<int> pending;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        pending.push_back(pairs[i].second);
    }
    if (_single != -1)
        pending.push_back(_single);

    for (size_t i = 0; i < pending.size(); ++i)
    {
        std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), pending[i]);
        S.insert(it, pending[i]);
    }

    array = S;
}

void PmergeMe::extractMaxVec()
{
    std::vector<int> maxVecS;

    for (std::vector<std::pair<int, int> >::const_iterator it = _pairVecX.begin(); it != _pairVecX.end(); ++it)
    {
        maxVecS.push_back(it->first);
    }

    mergeInsertSort(maxVecS);

    std::cout << "Creacte pairs S: ";
    for (std::vector<int>::iterator it = maxVecS.begin(); it != maxVecS.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t n)
{
    std::vector<size_t> jacob;

    jacob.push_back(0);
    jacob.push_back(1);
    
    size_t i = 2;
    
    while (jacob.back() < n)
    {
        jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
        ++i;
    }
    
    return (jacob);
}

void PmergeMe::run()
{
    // Afficher la séquence d'entrée
    for (std::vector<int>::iterator it = _inputVec.begin(); it != _inputVec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    clock_t start = clock();

    // Étape 1 : Créer les paires
    _pairVecX = createPairsVec(_inputVec);
    std::cout << "Creacte pairs X: ";
    for (size_t i = 0; i < _pairVecX.size(); ++i)
    {
        std::cout << "(" << _pairVecX[i].first << ", " << _pairVecX[i].second << ")" << " ";
    }
    std::cout << std::endl;

    // Étape 3 : Extraire et trier les maximums
    extractMaxVec();

    // Étape 4 : Insérer les minimums et _single avec l'ordre de Jacobsthal
    _pending.clear();
    for (size_t i = 0; i < _pairVecX.size(); ++i)
    {
        _pending.push_back(_pairVecX[i].second);
    }
    if (_single != -1)
        _pending.push_back(_single);

    std::vector<size_t> jacob = generateJacobsthal(_pairVecX.size());
    for (size_t i = 1; i < jacob.size() && jacob[i] < _pending.size(); ++i)
    {
        size_t index = jacob[i];
        if (index < _pending.size())
        {
            std::vector<int>::iterator it = std::lower_bound(_maxVecS.begin(), _maxVecS.end(), _pending[index]);
            _maxVecS.insert(it, _pending[index]);
        }
    }

    for (size_t i = 0; i < _pending.size(); ++i)
    {
        bool alreadyInserted = false;
        for (size_t j = 1; j < jacob.size() && jacob[j] < _pending.size(); ++j)
        {
            if (jacob[j] == i)
            {
                alreadyInserted = true;
                break;
            }
        }
        if (!alreadyInserted)
        {
            std::vector<int>::iterator it = std::lower_bound(_maxVecS.begin(), _maxVecS.end(), _pending[i]);
            _maxVecS.insert(it, _pending[i]);
        }
    }

    // Afficher la séquence triée finale
    std::cout << "Final sorted sequence: ";
    for (std::vector<int>::const_iterator it = _maxVecS.begin(); it != _maxVecS.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    _timeVec = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process with vector: " << _timeVec << " us" << std::endl;
}

