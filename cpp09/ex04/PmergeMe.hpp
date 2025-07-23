/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:06:39 by rhanitra          #+#    #+#             */
/*   Updated: 2025/07/22 18:06:45 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <exception>
#include <algorithm>
#include <utility>
# include <string>
#include <sstream>
#include <limits>
#include <ctime>
#include <vector>
#include <deque>
#include <set>

struct ComparePairs
{
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const
    {
        return (a.first < b.first);
    }
};

class PmergeMe
{
    private:
    
        int                 _single;

        double              _timeVec;
        std::vector<int>    _inputVec;
        std::vector<int>    _sortedVec;
        
        double              _timeDeq;
        std::deque<int>     _inputDeq;
        std::deque<int>     _sortedDeq;

        static bool isNumeric(const std::string &str);
        static void findDuplicates(std::vector<int>& input);
        static void displayArray(size_t i);

        std::vector<std::pair<int, int> > createPairsVec(const std::vector<int>& array);
        std::vector<int> VecExtractMinX(const std::vector<std::pair<int, int> >& pairs);
        std::vector<size_t> VecGenerateJacobsthal(size_t maxIndex);
        std::vector<int> fordJohnsonVecSort(std::vector<int> inputMax);
        void PmergeMeVector();

        std::deque<std::pair<int, int> > createPairsDeq(const std::deque<int>& array);
        std::deque<int> DeqExtractMinX(const std::deque<std::pair<int, int> >& pairs);
        std::deque<size_t> DeqGenerateJacobsthal(size_t maxIndex);
        std::deque<int> fordJohnsonDeqSort(std::deque<int> inputMax);
        void PmergeMeDeque();

    public:
        PmergeMe(const std::string& args);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void mergeInsertSort();

};

#endif