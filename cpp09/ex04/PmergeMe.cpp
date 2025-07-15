
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::string& args)
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
        _inputVector.push_back(final);
        _inputDeque.push_back(final);
    }

    findDuplicates(_inputVector);
}
    
PmergeMe::~PmergeMe() {};

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
        throw std::runtime_error("Empty file!!!!");
        
    int found = 0;
    std::vector<int>::iterator it = input.begin();
    
    while (it != input.end())
    {
        found = 0;
        for (std::vector<int>::iterator itFind = input.begin(); itFind != input.end(); itFind++)
        {
            if (*it == *itFind)
                found++;
        }
        if (found > 1)
        {
            std::ostringstream oss;
            oss << "The file has duplicates: " << *it;
            throw std::runtime_error(oss.str());
        }
        ++it;
    }
}

void PmergeMe::createPairsVector()
{
    _mainChainVector.clear();
    _pendingChainVector.clear();

    for (size_t i = 0; i < _inputVector.size(); i += 2)
    {
        if (i + 1 < _inputVector.size())
        {
            // Former une paire
            int first = _inputVector[i];
            int second = _inputVector[i + 1];
            // Placer le plus grand dans main chain, le plus petit dans pending chain
            if (first > second)
            {
                _mainChainVector.push_back(first);
                _pendingChainVector.push_back(second);
            } else
            {
                _mainChainVector.push_back(second);
                _pendingChainVector.push_back(first);
            }
        } else
        {
            // Si impair, dernier élément va dans pending chain
            _pendingChainVector.push_back(_inputVector[i]);
        }
    }
}

void PmergeMe::createPairsDeque()
{
    _mainChainDeque.clear();
    _pendingChainDeque.clear();

    for (size_t i = 0; i < _inputDeque.size(); i += 2)
    {
        if (i + 1 < _inputDeque.size())
        {
            int first = _inputDeque[i];
            int second = _inputDeque[i + 1];
            if (first > second)
            {
                _mainChainDeque.push_back(first);
                _pendingChainDeque.push_back(second);
            } else
            {
                _mainChainDeque.push_back(second);
                _pendingChainDeque.push_back(first);
            }
        } else
        {
            _pendingChainDeque.push_back(_inputDeque[i]);
        }
    }
}

void PmergeMe::mergeInsertSortVector()
{
    if (_mainChainVector.size() <= 1)
        return;

    // Créer des paires à partir de la main chain actuelle
    std::vector<int> newMainChain, newPendingChain;
    for (size_t i = 0; i < _mainChainVector.size(); i += 2)
    {
        if (i + 1 < _mainChainVector.size())
        {
            int first = _mainChainVector[i];
            int second = _mainChainVector[i + 1];
            if (first > second)
            {
                newMainChain.push_back(first);
                newPendingChain.push_back(second);
            } else
            {
                newMainChain.push_back(second);
                newPendingChain.push_back(first);
            }
        } else
        {
            newPendingChain.push_back(_mainChainVector[i]);
        }
    }

    // Remplacer la main chain actuelle par la nouvelle
    _mainChainVector = newMainChain;

    // Appeler récursivement sur la nouvelle main chain
    mergeInsertSortVector();

    // Insérer les éléments de la pending chain récursivement
    for (size_t i = 0; i < newPendingChain.size(); ++i)
    {
        binaryInsertVector(newPendingChain[i], _mainChainVector, _mainChainVector.size());
    }

    // Insérer les éléments de la pending chain initiale avec l'ordre de Jacobsthal
    std::vector<size_t> jacobsthalOrder = generateJacobsthalOrder(_pendingChainVector.size());
    for (size_t i = 0; i < jacobsthalOrder.size() && i < _pendingChainVector.size(); ++i)
    {
        size_t idx = jacobsthalOrder[i];
        binaryInsertVector(_pendingChainVector[idx], _mainChainVector, _mainChainVector.size());
    }
}

