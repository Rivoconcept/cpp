#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() : _targetBook(0), _countTargetBook(0) {}

TargetGenerator::~TargetGenerator()
{    
    for (int i = 0; i < _countTargetBook; i++)
        delete _targetBook[i];

    delete[] _targetBook;
}

void TargetGenerator::learnTargetType(ATarget* target)
{
    if (!target)
        return;

    for (int i = 0; i < _countTargetBook; i++)
    {
        if (_targetBook[i] && _targetBook[i]->getType() == target->getType())
            return ;
    }
    
    ATarget** NewTargetBook = new ATarget*[_countTargetBook + 1];

    for (int i = 0; i < _countTargetBook; i++)
    {
        NewTargetBook[i] = _targetBook[i];
    }
    NewTargetBook[_countTargetBook] = target->clone();
    delete[] _targetBook;
    _targetBook = NewTargetBook;
    ++_countTargetBook;
}

void TargetGenerator::forgetTargetType(std::string const & targetType)
{
    for (int i = 0; i < _countTargetBook; ++i) 
    {
        if (_targetBook[i] && _targetBook[i]->getType() == targetType) 
        {
            delete _targetBook[i];
            
            for (int j = i; j < _countTargetBook - 1; ++j)
                _targetBook[j] = _targetBook[j + 1];
            
            _targetBook[_countTargetBook - 1] = NULL;
            --_countTargetBook;
            break;
        }
    }
}

ATarget* TargetGenerator::createTarget(std::string const & targetType)
{
    if (targetType.empty() || _countTargetBook == 0)
        return NULL;

    ATarget* prototype = NULL;

    for (int i = 0; i < _countTargetBook; ++i) 
    {
        if (_targetBook[i] && _targetBook[i]->getType() == targetType) 
        {
            prototype = _targetBook[i];
            break;
        }
    }

    if (!prototype)
        return NULL;

    try
    {
        ATarget* newTarget = prototype->clone();
        if (!newTarget)
        {
            throw std::runtime_error("Clone failed for target: " + targetType);
        }
        return newTarget;
    } 
    catch (...)
    {

        return NULL;
    }
}