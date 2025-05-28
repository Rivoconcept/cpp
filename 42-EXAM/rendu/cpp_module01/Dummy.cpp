#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}

Dummy::Dummy(const Dummy& other) : ATarget(other) {}

Dummy& Dummy::operator=(const Dummy& other)
{
    if (this != &other)
    {
        ATarget::operator=(other);
    }
    return (*this);
}

Dummy::~Dummy() {}

ATarget* Dummy::clone() const
{
    return (new Dummy(*this));
}

