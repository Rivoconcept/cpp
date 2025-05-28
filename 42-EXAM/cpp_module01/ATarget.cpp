#include "ATarget.hpp"

ATarget::ATarget(const std::string& type) : _type(type) {}

ATarget::ATarget(const ATarget& other) : _type(other._type) {}

ATarget& ATarget::operator=(const ATarget& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

const std::string& ATarget::getType() const
{
    return (this->_type);
}

ATarget::~ATarget() {}


void ATarget::getHitBySpell(const ASpell& speel) const
{
    std::cout << this->_type << " has been " << speel.getEffects() << "!" << std::endl;
}