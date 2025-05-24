/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:51:57 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/24 16:49:46 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { *this = other; }

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

Intern::~Intern() {}

AForm* Intern::createShrubbery(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidential(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& form, const std::string& target) const
{
    const std::string names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*functions[])(const std::string&) = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};

    for (int i = 0; i < 3; ++i)
    {
        if (form == names[i])
        {
            std::cout << "Intern creates " << form << std::endl;
            return (functions[i](target));
        }
    }

    std::cerr << "Error: form \"" << form << "\" does not exist." << std::endl;
    return (NULL);
}
