#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        ASpell* _spells[4];
        int _countSpells;


    public:
        Warlock(const std::string& name, const std::string& title);
        ~Warlock();

        const std::string& getTitle() const;
        const std::string& getName() const;
        void setTitle(const std::string& title);

        void introduce() const;

        void learnSpell(ASpell* spell);
        void forgetSpell(std::string spellName);
        void launchSpell(std::string spellName, const ATarget& target);

};

#endif