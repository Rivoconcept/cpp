#include "Dog.hpp"
#include "Human.hpp"

int main(void)
{
    Dog dog("Billy", 5);
    Human human("Tom", 21, dog);

    human.walkDog();
    dog.bark();

    return (0);
}