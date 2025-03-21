#include "test.hpp"

/*Rectangle::Rectangle() {}

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
}*/


typedef enum {
    DEBUG,
    INFO,
    WARNING,
    ERROR
} Message;

const char *message_strings[] = {
    [DEBUG] = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!",
    [INFO] = "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!",
    [WARNING] = "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.",
    [ERROR] = "This is unacceptable! I want to speak to the manager now.",
};

int main() {
    Message msg = INFO;
    std::cout << "msg: " << message_strings[msg] << std::endl;
    return 0;
}
