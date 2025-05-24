/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:51:57 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/24 13:06:11 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { *this = other; }

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& form, const std::string& target) const
{
    std::string formNames[3] =
    {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[3])(const std::string&) = {
        [](const std::string& target) { return new ShrubberyCreationForm(target); },
        [](const std::string& target) { return new RobotomyRequestForm(target); },
        [](const std::string& target) { return new PresidentialPardonForm(target); }
    };

    for (int i = 0; i < 3; ++i)
    {
        if (form == formNames[i])
        {
            std::cout << "Intern creates " << form << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Error: form \"" << form << "\" does not exist." << std::endl;
    return NULL;
}
