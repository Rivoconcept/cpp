
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
        std::vector<int> _pending;
        std::vector<int> _vecX;
        std::vector<int> _maxVecS;
        std::vector<std::pair<int, int> > _pairVecX;
        std::vector<std::pair<int, int> > _pairVecS;
        /*std::vector<std::vector<int> > _groups;
        std::vector<int> _unpaired;*/
        int _single;
        double _timeVec;

        static bool isNumeric(const std::string &str);
        static float fromFloat(const std::string& literal);
        static void findDuplicates(std::vector<int>& input);

        std::vector<std::pair<int, int> > createPairsVec(const std::vector<int>& array);
        void extractMaxVec();
        std::vector<size_t> generateJacobsthal(size_t n);
        void mergeInsertSort(std::vector<int>& vec);

    public:
        PmergeMe(const std::string& args);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        const std::vector<int>& getSortedVec() const;


         void run();
};
    
struct ComparePairs
{
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const
    {
        return (a.first < b.first);
    }
};

struct CompareGroups
{
    bool operator()(const std::vector<int>& a, const std::vector<int>& b) const
    {
        int max_a = *std::max_element(a.begin(), a.end());
        int max_b = *std::max_element(b.begin(), b.end());
        return max_a < max_b;
    }
};

#endif