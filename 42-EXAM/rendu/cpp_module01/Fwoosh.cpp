#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "Fwooshed") {}

Fwoosh::Fwoosh(const Fwoosh& other) : ASpell(other) {}

Fwoosh& Fwoosh::operator=(const Fwoosh& other)
{
    if (this != &other)
    {
        ASpell::operator=(other);
    }
    return (*this);
}

Fwoosh::~Fwoosh() {}

ASpell* Fwoosh::clone() const
{
    return (new Fwoosh(*this));
}
