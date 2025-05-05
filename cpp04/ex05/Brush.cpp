#include "Brush.hpp"

ABrush::ABrush(const std::string& type) : _type(type)
{
    std::cout << "ABrush: Constructor called" << std::endl;
}

ABrush::ABrush(const ABrush& brush)
{
    std::cout << "ABrush: Copy constructor called" << std::endl;
}

ABrush& ABrush::operator=(const ABrush& brush)
{
    if (this != &brush)
    {
        this->_type = brush._type;
    }
    return (*this);
}

ABrush::~ABrush()
{
    std::cout << "ABrush: Destructor called" << std::endl;
}

const std::string& ABrush::getType() const
{
    return (this->_type);
}