
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
#include <ctime>
#include <vector>
#include <deque>
#include <map>


class PmergeMe
{
    private:
    
        double              _timeVec;
        std::vector<int>    _inputVec;
        
        double              _timeDeq;
        std::deque<int>     _inputDeq;

        static bool isNumeric(const std::string &str);
        static void findDuplicates(std::vector<int>& input);
        static bool isSorted(const std::vector<int>& vec, const std::vector<int> initVec);
        static void displayArray(size_t i);
        
        std::vector<size_t> VecGenerateJacobsthal(size_t maxIndex);
        std::vector<int> PmergeMeVector(std::vector<int> input);

        std::deque<size_t> DeqGenerateJacobsthal(size_t maxIndex);
        std::deque<int> PmergeMeDeque(std::deque<int> input);
 
    public:
        PmergeMe(const std::string& args);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void mergeInsertSort();
};

#endif