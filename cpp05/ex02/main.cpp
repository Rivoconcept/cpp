/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:33:19 by rhanitra          #+#    #+#             */
/*   Updated: 2025/05/30 16:52:59 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    {
        try
        {
            std::cout << "\nShrubberyCreationForm Test:\n";
            Bureaucrat john("John", 148);
            ShrubberyCreationForm form("Forest");

            form.beSigned(john);
            form.execute(john);
        }
        catch (std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    {    
        try
        {
            std::cout << "\nRobotomyRequestForm Test:\n";
            Bureaucrat joe("Joe", 40);
            RobotomyRequestForm form("Bender");

            form.beSigned(joe);
            form.execute(joe);

            Bureaucrat Parker("Joe", 80);
            form.execute(Parker);
        }
        catch (std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    {    
        try
        {

            std::cout << "\nPresidentialPardonForm Test:\n";
            Bureaucrat anna("Anna", 3);
            PresidentialPardonForm form("Willy");

            form.beSigned(anna);
            form.execute(anna); 

            Bureaucrat ben("Ben", 30);
            form.execute(ben);
        }
        catch (std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    return 0;
}