void PmergeMe::mergeInsertSortDeque()
{
    if (_mainChainDeque.size() <= 1)
        return;

    std::deque<int> newMainChain, newPendingChain;
    for (size_t i = 0; i < _mainChainDeque.size(); i += 2)
    {
        if (i + 1 < _mainChainDeque.size())
        {
            int first = _mainChainDeque[i];
            int second = _mainChainDeque[i + 1];
            if (first > second)
            {
                newMainChain.push_back(first);
                newPendingChain.push_back(second);
            } else
            {
                newMainChain.push_back(second);
                newPendingChain.push_back(first);
            }
        } else
        {
            newPendingChain.push_back(_mainChainDeque[i]);
        }
    }

    _mainChainDeque = newMainChain;
    mergeInsertSortDeque();

    for (size_t i = 0; i < newPendingChain.size(); ++i)
    {
        binaryInsertDeque(newPendingChain[i], _mainChainDeque, _mainChainDeque.size());
    }

    std::vector<size_t> jacobsthalOrder = generateJacobsthalOrder(_pendingChainDeque.size());
    for (size_t i = 0; i < jacobsthalOrder.size() && i < _pendingChainDeque.size(); ++i)
    {
        size_t idx = jacobsthalOrder[i];
        binaryInsertDeque(_pendingChainDeque[idx], _mainChainDeque, _mainChainDeque.size());
    }
}

void PmergeMe::binaryInsertVector(int element, std::vector<int>& chain, size_t end)
{
    size_t left = 0;
    size_t right = end;

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (chain[mid] < element)
        {
            left = mid + 1;
        } else
        {
            right = mid;
        }
    }

    chain.insert(chain.begin() + left, element);
}

void PmergeMe::binaryInsertDeque(int element, std::deque<int>& chain, size_t end)
{
    size_t left = 0;
    size_t right = end;

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (chain[mid] < element)
        {
            left = mid + 1;
        } else
        {
            right = mid;
        }
    }

    chain.insert(chain.begin() + left, element);
}

std::vector<size_t> PmergeMe::generateJacobsthalOrder(size_t size)
{
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    size_t n = 2;
    while (true)
    {
        size_t next = jacobsthal[n - 1] + 2 * jacobsthal[n - 2];
        if (next >= size)
            break;
        jacobsthal.push_back(next);
        ++n;
    }

    std::vector<size_t> order;
    for (size_t i = 1; i < jacobsthal.size(); ++i)
    {
        size_t current = jacobsthal[i];
        size_t prev = jacobsthal[i - 1];
        order.push_back(current - 1);
        for (size_t j = current - 2; j >= prev && j < size; --j)
        {
            order.push_back(j);
        }
    }

    // Ajouter les indices restants
    for (size_t i = jacobsthal.back(); i < size; ++i)
    {
        order.push_back(i);
    }

    return order;
}

void PmergeMe::run()
{
    // Afficher la séquence non triée
    std::cout << "Before: ";
    for (size_t i = 0; i < _inputVector.size(); ++i)
        std::cout << _inputVector[i] << " ";
    std::cout << "\n";

    // Mesurer le temps pour vector
    clock_t startVector = clock();
    createPairsVector();
    mergeInsertSortVector();
    clock_t endVector = clock();
    double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000; // Microsecondes

    // Afficher la séquence triée
    std::cout << "After: ";
    for (size_t i = 0; i < _mainChainVector.size(); ++i)
        std::cout << _mainChainVector[i] << " ";
    std::cout << "\n";

    // Mesurer le temps pour deque
    clock_t startDeque = clock();
    createPairsDeque();
    mergeInsertSortDeque();
    clock_t endDeque = clock();
    double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000; // Microsecondes

    // Afficher les temps
    std::cout << "Time to process a range of " << _inputVector.size() << " elements with std::vector : " << timeVector << " us\n";
    std::cout << "Time to process a range of " << _inputDeque.size() << " elements with std::deque : " << timeDeque << " us\n";
}