#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"

class SpellBook
{
    private:
        ASpell** _spellBook;
        int _countSpellBook;

        SpellBook(const SpellBook&);
        SpellBook& operator=(const SpellBook&); 

    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell*);
        void forgetSpell(std::string const &);
        ASpell* createSpell(std::string const &);
};

#endif