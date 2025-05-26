/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:33:19 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/26 18:06:47 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;
    AForm* form;

    try
    {
        form = intern.makeForm("shrubbery creation", "Garden");
        std::cout << *form << std::endl;
        delete form;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        form = intern.makeForm("robotomy request", "Bender");
        std::cout << *form << std::endl;
        delete form;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        form = intern.makeForm("presidential pardon", "Alice");
        std::cout << *form << std::endl;
        delete form;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        form = intern.makeForm("invalid form", "Nobody");
        std::cout << *form << std::endl;
        delete form;
    } 
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}

