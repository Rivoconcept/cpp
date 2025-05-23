#ifndef PPFORM_H
#define PPFORM_H

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        const std::string& getTarget() const;

        void execute(const Bureaucrat& executor) const;
};
 

#endif