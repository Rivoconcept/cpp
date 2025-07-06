#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) :  _name(name), _title(title), _countSpells(0)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
    for (int i = 0; i < 4; i++)
    {
        _spells[i] = NULL;
    }
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
    for (int i = 0; i < _countSpells; i++)
    {
        delete _spells[i];
    }
}

const std::string& Warlock::getName() const
{
    return (_name);
}

const std::string& Warlock::getTitle() const
{
    return (_title);
}

void Warlock::setTitle(const std::string& title)
{
    _title = title;
}

 void Warlock::introduce() const
 {
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl; 
 }

void Warlock::learnSpell(ASpell* spell)
{
    if (!spell)
        return;
    
    for (int i = 0 ; i < _countSpells; i++ )
    {
        if (_spells[i] && _spells[i]->getName() == spell->getName())
            return;
    }

    _spells[_countSpells++] = spell->clone();
    
}
void Warlock::forgetSpell(std::string spellName)
{
    for (int i = 0; i < _countSpells; i++)
    {
        if (_spells[i] && _spells[i]->getName() == spellName)
        {
            delete _spells[i];
            {
                for (int j = i; j < _countSpells - 1; j++)
                {
                    _spells[j] = _spells[j + 1];
                }
            }
            _spells[--_countSpells] = NULL;
            return;
        }
    }
}
void Warlock::launchSpell(std::string spellName, const ATarget& target)
{
    for (int i = 0; i < _countSpells; i++)
    {
        if (_spells[i] && _spells[i]->getName() == spellName)
        {
            _spells[i]->launch(target);
            return ;
        }
    }
}