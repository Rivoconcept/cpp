
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <exception>
#include <algorithm>
#include <utility>
#include <sys/time.h>
# include <string>
#include <sstream>
#include <climits>
#include <limits>
#include <iterator>
#include <ctime>
#include <set>
#include <vector>
#include <deque>
#include <map>


class PmergeMe
{
    private:
    
        int                 _single;
        int                 _sizeTab;

        double              _timeVec;
        std::vector<int>    _inputVec;
        std::vector<int>    _sortedVec;
        
        double              _timeDeq;
        std::deque<int>     _inputDeq;
        std::deque<int>     _sortedDeq;

        static bool isNumeric(const std::string &str);
        static void findDuplicates(std::vector<int>& input);
        static bool isSorted(const std::vector<int>& vec, const std::vector<int> initVec);
        static void displayArray(size_t i);
        
        std::vector<size_t> VecGenerateJacobsthal(size_t maxIndex);
        std::vector<size_t> VecgenerateJacobsthalGroup(size_t maxIndex);
        std::vector<int> fordJohnsonVecSort(std::vector<int> inputMaxX);
        void PmergeMeVector();

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