
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
# include <string>
#include <sstream>
# include <fstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <stack>
#include <vector>
#include <deque>
#include <chrono>



class PmergeMe
{
    private:

        std::vector<int> _input;
        std::vector<int> _sortedVec;
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

        double getTimeVec() const;
        double getTimeDeq() const;

        void setTimeVec(double time);
        void setTimeDeq(double time);

        const std::vector<int>& getInput() const;
        const std::vector<int>& getSortedVec() const;
        const std::deque<int>& getSortedDeq() const;

        // Tri fusion-insertion pour std::vector
       //  void mergeInsertSortVector(std::vector<int>& arr);
        
        // Tri fusion-insertion pour std::deque (même logique)
        // void mergeInsertSortDeque(std::deque<int>& arr);
        
         void run();
    };
    


#endif