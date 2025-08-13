#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) :  _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;

}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
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
    _speelBook.learnSpell(spell);
}
void Warlock::forgetSpell(const std::string& spellName)
{

    if (spellName.empty)
        _speelBook.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, const ATarget& target)
{
    ASpell* newSpell = _speelBook.createSpell(spellName);
    if (newSpell)
    {
        try {
            newSpell->launch(target);
        } catch (...) {
            delete newSpell;
            throw;
        }
        delete newSpell;
    }
}

// VERSION CORRECTE
/*void Warlock::launchSpell(const std::string& spellName, const ATarget& target)
{
    // 1. Recherche du prototype dans le SpellBook
    ASpell* prototype = NULL;
    for (int i = 0; i < _countSpeelBook; ++i) {
        if (_spellBook[i].name == spellName) {
            prototype = _spellBook[i].spell;
            break;
        }
    }

    if (prototype) {
        // 2. "Créer le sort" en utilisant le prototype, c'est-à-dire le cloner
        ASpell* newSpellInstance = prototype->clone();

        if (newSpellInstance) {
            // 3. Lancer la NOUVELLE instance
            newSpellInstance->launch(target);

            // 4. Détruire l'instance temporaire pour éviter les fuites de mémoire
            delete newSpellInstance;
        }
    }
}*/