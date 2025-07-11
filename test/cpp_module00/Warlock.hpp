#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
    private:
        std::string _name;
        std::string _title;


    public:
        Warlock(const std::string& name, const std::string& title);
        ~Warlock();

        const std::string& getTitle() const;
        const std::string& getName() const;
        void setTitle(const std::string& title);

        void introduce() const;


};

#endif