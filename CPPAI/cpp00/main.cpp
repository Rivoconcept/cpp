#include "Dog.hpp"

int main(void)
{
    Dog dog("Billy", 5);

    dog.bark();
    std::cout << "Age via getAge() = " << dog.getAge() << std::endl;
    return (0);
}