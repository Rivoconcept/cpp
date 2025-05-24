/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:33:19 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/24 16:55:42 by rhanitra         ###   ########.fr       */
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
        // Test 1: ShrubberyCreationForm
        form = intern.makeForm("shrubbery creation", "Garden");
        std::cout << *form << std::endl;
        delete form;
    } catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        // Test 2: RobotomyRequestForm
        form = intern.makeForm("robotomy request", "Bender");
        std::cout << *form << std::endl;
        delete form;
    } catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        // Test 3: PresidentialPardonForm
        form = intern.makeForm("presidential pardon", "Alice");
        std::cout << *form << std::endl;
        delete form;
    } catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try 
    {
        form = intern.makeForm("invalid form", "Nobody");
        if (!form)
            throw std::runtime_error("Form creation returned NULL.");
        std::cout << *form << std::endl;
        delete form;
    } 
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

