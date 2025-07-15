
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
#include <ctime>

class PmergeMe
{
    private:
        
        std::vector<int> _inputVector; // Conteneur vector pour l'entrée
        std::vector<int> _mainChainVector; // Main chain pour vector
        std::vector<int> _pendingChainVector; // Pending chain pour vector
        
        std::deque<int> _inputDeque;   // Conteneur deque pour l'entrée
        std::deque<int> _mainChainDeque; // Main chain pour deque
        std::deque<int> _pendingChainDeque; // Pending chain pour deque

        static bool isNumeric(const std::string &str);
        static void findDuplicates(std::vector<int>& input);

        // Méthodes pour l'algorithme Ford-Johnson avec vector
        void createPairsVector();
        void mergeInsertSortVector();
        void binaryInsertVector(int element, std::vector<int>& chain, size_t end);

        // Méthodes pour l'algorithme Ford-Johnson avec deque
        void createPairsDeque();
        void mergeInsertSortDeque();
        void binaryInsertDeque(int element, std::deque<int>& chain, size_t end);

        // Générer les indices de Jacobsthal pour l'ordre d'insertion
        std::vector<size_t> generateJacobsthalOrder(size_t size);

    public:
        PmergeMe(const std::string& args);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void run();
};
    

#endif