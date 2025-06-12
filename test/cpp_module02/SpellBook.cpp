#include "SpellBook.hpp"

SpellBook::SpellBook() : _spellBook(0), _countSpellBook(0) {}

SpellBook::~SpellBook() 
{
    for (int i = 0; i < _countSpellBook; i++)
        delete _spellBook[i];
    delete[] _spellBook;
}

void SpellBook::learnSpell(ASpell* spell)
{
    if (!spell)
        return;
    for (int i = 0; i < _countSpellBook; i++)
    {
        if (_spellBook[i] && _spellBook[i]->getName() == spell->getName())
            return;
    }
    ASpell** NewSpell = new ASpell*[_countSpellBook + 1];

    for (int i = 0; i < _countSpellBook; i++)
    {
        NewSpell[i] = _spellBook[i];
    }
    NewSpell[_countSpellBook] = spell->clone();
    delete[] _spellBook;
    _spellBook = NewSpell;
    ++_countSpellBook;
    delete spell;
}
void SpellBook::forgetSpell(std::string const & spellName)
{
    for (int i = 0; i < _countSpellBook; i++)
    {
        if (_spellBook[i] && _spellBook[i]->getName() == spellName)
        {
            delete _spellBook[i];

            for (int j = i; j < _countSpellBook - 1; j++)
            {
                _spellBook[j] = _spellBook[j + 1];
            }

            _spellBook[_countSpellBook - 1] = NULL;
            --_countSpellBook;
            break;
        }
    }
}

ASpell* SpellBook::createSpell(std::string const & spellName)
{
    if (spellName.empty() || _countSpellBook == 0)
        return NULL;

    ASpell* prototype = NULL;
    
    for (int i = 0; i < _countSpellBook; ++i) 
    {
        if (_spellBook[i] && _spellBook[i]->getName() == spellName) 
        {
            prototype = _spellBook[i];
            break;
        }
    }

    if (!prototype)
        return NULL;

    try
    {
        ASpell* newSpell = prototype->clone();
        if (!newSpell)
            throw std::runtime_error("Clone failed for spell: " + spellName);
        return newSpell;
    } 
    catch (...)
    {
        return NULL;
    }
}