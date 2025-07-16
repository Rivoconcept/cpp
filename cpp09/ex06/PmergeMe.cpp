/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:56:06 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/16 19:22:05 by rhanitra         ###   ########.fr       */
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
        _sortedVec = other._sortedVec;
        _timeVec = other._timeVec;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {};

const std::vector<int>& PmergeMe::getSortedVec() const
{
    return (_sortedVec);
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

void PmergeMe::createPairsVec()
{
    _pairsVec.clear();

    for (size_t i = 0; i + 1 < _inputVec.size(); i += 2)
    {
        int first = _inputVec[i];
        int second = _inputVec[i + 1];
        
        if (first < second)
            std::swap(first, second);
        
        _pairsVec.push_back(std::make_pair(first, second));
    }

    std::cout << "Creacte pairs: ";
    for (size_t i = 0; i < _pairsVec.size(); ++i)
    {
        std::cout << "(" << _pairsVec[i].first << ", " << _pairsVec[i].second << ")" << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::sortPairsVec()
{

    std::sort(_pairsVec.begin(), _pairsVec.end(), ComparePairs());

 
    std::cout << "Sorted pairs: ";
    for (std::vector<std::pair<int, int> >::const_iterator it = _pairsVec.begin(); it != _pairsVec.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
}

void PmergeMe::createMainSeqVec()
{

    _sortedVec.clear();


    for (std::vector<std::pair<int, int> >::const_iterator it = _pairsVec.begin(); it != _pairsVec.end(); ++it) {
        _sortedVec.push_back(it->first);
    }

    std::cout << "Main sequence: ";
    for (std::vector<int>::const_iterator it = _sortedVec.begin(); it != _sortedVec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::createPendingVec()
{

    std::vector<int> pending;

    for (std::vector<std::pair<int, int> >::const_iterator it = _pairsVec.begin(); it != _pairsVec.end(); ++it)
    {
        pending.push_back(it->second);
    }

    if (_single != -1)
    {
        pending.push_back(_single);
    }

    std::cout << "Pending elements: ";
    for (std::vector<int>::const_iterator it = pending.begin(); it != pending.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/*void PmergeMe::createMainSeqVec()
{
    _sortedVec.clear();

    // Ajouter b_1 (pair.second de la première paire) si _pairsVec n'est pas vide
    if (!_pairsVec.empty()) {
        _sortedVec.push_back(_pairsVec[0].second); // b_1
    }

    // Ajouter tous les a_i (pair.first)
    for (std::vector<std::pair<int, int> >::const_iterator it = _pairsVec.begin(); it != _pairsVec.end(); ++it) {
        _sortedVec.push_back(it->first); // a_i
    }

    // Afficher la séquence principale
    std::cout << "Main sequence: ";
    for (std::vector<int>::const_iterator it = _sortedVec.begin(); it != _sortedVec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::createPendingVec()
{
    std::vector<int> pending;

    // Ajouter les b_i à partir de b_2 (ignorer b_1)
    for (std::vector<std::pair<int, int> >::const_iterator it = _pairsVec.begin() + 1; it != _pairsVec.end(); ++it)
    {
        pending.push_back(it->second);
    }

    // Ajouter les éléments non appariés
    for (std::vector<int>::const_iterator it = _unpaired.begin(); it != _unpaired.end(); ++it)
    {
        pending.push_back(*it);
    }

    // Afficher les éléments pending
    std::cout << "Pending elements: ";
    for (std::vector<int>::const_iterator it = pending.begin(); it != pending.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Stocker pending dans un membre temporaire pour l'insertion
    _pending = pending; // Note : _pending doit être ajouté à PmergeMe.hpp
}*/


void PmergeMe::run()
{
    for (std::vector<int>::iterator it = _inputVec.begin(); it != _inputVec.end(); ++it)
    {
        std::cout << *it <<  " ";
    }
    std::cout << std::endl;
    createPairsVec();

    sortPairsVec();
    createMainSeqVec();
    createPendingVec();
    // run(_sortedVec);
}


/*void PmergeMe::mergeInsertSortVector(std::vector<int>& arr)
{
    if (arr.size() <= 1) return;

    // Étape 1 : Création des paires
    std::vector<int> bigs, smalls;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (i + 1 < arr.size()) {
            if (arr[i] > arr[i + 1]) {
                bigs.push_back(arr[i]);
                smalls.push_back(arr[i + 1]);
            } else {
                bigs.push_back(arr[i + 1]);
                smalls.push_back(arr[i]);
            }
        } else {
            smalls.push_back(arr[i]);
        }
    }

    // Étape 2 : Tri récursif des grands éléments
    mergeInsertSortVector(bigs);

    // Étape 3 : Fusion avec les petits éléments (ordre Jacobsthal simplifié)
    _sortedVec = bigs;
    _sortedVec.insert(_sortedVec.begin(), smalls[0]); // Premier élément

    for (size_t i = 1; i < smalls.size(); ++i)
    {
        auto it = std::lower_bound(_sortedVec.begin(), _sortedVec.end(), smalls[i]);
        _sortedVec.insert(it, smalls[i]);
    }
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr)
{
    if (arr.size() <= 1) return;

    std::deque<int> bigs, smalls;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (i + 1 < arr.size())
        {
            if (arr[i] > arr[i + 1])
            {
                bigs.push_back(arr[i]);
                smalls.push_back(arr[i + 1]);
            } 
            else
            {
                bigs.push_back(arr[i + 1]);
                smalls.push_back(arr[i]);
            }
        }
        else
        {
            smalls.push_back(arr[i]);
        }
    }

    mergeInsertSortDeque(bigs);

    _sortedDeq = bigs;
    _sortedDeq.insert(_sortedDeq.begin(), smalls[0]);

    for (size_t i = 1; i < smalls.size(); ++i) {
        auto it = std::lower_bound(_sortedDeq.begin(), _sortedDeq.end(), smalls[i]);
        _sortedDeq.insert(it, smalls[i]);
    }
}*/

/*void PmergeMe::run() {
    // Afficher la séquence avant tri
    std::cout << "Before: ";
    for (int num : _input) std::cout << num << " ";
    std::cout << "\n";

    // Tri avec std::vector
    {
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> vecCopy = _input;
        mergeInsertSortVector(vecCopy);
        auto end = std::chrono::high_resolution_clock::now();
        _timeVec = std::chrono::duration<double, std::micro>(end - start).count();
    }

    // Tri avec std::deque
    {
        auto start = std::chrono::high_resolution_clock::now();
        std::deque<int> deqCopy(_input.begin(), _input.end());
        mergeInsertSortDeque(deqCopy);
        auto end = std::chrono::high_resolution_clock::now();
        _timeDeq = std::chrono::duration<double, std::micro>(end - start).count();
    }

    // Afficher les résultats
    std::cout << "After:  ";
    for (int num : _sortedVec) std::cout << num << " ";
    std::cout << "\n";

    std::cout << "Time to process a range of " << _input.size() 
                << " elements with std::vector: " << std::fixed << std::setprecision(5) 
                << _timeVec << " us\n";

    std::cout << "Time to process a range of " << _input.size() 
                << " elements with std::deque:  " << std::fixed << std::setprecision(5) 
                << _timeDeq << " us\n";
}*/
