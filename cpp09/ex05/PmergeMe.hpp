
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <exception>
#include <algorithm>
#include <utility>
# include <string>
#include <sstream>
# include <fstream>
#include <limits>
#include <cmath>
#include <stack>
#include <vector>
#include <deque>
#include <ctime>



class PmergeMe
{
    private:
        std::vector<int> _inputVec;
        std::vector<int> _sortedVec;
        std::vector<std::pair<int, int> > _pairsVec;
        int _single;
        double _timeVec;

        static bool isNumeric(const std::string &str);
        static float fromFloat(const std::string& literal);
        static void findDuplicates(std::vector<int>& input);

        void createPairsVec();
        
    public:
        PmergeMe(const std::string& args);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

         void run();
};
    


#endif