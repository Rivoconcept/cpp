
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::string& args) : _timeVec(0), _timeDeq(0)
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
            throw std::runtime_error("Conversion to float: impossible");
        
        if (input < 0)
            throw std::runtime_error("Error: not a positive number.");
        
        if (input > std::numeric_limits<int>::max())
            throw std::runtime_error("input integer out of range: " + token);
        
        int final = static_cast<int>(input);

        _input.push_back(final);
    }
    
    findDuplicates(_input);
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
   
    {
        _input = other._input;
        _sortedVec = other._sortedVec;
        _sortedDeq = other._sortedDeq;
        _timeVec = other._timeVec;
        _timeDeq = other._timeDeq;
    }
    return (*this);
    
}

PmergeMe::~PmergeMe()
{};

void PmergeMe::setTimeVec(double time)
{
    _timeVec = time;
}

void PmergeMe::setTimeDeq(double time)
{
    _timeDeq = time;
}

double PmergeMe::getTimeVec() const
{
    return _timeVec;
}

double PmergeMe::getTimeDeq() const
{
    return _timeDeq;
}

const std::vector<int>& PmergeMe::getInput() const
{
    return (_input);
}

const std::vector<int>& PmergeMe::getSortedVec() const
{
    return (_sortedVec);
}

const std::deque<int>& PmergeMe::getSortedDeq() const
{
    return (_sortedDeq);
}

bool PmergeMe::isNumeric(const std::string &str)
{
    std::istringstream iss(str);
    float f;
    
    iss >> std::noskipws >> f;
    
    return (iss.eof() && !iss.fail());
}

void PmergeMe::findDuplicates(std::vector<int>& input)
{
    if (input.empty())
        throw std::runtime_error("Empty input");

    std::vector<int> sorted = input;

    for (size_t i = 0; i < sorted.size(); ++i)
   
    {
        for (size_t j = 0; j < sorted.size() - i - 1; ++j)
        {
            if (sorted[j] > sorted[j + 1])
           
            {
                std::swap(sorted[j], sorted[j + 1]);
            }
        }
    }

    for (size_t i = 0; i < sorted.size() - 1; ++i)
    {
        if (sorted[i] == sorted[i + 1])
       
        {
            std::ostringstream oss;
            oss << "Duplicate found: " << sorted[i];
            throw std::runtime_error(oss.str());
        }
    }
}

std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n)
{
    std::vector<size_t> sequence;
    if (n >= 1) sequence.push_back(0);
    if (n >= 2) sequence.push_back(1);
    
    size_t j = 1;
    while (sequence.size() < n)
    {
        size_t next = j * 2 + sequence[sequence.size() - 2];
        sequence.push_back(next);
        j = next;
    }
    
    while (sequence.size() > n)
    {
        sequence.pop_back();
    }
    
    return sequence;
}

void PmergeMe::insertionSort(std::vector<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& array) {
    const int threshold = 16;
    
    if (array.size() <= threshold) {
        insertionSort(array, 0, array.size() - 1);
        return;
    }
    
    int mid = array.size() / 2;
    std::vector<int> left(array.begin(), array.begin() + mid);
    std::vector<int> right(array.begin() + mid, array.end());
    
    mergeInsertSortVector(left);
    mergeInsertSortVector(right);
    
    std::merge(left.begin(), left.end(), 
                right.begin(), right.end(), 
                array.begin());
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& array) {
    const int threshold = 16;
    
    if (array.size() <= threshold) {
        for (size_t i = 1; i < array.size(); ++i) {
            int key = array[i];
            int j = i - 1;
            
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                --j;
            }
            array[j + 1] = key;
        }
        return;
    }
    
    int mid = array.size() / 2;
    std::deque<int> left(array.begin(), array.begin() + mid);
    std::deque<int> right(array.begin() + mid, array.end());
    
    mergeInsertSortDeque(left);
    mergeInsertSortDeque(right);
    
    std::merge(left.begin(), left.end(), 
                right.begin(), right.end(), 
                array.begin());
}

void PmergeMe::run()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _input.size(); ++i)
        std::cout << _input[i] << " ";
    std::cout << "\n";

    clock_t start = clock();
    _sortedVec = _input;
    mergeInsertSortVector(_sortedVec);
    _timeVec = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1e6;

    start = clock();
    _sortedDeq = std::deque<int>(_input.begin(), _input.end());
    mergeInsertSortDeque(_sortedDeq);
    _timeDeq = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1e6;

    std::cout << "After:  ";
    for (size_t i = 0; i < _sortedVec.size(); ++i)
        std::cout << _sortedVec[i] << " ";
    std::cout << "\n";

    std::cout << "Time to process a range of " << _input.size() 
                << " elements with std::vector: " << std::fixed << std::setprecision(5) 
                << _timeVec << " us\n";
    std::cout << "Time to process a range of " << _input.size() 
                << " elements with std::deque:  " << std::fixed << std::setprecision(5) 
                << _timeDeq << " us\n";
}