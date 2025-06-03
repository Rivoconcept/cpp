#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ASpell
{
    protected:
        std::string name;
        std::string effects;

    public:
        ASpell(const std::string& nom, const std::string& effects);
        ASpell(const ASpell& other);
        ASpell& operator=(const ASpell& other);
        virtual ~ASpell();

        const std::string& getName() const;
        const std::string& getEffects() const;

        virtual ASpell* clone() const = 0;

        void launch(const ATarget& target) const;
     
};

#endif