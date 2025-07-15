
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
# include <string>
#include <sstream>
# include <fstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <vector>
#include <deque>


class PmergeMe
{
    private:

        std::vector<int> _inputVec;
        std::vector<int> _sortedVec;

        std::vector<int> _inputDeq;
        std::deque<int> _sortedDeq;

        double _timeVec;
        double _timeDeq;

        static bool isNumeric(const std::string &str);
        static float fromFloat(const std::string& literal);
        static void findDuplicates(std::vector<int>& input);
        
        
        
    public:
        PmergeMe(const std::string& args);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();



       //  void mergeInsertSortVector(std::vector<int>& arr);
        

        // void mergeInsertSortDeque(std::deque<int>& arr);
        
         void run();
    };
    


#endif