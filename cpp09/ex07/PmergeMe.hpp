
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
#include <limits>
#include <iterator>
#include <ctime>
#include <set>
#include <vector>
#include <deque>

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
        static bool isSorted(const std::vector<int>& vec);
        static void displayArray(size_t i);
        
        static std::vector<int>::iterator findIt(std::vector<int>& array, int value);
        static size_t findIndex(std::vector<int>& array, int value);
        std::vector<std::pair<int, int> > createPairsVec(const std::vector<int>& array);
        std::vector<int> VecExtractMinX(const std::vector<std::pair<int, int> >& pairs);
        std::vector<size_t> VecGenerateJacobsthal(size_t maxIndex);
        std::vector<int> fordJohnsonVecSort(std::vector<int> inputMax);
        void PmergeMeVector();

        static std::deque<int>::iterator findIt(std::deque<int>& array, int value);
        static size_t findIndex(std::deque<int>& array, int value);
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