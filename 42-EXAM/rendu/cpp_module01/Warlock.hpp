#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
    private:
        std::string name;
        std::string title;

    public:
        Warlock(const std::string& nom, const std::string& titre);
        ~Warlock();

        const std::string& getName() const;
        const std::string& getTitle() const;
        void setTitle(const std::string& titre);

        void introduce() const;
};
#endif