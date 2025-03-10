#include "test.hpp"

void byPtr(std::string *str)
{
    *str += " and ponies";
}

void byConstPtr(std::string const *str)
{
    std::cout << *str << std::endl;
}

void byRef(std::string& str)
{
    str += " and ponies";
}

void byConstRef(std::string const& str)
{
    std::cout << str << std::endl;
}

int main ()
{
    std::string str = "I like butterflies";
    std::cout << str << std::endl;
    byPtr(&str);
    byConstPtr(&str);
    std::cout << str << std::endl;
    str = "I like others";
    byRef(str);
    byConstRef(str);
    std::cout << str << std::endl;
    return (0);
}
