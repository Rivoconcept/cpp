#include "test.hpp"

double Rectangle::surface() const
{
    return (width * height);
}

double Rectangle::getwidth() const
{
    return (width);
}

double Rectangle::getheight() const
{
    return (height);
} 

void Rectangle::setwidth(double weight)
{  
    this->width = weight;
}

void Rectangle::setheight(double height)
{
    this->height = height;
}

int main ()
{
    Rectangle Rect;
    Rect.setwidth(10.0);
    Rect.setheight(20.0);
    std::cout << "Surface: " << Rect.surface() << std::endl;
    return (0);
}